import socket

host = "0.cloud.chals.io"
p = 26265

def netcat(host, port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((host, int(port)))
    while True:
        data = s.recv(4096)
        if not data:
            break
        s.close()
        return(data)
    s.close()


def key_start(flag):
    key = [0, 0, 0, 0, 0]
    key[0] = flag[0] ^ ord('b')
    key[1] = flag[1] ^ ord('r')
    key[2] = flag[2] ^ ord('c')
    key[3] = flag[3] ^ ord('k')
    key[4] = flag[4] ^ ord('{')
    return key

def test_key(flag, key):
    i = 0
    keylen = len(key)
    new = []
    for c in flag:
        new.append(chr(c ^ key[i%keylen]))
        i += 1
    if '\n' in new:
        return
    print("".join(map(str,new)))
    print()
    print()

for i in range(200):
    newflag = netcat(host, p)
    if newflag:
        if len(newflag) == 42:
            key = key_start(newflag)
            test_key(newflag, key)