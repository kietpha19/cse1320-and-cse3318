#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fix(char str[]){
    strcpy(str, "kiet");
    //str[0] = 'k';
}

void fix1(char **str){
    *str = "kiet";
}

void fixNum(int **n){
    **n = 5; 
    *n[1] = 7;
}

int main(void){
    char str[5];
    fix(str);
    printf("%s\n", str);

    /* char str1[5];
    fix1();
    printf("%s\n",str1); */

    int *n;
    n = malloc(2*sizeof(int));
    fixNum(&n);
    printf("%d\n", *n);

    return EXIT_SUCCESS;
}