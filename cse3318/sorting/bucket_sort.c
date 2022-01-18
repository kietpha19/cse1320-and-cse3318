#include <stdio.h>

tydef struct _Bucket{
    int data;
    struct _Bucket *p;
} Bucket;

void insertion_sort(Bucket *buck){
    if(buck == NULL) return;
    Bucket *sorted_buck = NULL;
    int *trav = buck;
    
    while(trav != NULL){

    }
}

void bucket_sort(int num[], int n){

}

int main(void){

    return 0;
}