#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *p;
};
typedef struct node NODE;

struct list{
    NODE *head;
    NODE *last;
};
typedef struct list LIST;

void createList(LIST *l){
    l->head = NULL;
    l->last = NULL;
}

int main(void){
    


    return EXIT_SUCCESS;
}