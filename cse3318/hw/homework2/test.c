#include <stdio.h>
#include <math.h>

int main(){
    int a = 2147483646;
    int b = 2147483647;
    int c = -2147483648;
    int d = -2147483647;

    double temp = ((double)a-(double)c)*4/((double)b-(double)c+1);
    int i = (int)temp;
    printf("%d\n", i);
    
    return 0;
}