# Домашнее задание #3

Реализовать клиент-серверное приложение, в котором клиент аргументами командной строки получает ip адрес, порт и команду bash, которую должен выполнить сервер. Сервер получает строку с командой выполняет ее и возвращает результат выполнения клиенту. Клиент получает результат и прекращает работу. При получении сервером команды `exit` от клиента, его работа завершается. При обмене, оборачивать информацию в контейнер вида:

```
+-------------------+
| command | payload |
+-------------------+
```

Пример запросов с клиента: `exit | NULL`, `execute | ls -la \`, `execute | whoami`.

Пример ответов от сервера: `reponse | OK`, `response | .`, `response | fizzbuzz`.

Дизайн контейнера -- на усмотрение исполнителя.

Для успешного выполнения задания, файлы с исходным кодом должны быть выложены в этом репозитории (в текущей директории(./)) по аналогии с предыдущими ДЗ. Результат выполнения программ должен быть зафиксирован на скриншоте и выложен в этом репозитории.

Полезные материалы:

* [socket - create an endpoint for communication](https://man7.org/linux/man-pages/man2/socket.2.html)
* [The getopt() function parses the command-line arguments](https://man7.org/linux/man-pages/man3/getopt.3.html)
* [popen, pclose - pipe stream to or from a process](https://man7.org/linux/man-pages/man3/popen.3.html)
* [bind - bind a name to a socket](https://man7.org/linux/man-pages/man2/bind.2.html)
* [ip - Linux IPv4 protocol implementation](https://man7.org/linux/man-pages/man7/ip.7.html)
* [accept - accept a connection on a socket](https://man7.org/linux/man-pages/man2/accept.2.html)
* [connect - initiate a connection on a socket](https://man7.org/linux/man-pages/man2/connect.2.html)
