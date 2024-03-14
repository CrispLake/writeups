import sys

input = ""
for line in sys.stdin:
    l = line[16:]
    arr = l.split()
    for a in arr:
        a = a[2:]
        input += a
print(input)