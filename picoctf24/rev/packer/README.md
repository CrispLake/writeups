# picoCTF 2024

## packer

>   Reverse this linux executable?
>
> [`binary`](out)
>
>   Author: MUBARAK MIKAIL


## Solution

Running the binary asks for a password

```
$ ./out
Enter the password to unlock this file: abc
You entered: abc

Access denied
```

Using strings I don't find a password but I find the following string

`$Info: This file is packed with the UPX executable packer http://upx.sf.net $`

After installing the packer and unpacking the binary with it, I ran strings again on the new one and find this

`Password correct, please see flag: 7069636f4354467b5539585f556e5034636b314e365f42316e34526933535f36666639363465667d`

Converting the flag from hex and I get `picoCTF{U9X_UnP4ck1N6_B1n4Ri3S_6ff964ef}`