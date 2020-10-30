import socket
import

HEADER = 64
PORT = 5500
FORMAT = "utf-8"
DISCONNECT_MESSAGE = "!dis"
SERVER = "192.168.0.17"
ADDR = (SERVER,PORT)


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

client.settimeout(0.1)
def send(msg):
    message=msg.encode(FORMAT)
    send_length=str(len(message)).encode(FORMAT)
    send_length += b' ' * (HEADER-len(send_length))
    client.send(send_length)
    client.send(message)

while True:
    send(input(y:="Enter password: "))
    if y=="":
        send(DISCONNECT_MESSAGE)