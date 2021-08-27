#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_NUM 16
#define VALUE_OF_A 10

unsigned int hexStringToUnit(const char str[]){
    unsigned int sum =0;
    unsigned weight = 1;
    int i = strlen(str)-1;
    char c;
    while(i >= 0){
        c = str[i];
        if( c >= '0' && c <= '9'){
            sum += weight*(c-'0');
        } else if (c >= 'a' && c <= 'f'){
            sum += weight*(c - 'a' + VALUE_OF_A);
        } else if (c >= 'A' && c <= 'F'){
            sum += weight*(c - 'A' + VALUE_OF_A);
        }
        weight *= HEX_NUM;
        i--;
    }
    return sum;
}



int main(void){
    char str[] = "1fad"; 
    unsigned int value = hexStringToUnit(str);
    printf("%d\n", value);
    return EXIT_SUCCESS;
}
