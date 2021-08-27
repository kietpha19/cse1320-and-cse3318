// Mymath (C99)

#include "mymath.h"

// Returns the minimum value in an array of count entries
// result only defined if count > 0
int min(int x[], int count)
{
    int minimum;
    int i;
    if (count > 0)
    {
        minimum = x[0];
        for (i = 1; i < count; i++)
            if (x[i] < minimum)
                minimum = x[i];
    }
    return minimum;
}

int max(int x[], int count)
{
    int maximum;
    int i;
    if (count > 0)
    {
        maximum = x[0];
        for (i = 1; i < count; i++)
            if (x[i] > maximum)
                maximum = x[i];
    }
    return maximum;
}

// Address of x and y are passed to the function
// Pass by reference
void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

// 0 1 2 3 4 -> count = 5
// i = count - 1 = 4
// 0 1        (j = 0)
//   1 2      (j = 1)
//     2 3    (j = 2)
//        3 4 (j = 3) -> largest at index 4
// i = 3
// 0 1        (j = 0)
//   1 2      (j = 1)
//     2 3    (j = 2) -> 2nd largest at index 3
// i = 2
// 0 1        (j = 0)
//   1 2      (j = 1) -> 3rd largest at index 2
// i = 1
// 0 1        (j = 0) -> 4th largest at index 1, smallest at index 0

// Bubble sort
void sort(int x[], int count)
{
    int i, j;
    for (i = count - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (x[j] > x[j+1])
                swap(&x[j], &x[j+1]);
        }
    }
}

