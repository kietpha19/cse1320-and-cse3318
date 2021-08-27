#include <stdio.h>
#include <stdlib.h>



int sumDigit(int x){
    if(x<10){
        return x;
    }else{
        return x%10 + sumDigit(x/10);
    }

}

int main(void){
    int sum = sumDigit(19846746);
    printf("%d\t", sum);

    return EXIT_SUCCESS;
}