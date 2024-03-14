# HTB Cyber Apocalypse 2024

## QuickScan

>  Author: clubby789


## Solution

Connecting to the server prompts you this

```
I am about to send you 128 base64-encoded ELF files, which load a value onto the stack. You must send back the loaded value as a hex string
You must analyze them all in under 60 seconds
Let's start with a warmup
ELF:  f0VMRgIBAQAAAAAAAAAAAAIAPgABAAAAl4MECAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAEAAOAABAAAAAAAAAAEAAAAFAAAAAAAAAAAAAAAAgAQIAAAAAACABAgAAAAAswMAAAAAAACzAwAAAAAAAAAQAAAAAAAAS2XaK6c97108OmEJYu7q0KkERcXrRhuiJBCRfPBp2ijGxdWcVOW2cUGTTaI0O6ya/95TzgqVOj6IsdL2yxjc79xPMlN0zF3mKcfSoPhMRfTny55yoUspZqVrlvrfaDUL7HIHSMgK1E8nPW8DnPD2WT2KZm/ow0Jl3/qnAwGe9belBVoMvM2FDs0yHrtOD6McstHRrsk0l4m8ocnICYnODmSJ5a9MMM+1SDLJvHwPj+o5VwMme5snx87P5HtjXn1EEdnqVcgLDBdTcAbKYSy45eqsBZTklInD6uA+/CwiSvErzOTdRDwyIwMwUsCLBJebcyQJm+stSRwdJc74Pb+lYluev1VUuqGJpFP5bVj1wrxjYBnGRWLdr6UyOkkvuW7xbWed/t8hE9l2Kh+Hj3BE/Pmw7/5XxO+/6g7S9ZBW0rkcs7SqIBcy8g+pbj6x4aEHdxGoTz3mf9CS1cya/2W7GZ21Em2OV8eiBk5ouZoOiiD4ldWOp4WDiNFDTROtfM3bWQyvYXZ8THc10AUXBG3PAYPF1x6wpenN36Cp+FKxyxkzwwKNYZZPoDVhSs15xUcL5R2ziuKEHw3z6aP9zSasJ1n2EeGSlY4rR3GW4ZicfbNF1trKbl4TH23gbrErugWeu6nzGET067tgkzEV1Fejmug3QoXc9WzwSYWea9fsakCwUVhfsubZxpQZWGlKFTJbpT59jxcAyOFI2POODA+NP+JhBta7DzCVqX3kurRet0O5AJ3u8u+g9KCzCgEEqmHOBfYPjGfXyuHmWxNA7X42tirMSP7mh4DvLF8CTt4fCV1sfGzIXJ5c1qgOtXTd6Jrl95zyZ5IALTDNZ/l5wqw3JBMW0EMTEBHjPQB+J1/is9gC7U6ID+SpxL0/+XGW91ShX9cydYoNOn2qDbA2r2CHnxBsSO0x+29Zo7jog7qedUd0OumnwxDxEwIXhB78vyu3rg2eCeJzGZbToXXRuMbx+cilrXxL9DuVtSaNe48q8ajqp9IDP3D+h7aWZfbhkSko1W36L9zaMzeaM4+92hdCTbGLY1DrLZkyzQ2EoEgka0iD7BhIjTVT/f//SInnuRgAAADzpLg8AAAADwU=
Expected bytes: 9ef5b7a5055a0cbccd850ecd321ebb4e0fa31cb2d1d1aec9
bytes?
```

Just sending the expected bytes back you get a new elf but without the answer this time.

I went and converted the first elf to a binary and went through it with gdb to see what is happening. 

```
0x8048397    sub    rsp, 0x18
   0x804839b    lea    rsi, [rip - 0x2ad]
   0x80483a2    mov    rdi, rsp
   0x80483a5    mov    ecx, 0x18
   0x80483aa    rep movsb byte ptr [rdi], byte ptr [rsi]
    ↓
   0x80483aa    rep movsb byte ptr [rdi], byte ptr [rsi]
```

I found out that it loops 24 times and writes 24 bytes into rsp so I could just print the bytes after rsp with `x/24bx $rsp`

I created a script for gdb that opens the exe runs the program to the correct spot and prints the bytes
<br/>[`solve.py`](solve.py)

I then created a shell script to launch gdb with the solve.py and print the memory addresses with the bytes
<br/>[`thescript.sh`](thescript.sh)

Then was time to create a script that parses the memory addresses from the file and gives the correct output
<br/>[`parser.py`](parser.py)

To finish it off I created a script that automatically connects to the server. creates the executable file and runs the other scripts for the answer and sends it back
<br/>[`realconnect.py`](realconnect.py)

After getting 128 correct answers in the time limit I got the flag