#!/usr/bin/env python3

import socket

HOST = '192.168.1.16'
PORT = 8080

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'Hello World')
    data = s.recv(1024)

print('Received',str(data).rstrip('\x00'))
