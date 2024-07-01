#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int isPolindrom(const char* str) {

    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            return 0;
            }
    }
    return 1;
}

int main() {

    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creating failed");
        exit(EXIT_FAILURE);
        }

        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(PORT);

        inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

        connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

        int n;

        n = recv(sockfd, buffer, MAXLINE, 0); 
        buffer[n] = '\0';

        printf("Longest word received from server: %s\n", buffer);

        if(isPolindrom(buffer)) {
            printf("The longest word is polindrom.\n");
        } else {
            printf("The longest word is not polindrom.\n");
            }
        close(sockfd);
}
