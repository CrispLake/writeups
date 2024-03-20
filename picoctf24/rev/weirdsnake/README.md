# picoCTF 2024

## weirdSnake

> I have a friend that enjoys coding and he hasn't stopped talking about a snake recently
He left this [`file`](snake) on my computer and dares me to uncover a secret phrase from it. Can you assist?
>
>   Author: JUNIAS BONOU


## Solution

Looking through the file it looks like it's disassembled python code. I couldn't find a way to reassemble it through any tools so as a last resort before starting to do it by hand asked if chatGPT can make it to some sensible code and it did amazing job

```py
input_list = [4, 54, 41, 0, 112, 32, 25, 49, 33, 3, 0, 0, 57, 32, 108, 23, 48, 4, 9, 70, 7, 110, 36, 8, 108, 7, 49, 10, 4, 86, 43, 102, 126, 92, 0, 16, 58, 41, 89, 78]

key_str = 'J'
key_str += '_'
key_str += 'o'
key_str += '3'
key_str += 't'

key_list = [ord(char) for char in key_str]

while len(key_list) < len(input_list):
    key_list.extend(key_list)

result = [a ^ b for a, b in zip(input_list, key_list)]
result_text = ''.join(map(chr, result))

print(result_text)
```

but running the code it prints out this weird string `NiF3jF^wJ_V]ok:2M1K;Mne7"a9otZeFj:`

Checking out the code I can see that the only operation it does is just xoring the 5 key characters to everything in the input list

So I tried to switch the key chars to the start of a flag `picoC` and I get this output ``t_Jo3PpRN@piZO/gYgfwGg/wXik[3C`SJ6``

I see that the first 5 chars are the same characters as in the key_str but just in different order.

So I just switched them to the correct order in the script [a.py](a.py) and now it prints the flag `picoCTF{N0t_sO_coNfus1ng_sn@ke_9433dec6}`