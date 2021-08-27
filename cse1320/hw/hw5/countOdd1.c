#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80
#define MAX_ODD_NUMS 20

unsigned int countOdd(const char fileName[])
{
    int number = 0;
    int count = 0;
    FILE *input ;
    input = fopen(fileName, "r");

    while (!feof(input))
    {
        if (input == NULL)
        {
            printf("ERROR: The input file %s does not exist:\n", fileName);
        }
        else
        {
            fscanf(input, "%d", &number);w
            if (number % 2 != 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("passing arguments incorrectly!!\n");
        printf("usage: fileExe filename\n");
        exit(EXIT_FAILURE);
    }
    unsigned int numOfOdd = countOdd(argv[1]);
    printf("there are %d odd numbers in file %s\n", numOfOdd, argv[1]);
}