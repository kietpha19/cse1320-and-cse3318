#include <stdio.h>
#include <stdlib.h>


int countValueArray(int x[], int count, int value){
    int c =0;
    for(int i=0; i<count;i++){
        if(x[i] == value){
            c++;
        } 
    }
    return c;
}

int main(void){
   int *x;
   x = malloc(4*sizeof(int));
   x[0] = 1;
   x[1] = 5;
   x[2] = 5;
   x[3] = 1;

   int c = countValueArray(x, 4, 5);
   printf("%d\n", c);

   free(x);
    return EXIT_SUCCESS;
}