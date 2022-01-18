#include <stdio.h>
#include <stdlib.h>

void insert_sort(int *num, int length){
    for(int i=1;i<length;i++){
        int key = num[i];
        int j=i-1;
        while(j>=0 && num[j]>key){
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = key;
    }
}

//this sort is for sorting for the small number first. 
void selection_sort(int *num, int length){
    for(int i=0;i<length;i++){
        for(int j = i; j < length; j++){
            if(num[j] < num[i]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}

void bubble_sort(int *num, int length){
    /* int n = length;
    while(n >0){
        for(int i =0; i < n-1; i++){
            if(num[i+1] < num[i]){
                int temp = num[i];
                num[i] = num [i+1];
                num[i+1] = temp;
            }
        }
        n--; 
    }  */
    
    if(length == 1) return;

    for(int i =0; i < length-1; i++){
            if(num[i+1] < num[i]){
                int temp = num[i];
                num[i] = num [i+1];
                num[i+1] = temp;
            }
        }

    bubble_sort(num, length-1);
}

int main(void){
    int num[8] = {5,8,7,5,2,1,12,9};
    int num1[5] = {7,3,9,5,1};
    int num2[10] = {6,4,7,6,10,7,24,19,11,22};
    insert_sort(num, 8);
    //selection_sort(num, 8);
    //selection_sort(num1, 5);
    bubble_sort(num2, 10);
    for(int i =0; i<8; i++){
        printf("%d\t", num[i]);
    }
    printf("\n");
    for(int i =0; i< 5; i++){
        printf("%d\t", num1[i]);
    }
    printf("\n");
    for(int i =0; i< 10; i++){
        printf("%d\t", num2[i]);
    }

    return EXIT_SUCCESS;
}