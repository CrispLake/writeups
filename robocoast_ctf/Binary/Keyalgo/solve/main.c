#include <stdio.h>
#include <string.h>

void FUN_001011e9(char *param_1,char *param_2)
{
  size_t sVar1;
  size_t sVar2;
  int local_c;
  
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_2);
  for (local_c = 0; local_c < (int)sVar1; local_c = local_c + 1) {
    for (char c = 0; c < 127; c++)
    {
        char tmp = c;
        tmp = param_2[local_c % (int)sVar2] + tmp + -0x41;
        if (param_1[local_c] == tmp)
        {
            printf("%c", c);
            break;
        }
    }
  }
  printf("\n");
  return;
}

int main()
{
    char *output = "tHisi5aflA9takei7";
    char *key = "NOTAFLAGJUSTAKEY";

    FUN_001011e9(output, key);
    return 0;
}