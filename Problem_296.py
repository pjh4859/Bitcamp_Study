import socket

print('파이썬 TCP/IP 클라이언트 프로그래밍')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    client.connect(('127.0.0.11', 10000))
    client.sendall(b'Hello')
    client.close()
except:
    print('서버에 접속할 수 업습니다.')
