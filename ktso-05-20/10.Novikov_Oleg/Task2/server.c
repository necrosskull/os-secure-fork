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
#define BUFFER_SIZE 2048

int main() {

    // Сокеты 
    int server;
    int client;

    // Переменная типа сокет_адрес, которая содержит информацию об адресе сервера
    struct sockaddr_in server_address;

    // Создание сокета клиента
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) {
        printf("Server: Creating socket error: \n");
        return -1;
    }
    printf("Socket was successfully created \n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    // Связывание адреса и сокета
    int ret = bind(client, (struct sockaddr*)&server_address, sizeof(server_address));

    if (ret < 0) {
        printf("Server: Binding connection error \n");
        return -1;
    }

    socklen_t size = sizeof(server_address);
    printf("Listening client \n");

    // Прослушивание порта в ожидании соединения со стороны клиента. 
    // Аргументы: сокет и максимальное количество запросов 
    listen(client, 1);

    // Связывание сокета сервера и сокета клиента
    // Аргументы: сокет-дескриптор, указатель на адрес клиента и указатель на длину структуры адреса 
    server = accept(client, NULL, NULL);

    if (server < 0) {
        printf("Server: Can't accepting client \n");
        return -1;
    }

    // Буфер для хранения сообщений
    char buffer[BUFFER_SIZE];

    // Копирование сообщения в буфер
    strcpy(buffer, "Server connected");

    // Отправка сообщения
    send(server, buffer, BUFFER_SIZE, 0);
    printf("Connected to the client. Enter \"q\" to end the connection \n\n");

    // Бесконечный цикл работы сервера
    while (true) {

        // Приём и вывод полученного сообщения
        printf("Client: ");
        recv(server, buffer, BUFFER_SIZE, 0);
        printf("%s\n\n", buffer);

        // Проверка сообщения на наличие символа выхода
        if (buffer[0] == 'q') {
            break;
        }

        // Получение информации от клиента
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Удаление символа конца строки
        size_t last = strlen(buffer) - 1;
        if (buffer[last] == '\n') {
            buffer[last] = '\0';
        }

        // Отправка сообщения клиенту
        send(server, buffer, BUFFER_SIZE, 0);

        // Проверка отправленного сообщение на наличие символа выхода
        if (buffer[0] == 'q') {
            break;
        }
    }

    // Прекращение работы сервера
    // Аргумент - закрываемый сокет-дескриптор 
    close(client);

    return 0;
}