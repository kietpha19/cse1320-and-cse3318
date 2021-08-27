// Minmax (C99)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mymath.h"
//#include "mymath2.h"

#define COUNT 5

int main(void)
{
    int x[COUNT] = {34, 52, -9, 10, 33};
    int minimum = min(x, COUNT);
    int maximum = max(x, COUNT);
   // int minZero = minOrZero(x, COUNT);
    printf("Minimum = %d\n", minimum);
    printf("Maximum = %d\n", maximum);
   // printf("MinZero = %d\n", minZero);
    return EXIT_SUCCESS;
}
