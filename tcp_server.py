import socket

HOST = '0.0.0.0'
PORT = 9999

print(f"Starting TCP server on {HOST}:{PORT}")

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print("Waiting for connection...")
    while True:
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            conn.sendall(b'123456')
            print("Sent 6 bytes: 123456")
            conn.close()
            print("Connection closed")

