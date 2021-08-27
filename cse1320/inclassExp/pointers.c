#include <stdlib.h>
#include <stdio.h>

#define COUNT 5

// Bad example:
// x and y are passed as values to function
// x and y are one-way.... function cannot send back values in x and y
void swapBad(int x, int y)
{
    int z;
    printf("At start of swapBad(): x = %d, y = %d\n", x, y);
    z = x;
    x = y;
    y = z;
    printf("At end of swapBad(): x = %d, y = %d\n", x, y);
}

// Good example:
// x and y are passed by reference to function
// Function can read and write from the locations x and y
void swap(int *x, int *y)
{
    int z;
    printf("At start of swap(): x = %d, y = %d\n", *x, *y);
    z = *x;
    *x = *y;
    *y = z;
    printf("At end of swap(): x = %d, y = %d\n", *x, *y);
}

/*
// Method 1
int strLength(const char str[])
{
    int i = 0;
    printf("Add of str[0] is %p\n", &str[0]);
    printf("Add of str is %p\n", str);
    
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

// Method 2
int strLength(const char *str)
{
    int i = 0;
    printf("Add of str[0] is %p\n", &str[0]);
    printf("Add of str is %p\n", str);
    
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

// Method 3
int strLength(const char *str)
{
    int i = 0;
    printf("Add of str[0] is %p\n", &str[0]);
    printf("Add of str is %p\n", str);
    
    while (*str != '\0')
    {
        str++;
        i++;
    }
    return i;
}

// Method 4
int strLength(const char str[])
{
    int i = 0;
    printf("Add of str[0] is %p\n", &str[0]);
    printf("Add of str is %p\n", str);
    
    while (*str != '\0')
    {
        str++;
        i++;
    }
    return i;
}

// Method 5
int strLength(const char *str)
{
    int i = 0;
    printf("Add of str[0] is %p\n", &str[0]);
    printf("Add of str is %p\n", str);
    
    while (*(str+i) != '\0')
    {
        i++;
    }
    return i;
}
*/

// Method 6
int strLength(const char str[])
{
    int i = 0;
    printf("Add of str[0] is %p\n", &str[0]);
    printf("Add of str is %p\n", str);
    
    while (*(str+i) != '\0')
    {
        i++;
    }
    return i;
}

int main(void)
{
    char str[] = "Hello";
    int x[COUNT] = {10, 20, 30, 40, 50};
    int i;
    int *p;
    char* p2;
    int a, b, c;
    
    printf("sizeof(char) in bytes: %u\n", (unsigned int)sizeof(char));
    printf("sizeof(short) in bytes: %u\n", (unsigned int)sizeof(short));
    printf("sizeof(int) in bytes: %u\n", (unsigned int)sizeof(int));
    printf("sizeof(long) in bytes: %u\n", (unsigned int)sizeof(long));

    printf("\n");
    printf("sizeof(char) in bytes: %u\n", (unsigned int)sizeof(char));
    printf("sizeof(str) in bytes: %u\n", (unsigned int)sizeof(str));
    for (i = 0; i < sizeof(str); i++)
    {
        printf("str[%d] = %d = '%c'\t&str[%d] = %p\n", i, str[i], str[i], i, &str[i]);
    }
    p2 = &str[0];
    printf("p2 = &str[0] = %p, *p2 = %d\n", p2, *p2);
    p2++;
    printf("p2++ = %p, *p2 = %d\n", p2, *p2);
    p2+=2;
    printf("p2+=2 = %p, *p2 = %d\n", p2, *p2);

    printf("\n");
    printf("sizeof(int) in bytes: %u\n", (unsigned int)sizeof(int));
    printf("sizeof(x) in bytes: %u\n", (unsigned int)sizeof(x));
    for (i = 0; i < COUNT; i++)
    {
        printf("x[%d] = %d\t&x[%d] = %p\n", i, x[i], i, &x[i]);
    }

    p = &x[0];
    printf("p = &x[0] = %p, *p = %d\n", p, *p);
    p++;
    printf("p++ = %p, *p = %d\n", p, *p);
    p+=2;
    printf("p+=2 = %p, *p = %d\n", p, *p);

    a = 12;
    b = 13;
    printf("Before call to swapBad(): a = %d, b = %d\n", a, b);
    swapBad(a, b);
    printf("After call to swapBad(): a = %d, b = %d\n", a, b);
    
    a = 12;
    b = 13;
    printf("Before call to swap(): a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After call to swap(): a = %d, b = %d\n", a, b);
    
    printf("Length of str = %d\n", strLength(str));
    
    return EXIT_SUCCESS;
}