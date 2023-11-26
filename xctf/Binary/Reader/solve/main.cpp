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