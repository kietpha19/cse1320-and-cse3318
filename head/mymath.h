// Mymath (C99)

#ifndef _MYMATH_H_

#define _MYMATH_H_

//#include "mymath.h"
// Returns the minimum value in an array of count entries
// result only defined if count > 0
int min(int x[], int count);

// Returns the maximum value in an array of count entries
// result only defined if count > 0
int max(int x[], int count);

// Address of x and y are passed to the function
// Pass by reference
void swap(int *x, int *y);

// Bubble sort
void sort(int x[], int count);

#endif

// this code includes and include guard that ensures that the min and
// max functions are only declared once

