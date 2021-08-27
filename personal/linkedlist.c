#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *p;
};

void printList(struct node *node){
    while( node != NULL){
        printf("%d\t", node->num);
        node = node->p;
    }
}


/* have to pass the pointer to the function by reference, which mean pass a pointer to the head pointer.
that way, the function will working on the head pointer in heap.
if only pass the pointer by value, then the function make a copy a the head pointer in stack and works with it.
later on, the OS delete the copy of head.
that's is not correct becasue we want our real head in heap to change, which mean we want head to point to the new node
*/
/*the purpose of pass the head pointer by reference is to check whether the list is empty or not
and also, we could be able to make the head pointer point to the newnode
*/
void push(struct node **head_ref, int n){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->num = n; 
    new_node->p = *head_ref;

    *head_ref = new_node;
}

/*
in this function, we pass the head pointer by reference only to check whether the list is empty
and in case the list is empty, we could use the same algorithm as push() function. 
otherwise, we make a copy of head pointer by using the head_ref dereference, then use that copy to traverse the list. 
*/
void append(struct node **head_ref, int n){
    //could use return function inside the if so that we don't have to use else
    if(*head_ref == NULL){
        push(head_ref, n);
    }
    else{
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->num = n;
        new_node->p = NULL;

        struct node *trav = *head_ref;
        while(trav->p != NULL){
            trav = trav->p;
        }

        trav->p = new_node;
    }
}

void insertPrev(struct node **head_ref, int prev_num, int n){
    if(*head_ref == NULL){
        printf("the list is empty, so we just insert the number %d to the beginning of the list\n", n);
        push(head_ref, n);
        return;
    } 

    struct node *trav = *head_ref;
    while(trav->num != prev_num && trav->p != NULL){
        trav = trav->p;
    }
    
    if(trav->p == NULL && trav->num != prev_num){
        printf("the is no previous number %d in the list\n", prev_num);
        return;
    } 
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->num = n;
    new_node->p = trav->p;
    trav->p = new_node;
    return;
}

// didn't not work corectly for the case when the num located at the head.


void deleteNum(struct node **head_ref, int n){
    if(*head_ref == NULL){
        printf("the list is empty!! nothing to delete!!\n");
        return;
    }

    struct node *trav = *head_ref;
    while(trav->p->num != n && trav->p->p != NULL){
        trav = trav->p;
    }

    if(trav->p->num == n){
        free(trav->p);
        trav->p = trav->p->p;
        return;
    } else {
        printf("the is no number %d in the list to delete\n", n);
        return;
    }
}
int listLen(struct node *trav){
    if(trav == NULL){
        return 0;
    }
    int len =0;
    while(trav != NULL){
        trav = trav->p;
        len++;
    }
    return len;
}

void deleteIndex(struct node **head_ref, int index){
    if(*head_ref == NULL){
        printf("the list is empty!! nothing to delete at index %d!!\n", index);
        return;
    }
    
    int len = listLen(*head_ref);
    if(index >= len){
        printf("the index is greater than the list length which is %d\n", len);
        return;
    }
    struct node *trav = *head_ref;
    if(index == 0){
        trav = trav->p; 
        free(*head_ref);
        *head_ref = trav;
        return;
    }
    if(index == len-1){
        while(trav->p->p != NULL){
            trav = trav->p;
        }
       free(trav->p);
       trav->p = NULL;
       return;
    }
    int i =0;
    while(i < index-1){
        trav = trav->p;
        i++;
    }
    struct node *del_note = trav->p;
    trav->p = trav->p->p;
    free(del_note);
    return;

}

void insertIndex(struct node **head_ref, int n){

    
}

/* the reason that we dont put the pointer head outside main 
first of all we don't want any random function could have acess to it easily
morever, we could have different linked list in a programm. in that case, 
we may have like head1, head2, head3, 
and we want our function to be able to work with all those linked list with whichever list we pass to the function.
*/

int main(void){
    
    struct node *headNode = NULL;

    push(&headNode, 8); // 8
    push(&headNode, 4); // 4 8
    append(&headNode, 9); // 4 8 9
    insertPrev(&headNode, 4, 3); //4 3 8 9
    insertPrev(&headNode, 3, 7); // 4 3 7 8 9

    append(&headNode, 12); // 4 3 7 8 9 12
    push(&headNode, 19); // 19 4 3 7 8 9 12

    deleteNum(&headNode, 3); // 19 4 7 8 9 12
    deleteIndex(&headNode, 4); // 19 4 7 8 12

    deleteIndex(&headNode, 0); //4 7 8 12
    deleteIndex(&headNode, 3); // 4 7 8
    deleteNum(&headNode, 7); // 4 8
    deleteIndex(&headNode, 1); //4
    deleteIndex(&headNode, 1); // 4
    deleteIndex(&headNode, 0); // empty

    insertPrev(&headNode, 7,9); // 9

    int len = listLen(headNode);
    printf("the list length is %d\n", len);

    printList(headNode);
    
    printf("\n\n");
    struct node *head1 = NULL;
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    printList(head1);
    printf("\n");
    deleteNum(&head1,4);
    printList(head1);



    return EXIT_SUCCESS;
}