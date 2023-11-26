# Bits

You get a binary file that you need to give the correct flag for it to print out "Correct"

```
$ ./bits
Wrong number of arguments
$ ./bits 42
Wrong
$ ltrace ./bits 42
strcmp("xctf{S1MPL3_B1N4RY}", "42")    = 68
puts("Wrong"Wrong
)   = 6
+++ exited (status 0) +++
$ ./bits xctf{S1MPL3_B1N4RY}
Correct
```
So I got the flag: `xctf{S1MPL3_B1N4RY}`