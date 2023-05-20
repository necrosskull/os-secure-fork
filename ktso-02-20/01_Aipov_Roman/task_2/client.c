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
#define SERVER_IP "127.0.0.1"

int main() {

	 
	int client;
	
  	struct sockaddr_in server_address; 

  	client = socket(AF_INET, SOCK_STREAM, 0); 
  	if (client < 0) {
        printf("Client: Creating socket error \n");
        return -1;
    }

  	server_address.sin_family = AF_INET;
  	server_address.sin_port = htons(PORT);
  	inet_pton(AF_INET, SERVER_IP, & server_address.sin_addr);

    printf("Client socket was successfully created\n");

  	int ret = connect(client, (struct sockaddr * ) & server_address, sizeof(server_address)); 

  	if (ret == 0) {
  	  	printf("Connecting to server %s on port %d \n", inet_ntoa(server_address.sin_addr), PORT);
  	} else {
  	  	printf("Client: Failed connection to server \n");
  	  	return -1;
  	}

  	char buffer[BUFFER_SIZE];

  	printf("Waiting for server \n");

  	recv(client, buffer, BUFFER_SIZE, 0);
  	printf("%s \n", buffer);
  	printf("Connection established. Enter \"q\" to end the connection \n\n");

  	while (true) {

    	printf("Client: ");
    	fgets(buffer, BUFFER_SIZE, stdin);

    	size_t last = strlen(buffer) - 1;
    	if (buffer[last] == '\n') {
    	  	buffer[last] = '\0';
    	}

    	send(client, buffer, BUFFER_SIZE, 0);

    	if (buffer[0] == 'q'){
    	  	break;
    	}

    	printf("Server: ");
    	recv(client, buffer, BUFFER_SIZE, 0);
    	printf("%s\n\n", buffer);

    	if (buffer[0] == 'q'){
    	  	break;
    	}
  	}
 
  	close(client);

  	return 0;
}
