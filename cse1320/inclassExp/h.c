#include <stdio.h>
 
int main()
{
   int x, y, *a, *b, temp;
 
   int *p ;
   int *p1;
   int k =2;
   int l;
   
   p = &k;
   printf("p: %d\n", *p);
   l = *p; //tell integer l to equal the content of pointer p
   printf("l: %d\n", l);
   *p1 = l; //wrong because pointer p1 have not point to anything, so you can't tell the content of p1 to be equal to anything
   //printf("%d\n", *p1);


   // printf("Enter the value of x and y\n");
   // scanf("%d%d", &x, &y);
   x = 1;
   y = 3;
 
   printf("Before Swapping\nx = %d\ny = %d\n", x, y);
 
   a = &x;
   b = &y;
 
   temp = *b;
   printf("temp: %d\n", temp);
   *b = *a;
   printf("*b: %d\n", *b);
   *a = temp; // tell content of pointer a to equal temp, you can do that because currently pointer a has content which is x
   //a = &temp; // tell pointer a to point to the content or address of temp, and this is a wrong logic

   printf("*a: %d\n", *a);
 
   printf("After Swapping\nx = %d\ny = %d\n", x, y);
 
   return 0;
}