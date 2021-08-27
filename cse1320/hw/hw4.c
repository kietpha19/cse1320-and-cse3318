#include <stdio.h>
#include <stdlib.h>

unsigned int timesPowerOf2(unsigned int x, unsigned int p){
    if(p==0){
        return x;
    }
    return 2*timesPowerOf2(x,p-1);
    
}

int main(void){
    unsigned result = timesPowerOf2(4,18);
    printf("%d\n", result);

    return EXIT_SUCCESS;
}