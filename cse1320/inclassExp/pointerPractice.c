#include <stdio.h>
#include <stdlib.h>


/*
if assign integer to pointer use & because we actually assigned that integer's address to the pointer
if assign pointer to integer use * becasue we tell the integer to follow that pointer and copy that content
if assign pointer to pointer use * both side.
*/

void swap (int *xx, int *yy){
    int temp = *xx;
    *xx = *yy;
   // yy = &temp; // check if *yy = temp; this logic is wrong in term of swaping numbers
   // supposed to be
   *yy = temp; //  the content of pointer yy is point to y, so you are telling the content of pointer yy to equal temp
}

int main(void){

    int x = 4;
    int y;
    int *p;
    
   // *p = x; wrong
     
     // p = 4 ; this does not work
    
   p = &x; // tell the pointer to point to an address
   //*p = x; this one doesn't work
    printf("%d\n", *p);

     y = *p;
    printf("%d\n", y);
    
    printf("\n");

    int c = 1;
    int d = 3;
    int *pC; // = &c;
    int *pD = &d;
    pC = &c;
    
    swap(pC, pD);
    printf("%d\n", c);
    printf("%d\n",d);

    printf("\n\n");
    int num = 19;
    int *pointer = &num;
    printf("%d\n", *pointer);
    //printf("%d\n", *pC);


    return EXIT_SUCCESS;
}