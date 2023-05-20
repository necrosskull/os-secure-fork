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
#define IP_ADDR "127.0.0.1" 

int main() {

    //Сокет
    int client = Socket(AF_INET, SOCK_STREAM, 0);

    //Структура типа sockaddr_in, содержащая информацию об адресе сервера
    struct sockaddr_in adr = {0};

    adr.sin_family = AF_INET;
    adr.sin_port = htons(PORT);

    //Функция создания структуры с определённым сетевым адресом
    Inet_pton(AF_INET, IP_ADDR, &adr.sin_addr);
    
    //Подключение клиента к серверу
    Connect(client, (struct sockaddr *) &adr, sizeof adr);
     
        // Буфер для хранения сообщений
    char buffer[BUFFER_SIZE];

    printf("Waiting for server \n");

    // Получение и вывод в консоль сообщения от сервера
    recv(client, buffer, BUFFER_SIZE, 0);
    printf("%s \n\n", buffer);
    printf("Connection established. Enter \"x\" to end the connection \n\n");

    // Бесконечный цикл работы клиента
    while (1) {

        // Считывает информацию для отправки серверу
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Удаление символа конца строки
        size_t last = strlen(buffer) - 1;
        if (buffer[last] == '\n') {buffer[last] = '\0';}

        // Отправка сообщения серверу
        send(client, buffer, BUFFER_SIZE, 0);

        // Проверка сообщения на наличие символа выхода
        if (buffer[0] == 'x'){break;}

        // Получение и вывод сообщения от сервера
        printf("Server: ");
        recv(client, buffer, BUFFER_SIZE, 0);
        printf("%s \n\n", buffer);

        // Проверка отправленного сообщения на наличие символа выхода
        if (buffer[0] == 'x'){break;}
    }

    sleep(15);
    close(client);
    return 0;
}
