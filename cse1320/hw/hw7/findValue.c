#include <stdio.h>
#include <stdlib.h>

int findValueArray(int x[], int count, int value){
    for(int i=0; i < count; i++){
        if(x[i] == value) return i;
    }
    return -1;
}

int main(void){
   int *x;
   x = malloc(4*sizeof(int));
   x[0] = 1;
   x[1] = 5;
   x[2] = 6;
   x[3] = 1;

   int i = findValueArray(x, 4, 6);
   printf("%d\n", i);

   free(x);
    return EXIT_SUCCESS;
}