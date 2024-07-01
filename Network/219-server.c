#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

char* find_longest_word(const char* content) {
    char* longest_word = NULL;
    char* word = strtok((char*)content, " ");
    
    while (word != NULL) {
        if (longest_word == NULL || strlen(word) > strlen(longest_word)) {
            longest_word = word;
        }
        word = strtok(NULL, " ");
    }
    
    return longest_word;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAXLINE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    
    // Read file content
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* file_content = malloc(file_size + 1);
    fread(file_content, 1, file_size, file);
    fclose(file);
    file_content[file_size] = '\0';
    
    // Find the longest word in the file content
    char* longest_word = find_longest_word(file_content);
    
    // Send longest word to client
    send(new_socket , longest_word , strlen(longest_word) , 0 );
    printf("Longest word sent to client: %s\n", longest_word);
    
    free(file_content);
    close(new_socket);
    close(server_fd);
    return 0;
}

