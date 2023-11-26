# Reader

We get this big data.txt filled with random characters and then we got a binary

Running the binary with arguments seems to do something for couple seconds but there is no output

Opening it on ghidra reveals this pretty long main.

We can see that the whole program is wrapper in an if that checks if the program got 1 argument only

There is this one line that shows that it opens the data.txt

`local_38 = fopen("data.txt","rb");`

after that we find a lot of similar looking nested if statements

```
fseek(local_38,0xc7e,0);
fread(&local_4e,1,1,local_38);
if (local_4e == *(char *)(*(long *)(param_2 + 8) + 0xb)) {
    ...
}
```

We can see that fseek moves our file pointer to this specific spot in the file and then fread reads 1 byte from it. Then it compares the byte to something. param_2 seems to be main's argv and +8 to it means it is accessing our string we gave as an argument. Then it is accessing the 0xb (11) index character from the string so we get this:

`if (local_4e == argv[1][11])`

Then if we pass all the if statements there is a printf at the end
```
printf("If you got here and actually solved it, your input is correct! : %c%c%c%c{%c%c%c%c%c%c%c%c}"
        ,(ulong)(uint)(int)**(char **)(param_2 + 8),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 1),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 2),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 3),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 5),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 6),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 7),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 8),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 9),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 10),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 0xb),
        (ulong)(uint)(int)*(char *)(*(long *)(param_2 + 8) + 0xc));
```

We can see that it just prints our string back skipping 4th index but in the print it is '{'

I created this main that accesses all the same points in the file as the reader and stores them in the correct indexes
```
#include <cstdio>
#include <iostream>

void    f(std::FILE* file, int file_pos, int s_pos, char *s)
{
    char curr_char;
    fseek(file,file_pos,0);
    fread(&curr_char,1,1,file);
    s[s_pos] = curr_char;
}

int main()
{
    char s[15];

    s[4] = '{';
    s[13] = '}';
    s[14] = 0;
    std::FILE* file = fopen("data.txt", "rb");
    f(file, 0xc7e, 0xb, s);
    f(file, 0x1346, 1, s);
    f(file, 0x2bd2, 3, s);
    f(file, 0x2ef, 0xc, s);
    f(file, 0x1bfb, 0, s);
    f(file, 0x17ce, 5, s);
    f(file, 0x2a1c, 9, s);
    f(file, 0x188d, 10, s);
    f(file, 0x21a0, 7, s);
    f(file, 0x323d, 2, s);
    f(file, 0x289e, 8, s);
    f(file, 0x1e61, 6, s);

    std::cout << s << "\n";
}
```

```
$ ./a.out
XCTF{BYTEREAD}
$ ./reader XCTF{BYTEREAD}
If you got here and actually solved it, your input is correct!: XCTF{BYTEREAD}
```

And we got the flag: `XCTF{BYTEREAD}`