#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4444
#define BUFFER_SIZE 2048

int main() {
 
    int server;
    int client;

    struct sockaddr_in server_address; 

    client = socket(AF_INET, SOCK_STREAM, 0); 
    if (client < 0) {
        printf("Server: Creating socket error: \n");
        return -1;
    }
    printf("Socket was successfully created \n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    int ret = bind(client, (struct sockaddr * ) & server_address, sizeof(server_address));

    if (ret < 0) {
        printf("Server: Binding connection error \n");
        return -1;
    }

    socklen_t size = sizeof(server_address);
    printf("Listening client \n");

    listen(client, 1); 

    server = accept(client, NULL, NULL); 

    if (server < 0) {
        printf("Server: Can't accepting client \n");
        return -1;
    }

    char buffer[BUFFER_SIZE];

    strcpy(buffer, "Server connected");

    send(server, buffer, BUFFER_SIZE, 0);
    printf("Connected to the client. Enter \"q\" to end the connection \n\n");

    while (true) {

        printf("Client: ");
        recv(server, buffer, BUFFER_SIZE, 0);
        printf("%s\n\n", buffer);

        if (buffer[0] == 'q'){
            break;
        }

        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin); 

        size_t last = strlen(buffer) - 1;
        if (buffer[last] == '\n') {
            buffer[last] = '\0';
        }

        send(server, buffer, BUFFER_SIZE, 0); 

        if (buffer[0] == 'q'){
            break;
        }
    }
 
    close(client);

    return 0;
}
