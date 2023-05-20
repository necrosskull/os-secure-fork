#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 6505
#define buffer_s 1024
#define IP "127.0.0.1"

//Сonnection process
void is_conected(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  int res = connect(sockfd, addr, addrlen);
  if (res == -1) {
    perror("ERROR: connection failed");
    exit(EXIT_FAILURE);
  }
}

//Socket connection
int is_socket(int domain, int type, int protocol) {
  int res = socket(domain, type, protocol);
  if (res == -1) {
    perror("ERROR: socket creation failed");
    exit(EXIT_FAILURE);
  }
  return res;
}

//Buffer work
void Buffer(int client) {
  char buffer[buffer_s];
  printf("Waiting for server \n");

  recv(client, buffer, buffer_s, 0);
  printf("%s \n\n", buffer);
  printf("Connection established. Enter \"q\" to end the connection \n\n");

  while (1) {

    printf("Client: ");
    fgets(buffer, buffer_s, stdin);

    size_t last = strlen(buffer) - 1;
    if (buffer[last] == '\n') {
      buffer[last] = '\0';
    }

    send(client, buffer, buffer_s, 0);

    if (buffer[0] == 'q') {
      break;
    }

    printf("Server: ");
    recv(client, buffer, buffer_s, 0);
    printf("%s \n\n", buffer);

    if (buffer[0] == 'q') {
      break;
    }
  }
}

int main() {
  // Socket creation
  int client = is_socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in adr = {0};
  adr.sin_family = AF_INET;
  adr.sin_port = htons(port);

  int res = inet_pton(AF_INET, IP, &adr.sin_addr);

  if (res == 0) {
    printf("ERROR:  Inet_pton failed: src does not contain a character"
           " string representing a valid network address in the specified"
           " address family\n");
    exit(EXIT_FAILURE);
  }

  if (res == -1) {
    perror("ERROR:  Inet_pton failed");
    exit(EXIT_FAILURE);
  }

  is_conected(client, (struct sockaddr *)&adr, sizeof adr);
  Buffer(client);
}
