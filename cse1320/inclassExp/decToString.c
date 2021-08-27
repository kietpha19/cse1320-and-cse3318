#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_NUM 16
#define VALUE_OF_A 10

//range of x = 0 to 9999999
// pass integer to convert x by value
// pass the string to write the output by reference, the address of str[0]
void integerToDecimalString(int x, char str[])
{
    int weight = 1000000;
    int i = 0;
    int digit;
    while (x > 0)
    {
        digit = x / weight;
        x -= weight * digit;
        str[i++] = '0' + digit; // add the digit to string, then increment the i to go the next block of char array
        weight /= 10;
    }
    str[i] = '\0'; //null terminator
}

int main(void)
{
    int i = 12345;
    char str[8]; //enough to hold max of 9999999 + null
    char deployAirbag;
    integerToDecimalString(i, str);
    printf("%d = %s\n", i, str);
    return EXIT_SUCCESS;
}
