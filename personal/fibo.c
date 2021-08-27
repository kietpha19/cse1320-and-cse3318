#include <stdio.h>
#include <stdlib.h>

int fibo(int num){
    if(num == 1 || num == 2){
        return 1;
    }
    return fibo(num-1) + fibo(num-2);
}

int main(void){
    int result = fibo(13);
    printf("%d\n", result);
    return EXIT_SUCCESS;
}