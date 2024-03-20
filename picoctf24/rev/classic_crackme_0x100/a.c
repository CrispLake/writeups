#include <stdio.h>

void convert(char *input, int j)
{
    unsigned int char_U = 0x55;
    unsigned int char_3 = 0x33;
    unsigned int num_15 = 0xf;
    char char_a = 'a';

    unsigned int tmp1 = 0;
    unsigned int tmp2 = 0;
    int tmp3 = 0;

    // printf("in: %c |", input[j]);
    for (int i = 0; i < 3; i = i + 1) {
        // for (j = 0; j < pass_len; j = j + 1) {
        tmp1 = (j % 0xff >> 1 & char_U) + (j % 0xff & char_U);
        tmp2 = ((int)tmp1 >> 2 & char_3) + (char_3 & tmp1);
        tmp3 = ((int)tmp2 >> 4 & num_15) + ((int)input[j] - (int)char_a) + (num_15 & tmp2);
        input[j] = char_a + (char)tmp3 + (char)(tmp3 / 0x1a) * -0x1a;
        // printf("mod %i: %c |", i, input[j]);
        // }
    }
    // printf("\n");
}

int main()
{
    char pass[] = "kgxmwpbpuqtorzapjhfmebmccvwycyvewpxiheifvnuqsrgexl";
    int len = 50;

    char input[] = "kgxmwpbpuqtorzapjhfmebmccvwycyvewpxiheifvnuqsrgexl";
    char newpass[] = "kgxmwpbpuqtorzapjhfmebmccvwycyvewpxiheifvnuqsrgexl";

    for (int i = 0; i < len; i++)
    {
        for (int j = 30; j < 255; j++)
        {
            input[i] = j;
            newpass[i] = j;
            convert(input, i);
            if (input[i] == pass[i])
                break;
        }
        if (input[i] != pass[i])
            printf("Something went wrong\n");
    }
    printf("out: %s\n", newpass);

    return 0;
}