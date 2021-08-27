#include <stdio.h>
#include <stdlib.h>

#define N 5

struct Puzzel{
    int A[N];
    int B[N];
    int C[N];
};
typedef struct Puzzel puzzel;


 void move(int x[], int y[]){
     int i =0;
     while(x[i] != 0){
         i++;
     }
      if(i != 0){
         i-=1;
     }else{
         return; 
     }
     int j=0;
     while(y[j] != 0){
         j++;
     }

     y[j] = x[i];
     x[i] = 0;
 }

void printPuzzel(int a[],int b[],int c[]){
    for(int i = N-1;i >= 0;i--){
        printf("%d\t%d\t%d\t", a[i], b[i], c[i]);
        printf("\n");
    }
    printf("\n");
}

void towerOfHanoi(int a[], int b[], int c[], int n){
    if(n==1){
        move(a,c);
        printPuzzel(a,b,c);
        return;
    }
    towerOfHanoi(a,c,b,n-1);
    move(a,c);   
    printPuzzel(a,b,c);
    towerOfHanoi(b,a,c,n-1);
    

}


int main(void){

    int A[N] = {5,4,3,2,1};
    int B[N];
    int C[N]; 
    
    move(A,C);
    printPuzzel(A, B, C);
   /*  move(A,B);
    printPuzzel(A, B, C);
    move(C,B);
    printPuzzel(A, B, C);
    move(A,C);
    printPuzzel(A, B, C); */
    
   // towerOfHanoi(A,B,C,N);
    //printPuzzel(A,B,C);


    return EXIT_SUCCESS;
}