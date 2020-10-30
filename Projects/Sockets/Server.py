import socket
import threading
import  time

HEADER = 64
PORT = 5500
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER,PORT)
FORMAT = "utf-8"
DISCONNECT_MESSAGE = "!dis"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

def client_handler(conn,addr):
    print(f"[New Client]: {addr}")
    print(f"Currently connected {threading.active_count()-1}")
    while True:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length=int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                print("[CLIENT DISCONNECTED]")
                break
            print(f"[{msg}]")
    conn.close()
def begin():
    server.listen()
    while True:
        conn, addres = server.accept()
        thread=threading.Thread(target=client_handler,args=(conn,addres))
        thread.start()

print(f"[ STARTING ON {SERVER} ,{PORT}]")
time.sleep(2.5)
print("[ SERVER ONLINE ]")
print(f"Currently Connected: {threading.active_count()-1}")
begin()