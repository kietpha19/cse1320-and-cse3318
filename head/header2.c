#include <stdio.h>
#include <stdlib.h>
#include "kiet.h"
#include "thuong.h"

int main(void){
    int s = sum(5,6);
    printf("%d\n", s);

    int s1 = sumN1(1,2);
    printf("%d\n", s1);

    return EXIT_SUCCESS;
}