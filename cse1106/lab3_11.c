#include <stdio.h>
#include <stdbool.h>

int main(void){
    u_int8_t a = 0;
    u_int8_t b = 6;
    u_int8_t lt = 0;
    u_int8_t eq = 0;
    u_int8_t gt = 0;
  
    printf("a\ta==b\ta<b\ta>b");
    printf("\n");
    for(int i =0; i<32; i++){
        lt = a<b;
        eq = a==b;
        gt = a>b;
        printf("%u\t%u\t%u\t%u", a, eq, lt, gt);
        printf("\n");
        a = (a+1)%16;
    }
    return 0;
}