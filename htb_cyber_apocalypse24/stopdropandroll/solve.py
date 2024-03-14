import socket

host = "94.237.63.112"
port = 32888

def create_answer(line):
    ans = ""
    for a in line.split(', '):
        if "FIRE" in a:
            ans += "ROLL-"
        if "PHREAK" in a:
            ans += "DROP-"
        if "GORGE" in a:
            ans += "STOP-"
    #remove extra dash from end
    ans = ans[:-1]
    ans += '\n'
    return ans
    # print("ans", ans)

def connect(host, port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((host, int (port)))
    skip = True
    while True:
        data = s.recv(4096)
        if not data:
            s.close()
            return
        if skip:
            for line in data.decode("utf-8").splitlines():
                print(line)
                if "Are you ready" in line:
                    skip = False
                    s.sendall("y\n".encode())
        else:
            for line in data.decode("utf-8").splitlines():
                if "FIRE" in line or "PHREAK" in line or "GORGE" in line:
                    answer = create_answer(line)
                print(line)
                if "What do you do" in line:
                    print("ans", answer)
                    s.sendall(answer.encode())
connect(host, port)