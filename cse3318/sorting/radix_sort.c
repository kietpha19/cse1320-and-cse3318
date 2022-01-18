#include <stdio.h>

int get_max(int nums[], int n){
    int max = nums[0];
    for(int i =1; i < n; i++){
        if(nums[i] > max) max = nums[i];
    }
    return max;
}

void count_sort(int nums[], int n, int exp){
    int count[10]; // the digit can only be from 0 to 9
    int output[n];
    
    //initial
    for(int i =0; i < 10; i++){
        count[i] = 0;
    }

    //counting
    for(int i = 0; i<n; i++){
        int count_index = nums[i] / exp % 10; //first get rid of the tail, then get the number of that digit
        count[count_index]+=1;
    }

    //cumulative
    for(int i =1; i< 10; i++){
        count[i] += count[i-1];
    }

    //sort
    for(int i= n-1; i >= 0; i--){ //very important, i has to be equal to 0
        int count_index = nums[i] / exp % 10;
        int output_index = --count[count_index]; //make sure in decrease the count_index before assign it to the output array 
                                                //because when calculate the cumulative sum, we not considering the 0 index
        output[output_index] = nums[i];
        //count[count_index]--; //do this when output_index = count[count_index] -1
    }

    //copy
    for(int i =0; i<n; i++){
       nums[i] = output[i];
    }
}

void radix_sort(int nums[], int n){
    int max = get_max(nums, n);

    for(int exp = 1; max/exp > 0; exp *=10){
        count_sort(nums, n, exp);
    }
}

int main(void){
    int nums[12] = {54,12,9,23,91,67,35,16,43,37,82,71};
    radix_sort(nums, 12);

    for(int i=0; i<12; i++){
        printf("%d\t", nums[i]);
    }
    return 0;
}