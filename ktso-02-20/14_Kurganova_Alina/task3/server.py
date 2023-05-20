#!/usr/bin/python3
# -*- coding: utf-8 -*-

import socket
import os

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(('localhost', 2834))
    print('Socket created successfully!')
    sock.listen(1)
    print('Server is waiting for connection...')

    while True:
        conn, addr = sock.accept()
        print(f'Connected by {addr}')
        print('Waiting for command...')
        data = conn.recv(1024)
        print('Client: ', data.decode('utf-8'))

        if data.decode('utf-8').split(' | ')[0] == 'exit':
            break

        elif data.decode('utf-8').split(' | ')[0] == 'execute':
            print('Executing...')
            response = 'response | ' + os.popen(data.decode('utf-8').split(' | ')[1]).read()
            conn.send(bytes(response, 'utf-8'))
            print('Done!')

        conn.close()
        print()
            

print('Connection closed.') 


