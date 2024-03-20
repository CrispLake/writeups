# picoCTF 2024

## Classic Crackme 0x100

> A classic Crackme. Find the password, get the flag!
Binary can be downloaded [`here`](crackme100).
Crack the Binary file locally and recover the password. Use the same password on the server to get the flag!
Additional details will be available after launching your challenge instance.
>
>   Author: NANDAN DESAI


## Solution

Going through the program with gdb I find this string being given to strlen
`kgxmwpbpuqtorzapjhfmebmccvwycyvewpxiheifvnuqsrgexl`

Also the password I gave to the exe is going through some encryption process

I opened it with ghidra and see that after the encryption process, it compares the modified password to the string I found earlier

Here is the modifying process 

```c
  local_18 = 0x55;
  local_1c = 0x33;
  local_20 = 0xf;
  local_21 = 'a';
  for (; local_c < 3; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < local_14; local_10 = local_10 + 1) {
      local_28 = (local_10 % 0xff >> 1 & local_18) + (local_10 % 0xff & local_18);
      local_2c = ((int)local_28 >> 2 & local_1c) + (local_1c & local_28);
      iVar1 = ((int)local_2c >> 4 & local_20) +
              ((int)local_a8[local_10] - (int)local_21) + (local_20 & local_2c);
      local_a8[local_10] = local_21 + (char)iVar1 + (char)(iVar1 / 0x1a) * -0x1a;
    }
  }
  ```

Inspecting what it does I found out that the characters don't affect other ones in the password so I can just bruteforce it char by char

I created this simple [c program](a.c) to do the bruteforcing and got the password
```
kdugtj(grknflq$dgb`d+%d#)mnm&mj"tjr`b(`&pelejf'"rc
```

now just launch the instance, connect to it and give it the password and I get the flag `picoCTF{s0lv3_angry_symb0ls_45518832}`