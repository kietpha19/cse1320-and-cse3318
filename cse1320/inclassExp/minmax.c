#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define COUNT 6

int min(int x[], unsigned int count){
    int minimun;
    return minimun;
}

int max(int x[],unsigned int count){
    int maximun;
    return maximun;
}

int main(void){
int x[COUNT] = {34,52,-9,19,33};

int minimum = min(x, COUNT);
int maximum = max(x, COUNT);

printf("minimun = %d\n", minimum);
printf("maximun = %d\n", maximum);


return EXIT_SUCCESS;

}