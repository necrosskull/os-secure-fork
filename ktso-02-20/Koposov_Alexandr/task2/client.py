#!/usr/bin/python3
# -*- coding: utf-8 -*-
import socket

sock=socket.socket()
sock.connect(('localhost', 1414))

while True:
    print('Please, enter the text: ', end='')
    s = str(input())
    sock.send(bytes(s, 'UTF-8'))
    if s == 'bye':
        break
    data=sock.recv(1024)
    data = data.decode('utf-8')
    print('Server: ', data)
    print()
sock.close()
