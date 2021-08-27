#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool
#include <math.h> //sqrt

#define NUM_PRIME 25

// bool isPrime(int num, int div){
//     if(num <= 1 ){
//         return false;
//     } else if (div ==1 ){
//         return true;
//     } else if(num % div == 0){
//         return false;
//     }
//     return isPrime(num, div-1);
// }


// this one is faster than the one above because it has the same amount of condition but less cases
bool isPrime(int num, int div){
    if(num <= 1){
        return false;
    } else if (div > sqrt(num)){
        return true;
    } else if (num % div == 0){   // if merge this codition with the first 1, then number 2 wasn't counted. therefore incorect
        return false;
    }
    return isPrime(num, div+1);
}



int main(void){
    int count =0;
    int num = 0;


    while (count < NUM_PRIME){
        if(isPrime(num, 2)){
            printf("%d\n", num);
            count ++;
        }
        num++;
   }

    return EXIT_SUCCESS;
}