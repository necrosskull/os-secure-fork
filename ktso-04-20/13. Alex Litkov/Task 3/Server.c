#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

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

int Buffer(int client) {
  char buffer[BUFFER_SIZE];

  strcpy(buffer, "Server connected");

  send(client, buffer, BUFFER_SIZE, 0);
  printf("Connected to the client. Enter \"q\" to end the connection \n\n");
  while (1) {
    printf("Client: ");
    recv(client, buffer, BUFFER_SIZE, 0);
    printf("%s\n\n", buffer);

    if (buffer[0] == 'q') {
      break;
    }

    printf("Executing... \n");

    char execute[BUFFER_SIZE] = "echo | ";
    strcat(execute, buffer);
    strcat(execute, " 1> response.txt 2> response.txt");
    system(execute);

    sleep(5);

    FILE *file;

    char line[BUFFER_SIZE] = "";

    if ((file = fopen("response.txt", "r")) != NULL) {

      while (fgets(buffer, BUFFER_SIZE, file)) {
        strcat(line, buffer);
      }

      fclose(file);

    } else {

      printf("Problems with the file response.txt. \n");
      return -1;
    }
  }
}

int main() {
  int server = Socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in adr = {0};

  adr.sin_family = AF_INET;
  adr.sin_port = htons(PORT);

  Bind(server, (struct sockaddr *)&adr, sizeof adr);

  Listen(server, 1);
  socklen_t adrlen = sizeof adr;

  int client = Accept(server, (struct sockaddr *)&adr, &adrlen);

  Buffer(client);

  close(client);
  system("rm -rf response.txt");
  close(server);
  return 0;
}
