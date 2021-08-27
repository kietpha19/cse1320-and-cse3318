#include <stdlib.h>
#include <stdio.h>

#define COUNT 5

// value of x and y are passed to the dunction
void swapBad(int x, int y){
    int z =x;
    x= y;
    y=z;
    printf("within swapBad: x = %d, y = %d\n", x, y);
}
void swap( int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z; // what if I put &z
    printf("within swap x = %d, y = %d\n", *x, *y);
}

int strLength(const char *str){
    int length =0;
    while (*(str++) != '\0'){
        length++;
    }
    return length;
}


int main(void){

    int x[COUNT] = {1,2,3,4,5};
    int i;
    char str[] = "Hello";
    int a,b,c;
    int *pa, *pb, *pc;

    int xx, yy;

    // %u is for unsigned interger
    // %p is for the address of something

    printf("sizeof(char) = %d\n", (unsigned int)(sizeof(char)));
    printf("sizeof(short) = %u\n", (unsigned int)(sizeof(short)));
    printf("sizeof(int) = %u\n", (unsigned int)(sizeof(int)));
    printf("sizeof(long) = %u\n", (unsigned int)(sizeof(long)));

    printf("sizeof(x) = %u\n", (unsigned int)(sizeof(x))); //20


    printf("x[0] = %d, &x[0] = %p\n", x[0], &x[0]);


    for(i =0; i <COUNT; i++){
            printf("x[%d] = %d, &x[0] = %p\n",i, x[i], &x[i]); // different by 4

    }

    printf("sizeof(char) = %d\n", (unsigned int)(sizeof(char)));
    printf("sizeof(str) = %d\n", (unsigned int)(sizeof(str)));

    for (i=0; i < sizeof(str); i++){
        printf("str[%d] = %d = %c, &str[%d] = %p\n", i, str[i], str[i], i, &str[i]);
    }
    printf ("&a = %p\n", &a);
    printf ("&b = %p\n", &b);
    printf ("&c = %p\n", &c);


    a =1;
    b= 2;
    c = a+b;
    printf("c = a + b = %d\n", c);
    pa = &a; pb = &b; pc = &c;

    //printf("*pc = %p\n", *pc);

    xx =12;
    yy =13;
    printf("within main, before call: xx = %d, yy = %d\n", xx, yy);
    swapBad(xx, yy);
    printf("within main, after call: xx = %d, yy = %d\n", xx, yy);




    return EXIT_SUCCESS;
}