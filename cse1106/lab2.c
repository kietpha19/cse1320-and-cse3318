#include <stdio.h>

int main(void){
int c = 1;
while(c == 1){
    int a,b;
    printf("please enter two integer (0 or 1)\n");
    printf("A = ");
    scanf("%d",&a);
    printf("B= ");
    scanf("%d", &b);
    printf("\n");
    printf("A && B = %d\n", a && b);
    printf("A || B = %d\n", a || b);
    printf("!(A || B) =  %d\n", !(a||b));

    printf("do you want to keep going 1:yes or 0:no\n");
    scanf("%d", &c);
}


return 0;
}