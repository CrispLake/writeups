import socket
import subprocess
import base64

host = "83.136.255.230"
p = 52262

def connect(host, port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((host, int(port)))
    with open("log", "a") as log:
        while True:
            data = s.recv(4096)
            if not data:
                s.close()
                return
            for line in repr(data).split('\\'):
                # print(line)
                log.write(line + "\n")
                if "ELF:" in line:
                    elf = line[line.index("ELF:") + 6:]
                    # print("realelf")
                    # print(elf)
                    exec = base64.b64decode(elf)
                    with open("chal", "wb") as file:
                        file.write(exec)
                    subprocess.call(['bash', './thescript.sh'])
                    ans = ""
                    with open("answer", "r") as answer:
                        ans = answer.readline()
                    s.sendall(ans.encode())

connect(host, p)
