#include <stdlib.h>
#include <stdio.h>

#define COUNT 10

// int x = 10;  integer with value of 10
// int *p;      pointer to an integer (uninitialized)
// p = &x;      pointer to x (address of the variable x)
// int y;       integer uninitialized
// y = *p;      read address p (add of x), get value (value of x)
//              store the value in y
// int z;
// z = *(&x);   z = x; (reference with &, the deference with *)

/*
// Method 1
// Address of x[0] is passed to the function (pass by reference)
// Intent is clear... pointer to an array of 10 integers is passed
int sum10(int x[10])
{
    int i;
    int total = 0;
    printf("x = %p, *x = %d\n", x, *x);
    for (i = 0; i < 10; i++)
        total += x[i];
    return total;
}

// Method 2
// Address of x[0] is passed to the function (pass by reference)
// Not clear that this function needs an array of 10 integers
int sum10(int *x)
{
    int i;
    int total = 0;
    printf("x = %p, *x = %d\n", x, *x);
    for (i = 0; i < 10; i++)
        total += x[i];
    return total;
}
*/

/*
// Method 1
// Address of x[0] is passed to the function (pass by reference)
// Intent is clear... pointer to an array of integers is passed
int sum(int x[], int count)
{
    int i;
    int total = 0;
    printf("x = %p, *x = %d\n", x, *x);
    for (i = 0; i < count; i++)
        total += x[i];
    return total;
}

// Method 2
// Address of x[0] is passed to the function (pass by reference)
// Not clear that this require an array of integers and not a single integer
int sum(int *x, int count)
{
    int i;
    int total = 0;
    printf("x = %p, *x = %d\n", x, *x);
    for (i = 0; i < count; i++)
        total += x[i];
    return total;
}

// Method 3
// Address of x[0] is passed to the function (pass by reference)
int sum(int *x, int count)
{
    int i;
    int total = 0;
    for (i = 0; i < count; i++)
    {
        printf("x = %p, *x = %d\n", x, *x);
        total = total + *x; // deference x to get next value in array
        x++; // move the pointer to the next entry in the array
             // address increments by sizeof(int)
    }
    return total;
}
*/

// Method 4
// Address of x[0] is passed to the function (pass by reference)
int sum(int *x, int count)
{
    int i;
    int total = 0;
    for (i = 0; i < count; i++)
    {
        printf("x = %p, *x = %d\n", x, *x);
        total += *(x++); // add *x (dereferences pointer -- an integer) to the total
                         // increment pointer by sizeof(int)
    }
    return total;
}

int main(void)
{
    int x[COUNT] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i;
    int total;

    printf("sizeof(int) = %d\n", (int) sizeof(int));

    for (i = 0; i < COUNT; i++)
        printf("x[%d] = %d, &x[%d] = %p\n", i, x[i], i, &x[i]);

    total = sum(x, COUNT);
    printf("sum of x is %d\n", total);

    return EXIT_SUCCESS;
}
