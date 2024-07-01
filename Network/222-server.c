#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PORT 12345
#define FILENAME "base.atl"
#define CHUNK_SIZE 256
typedef struct {
    size_t size;
    uint32_t owner_id;
    uint32_t parent_id;
    uint8_t i_state;
    uint8_t i_type;
    uint8_t i_status;
    char i_name[CHUNK_SIZE];
    char i_path[CHUNK_SIZE];
} Inode;

typedef struct {
    size_t size;
    char i_name[256];
    uint8_t i_status;
    uint8_t i_type;
} Open;


int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    int open_count = 0;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is running. Waiting for connections...\n");

    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Receive command from client
        char command[256];
        ssize_t bytes_received = recv(client_socket, command, sizeof(command), 0);
        if (bytes_received <= 0) {
            perror("Error receiving command from client");
            close(client_socket);
            continue;
        }

        command[bytes_received] = '\0';

        if (strcmp(command, "open") == 0) {
            // Open file base.atl
            int fd = open(FILENAME, O_RDONLY);
            if (fd == -1) {
                perror("Error opening file");
                close(client_socket);
                continue;
            }

            // Read Inode structure from file
            Inode inode;
            ssize_t bytes_read = read(fd, &inode, sizeof(Inode));
            if (bytes_read != sizeof(Inode)) {
                perror("Error reading from file");
                close(fd);
                close(client_socket);
                continue;
            }

            // Convert Inode to Open structure
            Open open;
            open.size = inode.size;
            strncpy(open.i_name, inode.i_name, sizeof(open.i_name));
            open.i_name[sizeof(open.i_name) - 1] = '\0';
            open.i_status = inode.i_status;
            open.i_type = inode.i_type;

            // Send Open structure to client
            if (send(client_socket, &open, sizeof(Open), 0) != sizeof(Open)) {
                perror("Error sending data to client");
            }

            // Increment open count
            open_count++;

            // Close file
            close(fd);
        }

        // Send open count to client
        if (send(client_socket, &open_count, sizeof(open_count), 0) != sizeof(open_count)) {
            perror("Error sending data to client");
        }

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

