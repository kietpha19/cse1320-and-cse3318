#include <stdlib.h>
#include <stdio.h>

// Integer range is [0, 9 999 999]
void integerToDecimalString(int x, char str[])
{
    int weight = 1000000;
    int digit;
    int i = 0;
    while (weight > 0)
    {
        digit = x / weight;
        x -= digit * weight;
        str[i++] = '0' + digit;
        weight /= 10;
    }
    str[i] = '\0';
}

int main(void)
{
    int x = 123;
    char str[8]; // large enough to store string with 7 chars + null
    integerToDecimalString(x, str);
    printf("%d = %s\n", x, str);
    return EXIT_SUCCESS;
}
