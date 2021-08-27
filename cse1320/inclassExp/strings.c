#include <stdlib.h>  // EXIT_ codes
#include <stdio.h>   // printf
#include <string.h>  // strlen
#include <ctype.h>   // toupper

#define VALUE_OF_A 10
#define WEIGHT_OF_NIBBLE 16
// Function to replicate strlen() function
int strLength(const char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

// Convert a hex string to integer
// Valid characters are 0-9, A-F, and a-f; no error checking
unsigned int hexStringToInteger(const char str[])
{
    unsigned int sum = 0;
    unsigned int weight = 1;
    int i = strlen(str) - 1;
    char c;
    while (i >= 0)
    {
        c = toupper(str[i]);
        if (c >= '0' && c <= '9')
            sum += weight * (c - '0');
        else if (c >= 'A' && c <= 'F')
            sum += weight * (c - 'A' + VALUE_OF_A);
        weight *= WEIGHT_OF_NIBBLE;
        i--;
    }
    return sum;
}

int main(void)
{
    char str[] = "Hello world";
    char str2[] = "1FFF";
    char str3[] = "ffff";
    int length;
    unsigned int value;
    length = strLength(str);
    printf("Length of string \"%s\" is %d\n", str, length);
    value = hexStringToInteger(str2);
    printf("Value of hex string \"%s\" is %u\n", str2, value);
    value = hexStringToInteger(str3);
    printf("Value of hex string \"%s\" is %u\n", str3, value);
    return EXIT_SUCCESS;
}
