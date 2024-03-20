# picoCTF 2024

## FactCheck

>   This binary is putting together some important piece of information... Can you uncover that information?
Examine this [`file`](bin). Do you understand its inner workings?
>
>   Author: JUNIAS BONOU


## Solution

Running strings gives me `picoCTF{wELF_d0N3_mate_` so I am missing the ending

stepping through the program with gdb and it starts adding characters to the flag and I get the flag from there `picoCTF{wELF_d0N3_mate_239b483f}`