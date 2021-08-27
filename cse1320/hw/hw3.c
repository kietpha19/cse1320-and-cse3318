#include<stdio.h>
#include<stdlib.h>

int main(void){
    float x[10] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    float* p = &x[4];
    float* p2 = p +2;
    printf("%p\n", x);

    printf("%p\n", &x[9]);

    printf("%lu\n",sizeof(float)); // could use %d but need (int)
    printf("%lu\n", sizeof(x));

    printf("%p\n", &x[5]);

    return EXIT_SUCCESS;
}