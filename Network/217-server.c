#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrLen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr*)&address, sizeof(address));

    listen(server_socket, 3);

    printf("Server listening on port %d...\n", PORT);

    while(1) {
        new_socket = accept(server_socket, (struct sockaddr*)&address,
        (socklen_t*)&addrLen);

        printf("Conection accepted\n");

        read(new_socket, buffer, BUFFER_SIZE);
        printf("File requsted by client %s\n", buffer);
        

        FILE* file = fopen(buffer, "r");
        if(file == NULL) {
            perror("file opening failed");
            exit(EXIT_FAILURE);
        }
        
        

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        char file_content[file_size + 1];
        fread(file_content, 1, file_size, file);
        file_content[file_size] = '\0';

        send(new_socket, file_content, strlen(file_content), 0);

        snprintf(buffer, BUFFER_SIZE, "File size: %ld bytes, Number of characters: %ld\n", file_size, strlen(file_content));

        send(new_socket, buffer, strlen(buffer), 0);

        fclose(file);
        close(new_socket);
    }
    return 0;
}
