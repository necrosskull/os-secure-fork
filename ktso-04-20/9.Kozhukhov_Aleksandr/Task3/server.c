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


        printf("Executing... \n");

        char execute[BUFFER_SIZE] = "echo | ";
        strcat(execute, buffer);
        strcat(execute, " 1> response.txt 2> response.txt");
        system(execute); 

        // Впадает в сон на 8 секунд
        sleep(8); 

        // Указатель на response.txt
        FILE *file;

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

        } else {

            // Вывод ошибки при неудачной попытке открытия файла
            printf("Problems with the file response.txt. \n");
            return -1;

        }

        printf("Sending response \n");

        // Отправка сообщения юзеру
        send(client, line, BUFFER_SIZE, 0);
        
        printf("Done! \n");
    } 

    sleep(15);

    close(client);

    system("rm -rf response.txt");

    close(server);

    return 0;
}