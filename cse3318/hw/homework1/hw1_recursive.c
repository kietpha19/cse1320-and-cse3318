#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void runtime_rec(int N, char * str){
 if (N==0) return;
 str[N-1] = 'L';
 runtime_rec(N-1, str);
 str[N-1] = 'R';
 runtime_rec(N-1, str);
}
int main(int argc, char** argv) {
 int N = 0;
 char ch;
 char str[100];
 printf("run for: N = ");
 scanf("%d", &N);
 str[N] = '\0'; //to use it as a string of length N.
 printf("runtime_rec(%d)\n", N);
 runtime_rec(N, str);
}