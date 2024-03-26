# picoCTF 2024

## Verify

> People keep trying to trick my players with imitation flags. I want to make sure they get the real thing! I'm going to provide the SHA-256 hash and a decrypt script to help you know that my flags are legitimate.
> </br> You can download the challenge files here:
> </br> [`challenge.zip`](challenge.zip)
> </br> Additional details will be available after launching your challenge instance.
>
> Author: JEFFERY JOHN

# solution

There is a decrypt.sh and you clearly just have to run that for each file in the files folder.

I created this simple a.sh shell script to run the decrypt.sh on each file and ran it with `./a.sh | sort` and the flag was printed as the last output line `picoCTF{trust_but_verify_451fd69b}`