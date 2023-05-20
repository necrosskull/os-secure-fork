#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "erproc.h"
#include <string.h>


#define PORT 6505
#define BUFFER_SIZE 1024

int main() {

    //Сокет
    int server = Socket(AF_INET, SOCK_STREAM, 0);

    //Структура типа sockaddr_in, содержащая информацию об адресе сервера
    struct sockaddr_in adr = {0};

    adr.sin_family = AF_INET;
    adr.sin_port = htons(PORT);

    //Функция привязки сокета к адресу
    Bind(server, (struct sockaddr *) &adr, sizeof adr);
    
    //Прослушивание
    Listen(server, 1);
     
    socklen_t adrlen = sizeof adr;
    //Приём клиента
    int client = Accept(server, (struct sockaddr *) &adr, &adrlen);

    //Буффер для хранения сообщений
    char buffer[BUFFER_SIZE];

    // Копирование сообщения в буфер
    strcpy(buffer, "Server connected");

    // Отправка сообщения
    send(client, buffer, BUFFER_SIZE, 0);
    printf("Connected to the client. Enter \"x\" to end the connection \n\n");

    // Бесконечный цикл работы сервера
    while (1) {

        // Приём и вывод полученного сообщения
        printf("Client: ");
        recv(client, buffer, BUFFER_SIZE, 0);
        printf("%s\n\n", buffer);

        // Проверка сообщения на наличие символа выхода
        if (buffer[0] == 'x'){break;}

        // Получение информации от клиента
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Удаление символа конца строки
        size_t last = strlen(buffer) - 1;
        if (buffer[last] == '\n') {buffer[last] = '\0';}

        // Отправка сообщения клиенту
        send(client, buffer, BUFFER_SIZE, 0);

        // Проверка отправленного сообщение на наличие символа выхода
        if (buffer[0] == 'x'){break;}
    }

    sleep(15);

    close(client);
    close(server);
    return 0;
}