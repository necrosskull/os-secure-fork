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

void Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen) {
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

int Accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) {
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

int main() {
    //Сокет
    int server = Socket(AF_INET, SOCK_STREAM, 0);

    //Адрес сервера
    struct sockaddr_in adr = { 0 };

    adr.sin_family = AF_INET;
    adr.sin_port = htons(PORT);

    //Привязка сокета к адресу
    Bind(server, (struct sockaddr*)&adr, sizeof adr);

    //Прослушка
    Listen(server, 1);
    socklen_t adrlen = sizeof adr;

    //Прием клиента
    int client = Accept(server, (struct sockaddr*)&adr, &adrlen);

    //Буфер
    char buffer[BUFFER_SIZE];

    //Копирование сообщения в буфер
    strcpy(buffer, "Server connected");

    //Отправка сообщения
    send(client, buffer, BUFFER_SIZE, 0);
    printf("Connected to the client. Enter \"q\" to end the connection \n\n");
    while (1) {

        // Приём и вывод полученного сообщения
        printf("Client: ");
        recv(client, buffer, BUFFER_SIZE, 0);
        printf("%s\n\n", buffer);

        // Проверка сообщения на наличие символа выхода
        if (buffer[0] == 'q') {
            break;
        }

        printf("Executing... \n");

        char execute[BUFFER_SIZE] = "echo | ";
        strcat(execute, buffer);
        strcat(execute, " 1> response.txt 2> response.txt");
        system(execute);

        // Впадает в сон на 5 секунд
        sleep(5);

        // Указатель на response.txt
        FILE* file;

        // Переменная для чтения строк из респонса
        char line[BUFFER_SIZE] = "";

        // Открытие response.txt
        if ((file = fopen("response.txt", "r")) != NULL) {

            // Считывание данных из респонса
            while (fgets(buffer, BUFFER_SIZE, file)) {
                strcat(line, buffer);
            }

            // Закрытие файла
            fclose(file);

        }
        else {

            // Вывод ошибки при неудачной попытке открытия файла
            printf("Problems with the file response.txt. \n");
            return -1;

        }

        printf("Sending response \n");

        // Отправка сообщения юзеру
        send(client, line, BUFFER_SIZE, 0);

        printf("Done! \n");

    }

    close(client);
    system("rm -rf response.txt");
    close(server);
    return 0;
}
