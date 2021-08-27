#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define NUM_PRIME 25

bool isPrime(int num, int div){
    if(num <= 1){
        return false;
    } else if (div > sqrt(num)){
        return true;
    } else if( num % div == 0){
        return false;
    }
    return isPrime(num, div +1);
}

int main(void){
    int count =0;
    int num =0;
    while(count < NUM_PRIME){
        if(isPrime(num,2)){
            printf("%d\n", num);
            count ++;
        }
        num++;
    }

    return EXIT_SUCCESS;
}

