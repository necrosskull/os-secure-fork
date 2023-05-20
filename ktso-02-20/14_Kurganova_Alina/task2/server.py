#!/usr/bin/python3
# -*- coding: utf-8 -*-

import socket

sock=socket.socket()
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind(('localhost', 1414))
print('Socket created successfully!')

sock.listen(1)
print('Server is waiting for connection...')


conn, addr=sock.accept()
print('Connection established')

while True: 
    data=conn.recv(1024)
    print('Client: ', data.decode('utf-8'))
    if data.decode('utf-8') == 'bye':
        break
    print('Server: ', (data.decode('utf-8')).upper())
    print()
    conn.send(data.upper())

conn.shutdown(1)
conn.close()
print('Connection closed.')



