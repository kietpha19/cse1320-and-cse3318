#include <stdio.h>

#define RANGE 10 // if our mumber is in the inter val [0,10] then the range should be 10+1 

//eficcient when there are a lot of duplicate objects
void count_sort(int num[], int length){
    int count[RANGE];
    int output[length];

    //important to initialize the count array
    for(int i =0; i<RANGE; i++){
        count[i] =0;
    }

    //counting
    for(int i =0; i<length;i++){
        count[num[i]] +=1;
        //++count[num[i]]; //increase then assign
    }

    //cumulative
    for(int i =1; i<RANGE;i++){
        count[i] += count[i-1];
    }

    //sort
    for(int i = length-1; i >= 0; i--){
        output[--count[num[i]]] = num[i]; 
        //--count[num[i]];
    }

    //copy
    for(int i = 0; i<length; i++){
        num[i] = output[i];
    }
}

int main(void){
    int num[12] = {2,1,2,7,3,1,2,5,6,5,9,7};
    count_sort(num, 12);

    for(int i =0; i < 12; i++){
        printf("%d\t", num[i]);
    }
    return 0;
}