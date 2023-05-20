#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
    
#define PORT 5050
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"

int main() {
    
    // Сокет 
    int client;

    // Переменная типа сокет_адрес, которая содержит информацию об адресе сервера
    struct sockaddr_in server_address; 

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, & server_address.sin_addr);

    // Создание сокета для подключения к серверу
    client = socket(AF_INET, SOCK_STREAM, 0); 
    if (client < 0) {
        printf("Client: Creating socket error \n");
        return -1;
    }

    printf("Client socket was successfully created \n");

    // Подключение клиента к серверу
    // Аргументы: сокет-дескриптор клиента и указатель на адрес сервера
    int ret = connect(client, (struct sockaddr * ) & server_address, sizeof(server_address)); 

    if (ret == 0) {
        printf("Connecting to server %s on port %d \n", inet_ntoa(server_address.sin_addr), PORT);
    } else {
        printf("Client: Failed connection to server \n");
        return -1;
    }

    // Буфер для хранения сообщений
    char buffer[BUFFER_SIZE];

    printf("Waiting for server \n");

    // Получение и вывод в консоль сообщения от сервера
    recv(client, buffer, BUFFER_SIZE, 0);
    printf("%s \n", buffer);
    printf("Connection established. Enter \"q\" to end the connection \n\n");

    // Бесконечный цикл работы клиента
    while (true) {

        // Считывает информацию для отправки серверу
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Удаление символа конца строки
        size_t last = strlen(buffer) - 1;
        if (buffer[last] == '\n') {
            buffer[last] = '\0';
        }

        // Отправка сообщения серверу
        send(client, buffer, BUFFER_SIZE, 0);

        // Проверка сообщения на наличие символа выхода
        if (buffer[0] == 'q'){
            break;
        }

        // Получение и вывод сообщения от сервера
        printf("Server: ");
        recv(client, buffer, BUFFER_SIZE, 0);
        printf("%s \n\n", buffer);

    }


    // Прекращение работы клиента
    // Аргумент - закрываемый сокет-дескриптор 
    close(client);

    return 0;
}