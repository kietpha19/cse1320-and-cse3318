/*
This program demonstrates 3 possible memory-related errors.
Run it with Valgrind and see
- the error message reported for each case
- the line number that
*/
#include <stdio.h>
#include <stdlib.h>

void no_error();
void pointer_error();
void mem_leak_error();
void cond_jump_error();

int main(void){
    int choice;

    printf("Started...\n");

    printf("This program runs one of the 3 tests below at a time:\n");
    printf(" 0 - no error. \n");
    printf(" 1 - pointer error (invalid memory access)\n");
    printf(" 2 - memory leak\n");
    printf(" 3 - conditional jump depends on unitialized value\n");

    printf("Enter your test choice (0-3): ");
    scanf("%d", &choice);

    if (choice == 0) {
        no_error();
    }
    else if (choice == 1) {
      pointer_error();
    }
    else if (choice == 2){
        mem_leak_error();
    }
    else if (choice == 3) {
        cond_jump_error();
    }
    else {
        printf("Invalid choice.");
    }

    printf("Finished...\n");
    return EXIT_SUCCESS;
}

void no_error(){
    int *p = malloc(sizeof(int));
    *p = 5;
    printf("p = %d\n", *p);
    free(p);

    double *arr = malloc(5 * sizeof(double));
    free(arr);

    int n = 7;
    if (n==0) {
        printf("n is 0\n");
    }
    else {
        printf("n is something else\n");
    }
}

// Writes to a random memory address
void pointer_error(){
    int *p;
    *p = 5;
    printf("p = %d\n", *p);
}

// allocates memory, but never frees it.
void mem_leak_error(){
    int filler = 0;
    //int *p = malloc(sizeof(int));
    double *arr = malloc(5 * sizeof(double));
    char another_filler = 'a';
}

// code to be executed depends on teh uninitialized variable n.
void cond_jump_error(){
    int n;
    if (n==0) {
        printf("n is 0\n");
    }
    else {
        printf("n is something else\n");
    }
}
