#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 5050
#define BUFFER_SIZE 1024

int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = bind(sockfd, addr, addrlen);
    if (res == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void Listen(int sockfd, int backlog) {
    int res = listen(sockfd, backlog);
    if (res == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

int main() {
	
	int server = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in adr = {0};

	adr.sin_family = AF_INET;
   	adr.sin_port = htons(PORT);

		Bind(server, (struct sockaddr *) &adr, sizeof adr);

	Listen(server, 1);
	socklen_t adrlen = sizeof adr;

	   	int client = Accept(server, (struct sockaddr *) &adr, &adrlen);

		char buffer[BUFFER_SIZE];

	strcpy(buffer, "Server connected");

	send(client, buffer, BUFFER_SIZE, 0);
    	printf("Connected to the client. Enter \"q\" to end the connection \n\n");
	  while (1) {

        printf("Client: ");
        recv(client, buffer, BUFFER_SIZE, 0);
        printf("%s\n\n", buffer);

         if (buffer[0] == 'q'){
		break;
	}

               printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);

               size_t last = strlen(buffer) - 1;
        if (buffer[last] == '\n') {buffer[last] = '\0';}

              send(client, buffer, BUFFER_SIZE, 0);

                if (buffer[0] == 'q'){break;}
    }

    close(client);
    close(server);
	return 0;
