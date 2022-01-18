#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("hello world!\n");
    int *nums;
    nums = malloc(1*sizeof(int));
    nums[0] = 7;
    printf("%d\n", nums[0]);
    free(nums);
    printf("finish........!\n");
    return EXIT_SUCCESS;
}