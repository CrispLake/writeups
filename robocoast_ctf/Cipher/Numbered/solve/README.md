# Numbered

You get this number string `4280848108410201408820818204204281028804010818802888`

googling `cipher symbols 01248` will give you first result to this page which explains the cipher https://ctf-wiki.mahaloz.re/crypto/classical/others/#01248-password

By creating this simple solver we get the flag `xctf{numbersfordayz}`

```
#include <stdio.h>

int main()
{
    char *s = "4280848108410201408820818204204281028804010818802888";
    char c = 'a' - 1;
    for (int i = 0; s[i]; i++)
    {
        switch (s[i])
        {
            case '0':
                printf("%c", c);
                c = 'a' - 1;
                break;
            case '1':
                c += 1;
                break;
            case '2':
                c += 2;
                break;
            case '4':
                c += 4;
                break;
            case '8':
                c += 8;
                break;
        }
    }
    printf("%c\n", c);
}
```