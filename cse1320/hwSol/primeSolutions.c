#include <stdio.h>

int main()
{
    int n = 25, number = 3, count, c;

    printf("Printing first 25 prime numbers: \n");
    printf("2\n");
    for (count = 2; count <= n ;)
    {
        for (c = 2; c <= number - 1; c++)
        {
            if (number % c == 0)
                break;
        }
        if (c == number)
        {
            printf("%d\n", number);
            count++;
        }
        number++;
    }
    return 0;
}