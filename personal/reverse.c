#include <stdio.h>
#include <stdlib.h>

void reverse(int l[], int i, int j){
    
    if(j-i < 1){
        return;
    }
    int z = l[i];
    l[i] = l[j];
    l[j] = z;
    reverse(l, i+1, j-1);
}

int main(void){
    int L[10] = {1,2,3,4,5,6,7,8,9,10};
    reverse(L, 0, 9);

    for(int i =0; i< 10; i++){
        printf("%d\t", L[i]);
    }


    return EXIT_SUCCESS;
}