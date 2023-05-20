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
#define IP_ADDR "127.0.0.1" 

int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if (res == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *src, void *dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        printf("inet_pton failed: src does not contain a character"
            " string representing a valid network address in the specified"
            " address family\n");
        exit(EXIT_FAILURE);
    }
    if (res == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
	int client = Socket(AF_INET, SOCK_STREAM, 0);

		struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET;
    	adr.sin_port = htons(PORT);

	Inet_pton(AF_INET, IP_ADDR, &adr.sin_addr);

	Connect(client, (struct sockaddr *) &adr, sizeof adr);

	char buffer[BUFFER_SIZE];
	printf("Waiting for server \n");

    	recv(client, buffer, BUFFER_SIZE, 0);
    	printf("%s \n\n", buffer);
    	printf("Connection established. Enter \"q\" to end the connection \n\n");
	while (1) {
        	printf("Client: ");
        	fgets(buffer, BUFFER_SIZE, stdin);

       
        	size_t last = strlen(buffer) - 1;
        	if (buffer[last] == '\n') {buffer[last] = '\0';}

        
        	send(client, buffer, BUFFER_SIZE, 0);

                	if (buffer[0] == 'q'){break;}

        	        	printf("Server: ");
        	recv(client, buffer, BUFFER_SIZE, 0);
        	printf("%s \n\n", buffer);

        
        	if (buffer[0] == 'q'){break;}
    	}

    	close(client);
	return 0;
}
