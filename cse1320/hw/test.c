#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char str[20] = "kiet";
    char str1[] = "kiet";
    char str2[] = "t";

   // int i = strcspn(str, "\t");
    int temp = strcmp(str, str1);
  //  printf("%d\n",i);
    printf("%d\n", temp);

     
    return 0;
}