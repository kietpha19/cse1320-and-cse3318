#include <stdio.h>
#include <stdlib.h>

void addValueToArray(int **x, int *count, int index, int value){
    if(index >= *count){
        *x = realloc(*x, (index+1)*sizeof(int));
        (*x)[index] = value;
        (*count)++;
    }else{
        *x = realloc(*x, ((*count)+1)*sizeof(int));
        for(int i = *count; i>index;i--){
            (*x)[i] = (*x)[i-1];
        }
        (*x)[index] = value;
        (*count)++;
    }
}
void test(int **x, int *count, int index, int value){
    (*x)[index] = value;
}

void deleteValueFromArray( int **x, int *count, int value){
    for(int i =0; i<*count; i++){
        if((*x)[i] == value){
            for(int j = i; j<*count;j++){
                (*x)[j] = (*x)[j+1];
            }
            //free((*x)[*count]);
            (*count)--;
            *x = realloc(*x, (*count) * sizeof(int));
            break;
        }
    }
}

int main(void){
    int *x;
    int count = 4;
   x = malloc(4*sizeof(int));
   x[0] = 1;
   x[1] = 5;
   x[2] = 6;
   x[3] = 1;

   printf("original array\n");

   for(int i=0; i<count; i++){
        printf("%d\n", x[i]);
    }
   addValueToArray(&x, &count, 2,9);
    //test(&x, &count, 2,9);
    printf("insert 9 to index 2\n");
for(int i=0; i<count; i++){
        printf("%d\n", x[i]);
    }
    printf("delete 5\n");
    deleteValueFromArray(&x, &count, 5);

    for(int i=0; i<count; i++){
        printf("%d\n", x[i]);
    }       
   printf("%d\n",x[count+1]);
   free(x);

    return EXIT_SUCCESS;
}