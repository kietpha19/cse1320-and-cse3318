#include <stdio.h>
#include <stdlib.h>

struct stack_array{
    int *stack; 
    int top;
};

struct stack_array newStack(){
    struct stack_array res;
    res.stack = NULL;
    res.top = -1;
    return res;
}

void push(struct stack_array *S, int num){
    int i = ++S->top;
    S->stack = (int*)realloc(S->stack, (i+1)*sizeof(int));
    S->stack[i] = num;
}

int pop(struct stack_array *S){
    int i = S->top--;
    int num = S->stack[i];
    //if(i == 0){
       // S->stack = (char*)realloc(S->stack, 0);
   // }else{
        S->stack = (int*)realloc(S->stack, (i+1)*sizeof(int));
    //}
    return num;
}

int main(){
    int *nums = (int*)calloc(3, sizeof(int));
    nums[0] = 0;
    nums[1] = 1;
    nums[2] = 2;
    printf("%d\n", nums[2]);

    int s = sizeof(s)/sizeof(int);
    printf("%d\n", s);
    return 0;
}