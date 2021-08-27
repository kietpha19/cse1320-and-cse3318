#include <stdlib.h>
#include <stdio.h>

int sum10(int x[10]){
    int i;
    int sum =0;
    for(i =0; i<10; i++){
        sum += x[i];
    }
    return sum;
}


int main(void){

    int x[10] = {10,20,30,40,50,60,70,80,90,100};
    int sum = sum10(x);

    
    printf("sum of array x elements is: %d\n", sum);
    

    return EXIT_SUCCESS;
}
