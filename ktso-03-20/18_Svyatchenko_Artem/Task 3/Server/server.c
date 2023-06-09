#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

#define DEFAULT_PORT 8888
#define BUFFER_SIZE 1024
#define ERROR_S "SERVER ERROR:"
#define CLIENT_CLOSE_CONNECTION_SYMBOL '#'

bool is_client_connection_close(const char *msg) //Проверяет переданное сообщение на наличие символа завершения.
{
    for (int i = 0; i < strlen(msg); i++)
    {
        if (msg[i] == CLIENT_CLOSE_CONNECTION_SYMBOL)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int server;
    int client;

    struct sockaddr_in server_address; //Переменная типа сокет_адрес, которая содержит информацию об адресе сервера.

    client = socket(AF_INET, SOCK_STREAM, 0); //Создание cокета.
    if (client < 0)
    {
        printf("%s establishing socket error.\n", ERROR_S);
        return -1;
    }
    printf("SERVER: Socket for server was successfully created.\n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(DEFAULT_PORT);
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    int ret = bind(client, (struct sockaddr *)&server_address, sizeof(server_address)); //Связка адреса и сокета.

    if (ret < 0)
    {
        printf("%s binding connection. Socket has already been establishing.\n", ERROR_S);
        return -1;
    }

    socklen_t size = sizeof(server_address);
    printf("SERVER: Listening clients...\n");
    /* Первый аргумент - сокет для прослушивания. Второй аргумент - целое положительное число, определяющие максимальное
    количество запросов на установление связи, которые могут стоять в очереди, ожидая обработки сервером. */
    listen(client, 1); //Начинаем слушать порт в ожидании соединения со стороны клиента.

    /* Первый аргумент функции - сокет-дескриптор для принятия связей от клиентов. Второй аргумент - указатель на адрес клиента (структура sockaddr)
    для соответствующего домена. Третий аргумент - указатель на целое число - длину структуры адреса. Второй и третий аргументы заполняются соответствующими
    значениями в момент установления связи клиента с сервером и позволяют серверу точно определить, с каким именно клиентом он общается. Если сервер
    не интересуется адресом клиента, в качестве второго и третьего аргументов можно задать NULL-указатели.*/
    server = accept(client, NULL, NULL); //Связываем сокет сервер и сокет клиент.
    if (server < 0)
    {
        printf("%s Can't accepting client.\n", ERROR_S);
        return -1;
    }

    char buffer[BUFFER_SIZE]; //Используется для хранения сообщений (которые приходят и которые будут отправлены).

    strcpy(buffer, "=> Server connected!"); //Копируем в "buffer" сообщение, которое хотим отправить. (Этот текст получит клиент при подключении к серверу).
    send(server, buffer, BUFFER_SIZE, 0);   //Отправляем сообщение клиенту.
    printf("=> Connected to the client #1. Enter %c to end the connection.\n\n", CLIENT_CLOSE_CONNECTION_SYMBOL);

    while (true)
    {
        printf("Client: ");
        recv(server, buffer, BUFFER_SIZE, 0);           //Принимаем сообщение (bash команду) от клиента.
        printf("%s\n", buffer);                         //Выводим на экран полученное сообщение.
        if (is_client_connection_close(buffer) == true) //Проверяем полученное сообщение на наличие символа завершения.
        {
            break;
        }

        printf("Server: Request accepted, processing...\n");

        char execute[BUFFER_SIZE] = "./handler.sh "; //Переменная execute = ./handler.sh [команда bash от клиента].
        strcat(execute, buffer);

        //Функция system() передает строку, адресуемую параметром execute, в качестве команды для командного процессора операционной системы.
        system(execute); //Здесь вызывается bash скрипт "handler.sh" с параметром bash команды, которую надо выполнить. (В скрипте переопределены поток вывода и поток ошибок; Результат выполнения bash команды будет записан в файл "result.txt").

        sleep(3); //Ждём 3 секунды.

        /* Работа с файлом "result.txt". Считываем результат работы (если все прошло успешно) bash команды, которая была получена от клиента. */
        FILE *file; //Указатель на файл.

        char line[BUFFER_SIZE] = "";                   //Переменная, используемая для чтения данных из файла.
        if ((file = fopen("result.txt", "r")) != NULL) // Пытаемся открыть файл, который хранит результат работы bash команды, на чтение.
        {
            //Файл "result.txt" открыт.
            while (fgets(buffer, BUFFER_SIZE, file)) //Считываем данные пока они есть.
            {
                strcat(line, buffer);
            }

            fclose(file); //Закрываем файл.
        }
        else
        {
            //Файл "result.txt" не был создан или его не удалось открыть.
            printf("%s problems with the file result.txt.\n", ERROR_S);
            return -1;
        }

        printf("Server: Sending the result to the client.\n\n");

        send(server, line, BUFFER_SIZE, 0); //Отправляем сообщение клиенту.
    }

    /* Аргумент - закрываемый сокет-дескриптор. (Эта функция закрывает сокет и разрывает все соединения с этим сокетом. В отличие
    от функции "shutdown" функция "close" может дожидаться окончания всех операций с сокетом, обеспечивая "нормальное", а не аварийное закрытие соединений). */
    close(client);

    system("rm -rf result.txt"); //Удаляем файл "result.txt".

    printf("\nGoodBye...\n");
    return 0;
}