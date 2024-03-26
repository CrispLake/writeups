data = b''
with open("challengefile", "rb") as f:
    data = f.read()

with open("./test", "wb") as f:
    for i in range(0, len(data), 4):
        rev = data[i:i+4]
        rev = rev[::-1]
        f.write(rev)

