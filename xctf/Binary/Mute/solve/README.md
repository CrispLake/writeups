# Mute

```
$ ./mute
this is not the flag you are looking for
```

Using strings or ltrace gives nothing of useful

using xxd to get hexdump from the binary we can find these lines
```
00001630: 7800 0063 0000 7400 0066 0000 7b00 0075  x..c..t..f..{..u
00001640: 0000 6e00 006d 0000 7500 0037 0000 3300  ..n..m..u..7..3.
00001650: 005f 0000 6d00 0033 0000 5f00 0070 0000  ._..m..3.._..p..
00001660: 3100 0033 0000 3400 0035 0000 3300 007d  1..3..4..5..3..}
```
so we found the flag: `xctf{unmu73_m3_p13453}`