#!/usr/bin/python3

import socket
import sys

ip = sys.argv[1]
port = int(sys.argv[2])
cmd = sys.argv[3]
cmd2 = sys.argv[4]
request = cmd2 + ' | ' + cmd

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.connect((ip, port))
    sock.send(bytes(request, 'UTF-8'))
    if cmd2 == 'exit':
        print('Connection closed')
        quit()
    print('Client: ', cmd) 
    response = sock.recv(1024)
    print('Server: ', response.decode('utf-8').split(' | ')[1])
    print()
    sock.close()

print('Connection closed.')

