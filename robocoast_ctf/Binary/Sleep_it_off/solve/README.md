# Sleep it off

Just running the binary it seems to be stuck or something

Opening it on ghidra shows that there is alot of sleeps with big timers. We can patch the timer to 0 seconds by finding the instruction before the sleep call that moves the time amount for the sleep call. Just right click the number, choose patch instruction and change it to 0x0 and press enter. Repeat for all the sleep calls

```
001013d4 bf 7f 19        MOV        EDI,0x98197f
            98 00
001013d9 e8 72 fc        CALL       <EXTERNAL>::sleep
            ff ff

```

After that is done the file can be exported to a program `File->Export program` with Format `Original file`

Running the patched program gives us the flag: `xctf{1m_Fe31inG_5l33PY_70d4Y}`