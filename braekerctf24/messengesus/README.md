# BraekerCTF

## Messengesus

> You encounter a bot meditating in the park. He opens his cameras and begins to speak.
>
>
> "Hear the word of RNGesus. Complexity is the enemy of security. Let your encryption be as simple as possible, as to secure it, thusly". He hands you a flyer with a snippet of code. "Secure every message you have with it. Only those who see can enter."
>
>
> What do you think? Is it simple enough to be secure?
>
>  Author: shoaloak and spipm
>
> nc 0.cloud.chals.io 26265
>
> [`messengesus.c`](messengesus.c)


## Solution

There is a c file attached that is running on the server. By taking a look at the c file we can see that it has the flag as a string. Then it reads random bytes from /dev/urandom with getline and uses those random bytes to encrypt the flag. Then it prints the flag.

So getline reads until it reaches '\n'. We know that the flag format is brck{} and can use the start of that to get the key by trying to get hit on a key that is short enough

I created this script to connect to the server get the key from the first 5 chars and try that to decrypt the whole flag:
<br/>[`solve.py`](solve.py)

I was running it for under a minute when I already got the flag: `brck{SiMPl1c1Ty_1s_K3Y_But_N0t_th3_4nSW3r}
`