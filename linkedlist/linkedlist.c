#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int data;
    struct _Node *next;
} Node;

Node* new_list(){
    Node *phead = NULL;
    return phead;
}

void printList(Node *phead){
    if(phead == NULL){
        printf("the list is empty\n");
    }
    Node *ptrav = phead;
    while(ptrav != NULL){
        printf("%d\t", ptrav->data);
        ptrav = ptrav->next;
    }
    printf("\n");
}

Node* push_return(Node *pHead, int data){
    Node *pNode = malloc(1*sizeof(Node));
    pNode->data = data;
    pNode->next = pHead;
    return pNode;
}

void push(Node **ppHead, int data){
    Node *pNode = malloc(1*sizeof(Node));
    pNode->data = data;
    pNode->next = *ppHead;
    *ppHead = pNode;
}

void addNodeAtEnd(Node** head, int value){
   
    if(*head == NULL){
        Node *pNode = malloc(1*sizeof(Node));
        pNode->data = value;
        pNode->next = NULL;
        *head = pNode;
        return;
    }
    Node *trav = *head;
    while(trav->next != NULL){
        trav = trav->next;
    }
    Node *pNode = malloc(1*sizeof(Node));
    pNode->data = value;
    pNode->next = NULL;
    trav->next = pNode;
}

 int countNodes(Node** head){
     int count = 0;
     if(*head == NULL){
         return count;
     }
     Node *trav = *head;
     while(trav != NULL){
         trav = trav->next;
         count++;
     }
     return count;
 }

  int countValue(Node** head, int value){
      int count = 0;
      if(*head == NULL){
          return count;
      }
      Node *trav = *head;
      while(trav != NULL){
          if(trav->data == value){
              count++;
          }
          trav = trav->next;
      }
      return count;
  }

  void printEndToHead (Node** head){
      if(*head == NULL){
          printf("there is no data\n");
          return;
      }
      
      Node *trav = *head;
      //the case when the list only have 1 element
      if(trav->next == NULL){
          printf("%d\n",trav->data);
          return;
      }
      int count =0;
      int *data = malloc(1 * sizeof(int));
    
      if(data == NULL){
          printf("out of memory!\n");
          return;
      }
      printf("print from end to head\n");
      while(trav != NULL){
          data[count++] = trav->data;
         // printf("%d\n", count);
          data = realloc(data, (count+1) * sizeof(int));
          trav = trav->next;
      }
      for(int i = count-1; i >=0; i--){
          printf("%d\t", data[i]);
      }
      printf("\n");
    free(data);
  }

  void insertAtIndex(Node **head,int value, int index){
      if(*head == NULL || index == 0){
          if(*head==NULL && index != 0){
              printf("the list is empty, you can only insert data at index 0!\n");
              return;
          }
          Node *pnode = malloc(1*sizeof(Node));
          pnode->data = value;
          pnode->next = *head;
          *head = pnode;
          return;
      }
      // could use trav->next->next
      Node *preTrav = *head;
      //Node *trav = (*head)->next;
      int i =0;
      while(preTrav->next != NULL && i != index-1){
          //preTrav = trav; 
          //trav = trav->next;
          preTrav = preTrav->next;
          i++;
      }
      if(i == index-1 ){
          Node *pnode = malloc(1*sizeof(Node));
          pnode->data = value;
          pnode->next = preTrav->next;
          preTrav->next = pnode;
          return;
      }
    printf("the index want to insert is out of the length of the list\n");
  }

  void deleteAtIndex(Node **head, int index){
      if(*head == NULL){
          printf("there is nothing to delete!\n");
          return;
      }
      Node *trav = *head;
      if(index == 0){
          *head = trav->next;
          free(trav);
          return;
      }
      int i =0;
      while(trav->next != NULL && i != index -1){
          trav = trav->next;
          i++;
      }
      if( i == index-1 && trav->next != NULL){
         // printf("run\n");
          Node *temp = trav->next;
          trav->next = temp->next;
          free(temp);
          return;
      }
      printf("the index want to delete is out of the length of the list\n");
  }

  void deleteData(Node **head, int num){
      if(*head == NULL){
          printf("there is nothing to delete!\n");
          return;
      }
      Node *trav = *head;
      //the case when the list only has 1 element
      if(trav->data == num){
          *head = trav->next;
          free(trav);
          return;
      }
      if(trav->next == NULL){
          printf("there is no number %d in the list to delete\n", num);
          return;
      }

    while(trav->next->data != num && trav->next->next != NULL){
        trav = trav->next;
    }

    if(trav->next->data == num){
        free(trav->next);
        trav->next = trav->next->next;
        return;
    } else {
        printf("the is no number %d in the list to delete\n", num);
        return;
    }
  }

  void printEndToHead_rec(Node **head){ 
       Node *trav = *head;
     
      if(trav->next != NULL){
          printEndToHead_rec(&(trav->next)); 
      }
      printf("%d\t", trav->data);
      
  }

  void deleteNode_update(Node **head, int num){
      Node *preTrav = NULL;
      Node *trav = *head;
      bool found = false;

      while(trav != NULL && !found){
          found = trav->data == num;
          if(!found){
              preTrav = trav;
              trav = trav->next;
          }
      }

      if(found){
          if(preTrav == NULL){
              *head = trav->next; //this is the reason why we have to pass double pointer
                                // because the data want to delete located at the beginning, therefore, we need to update the head;
          }else{
              preTrav->next = trav->next;
          }
          free(trav);
      }
  }

int main(void){
    
    Node *phead1 = new_list();
    insertAtIndex(&phead1, 12, 0); //12
    addNodeAtEnd(&phead1, 4); //12 4
    phead1 = push_return(phead1, 1); // 1 12 4
    push(&phead1, 2); //2 1 12 4
    push(&phead1, 3); //3 2 1 12 4
    addNodeAtEnd(&phead1, 5); // 3 2 1 12 4 5
    push(&phead1, 5); //5 3 2 1 12 4 5
    addNodeAtEnd(&phead1, 9); //5 3 2 1 12 4 5 9
    printList(phead1);

    int count = countNodes(&phead1);
    int countv = countValue(&phead1, 5);
    printf("there are %d nodes\n", count);
    printf("there are %d number 5 in the list\n", countv);
    printEndToHead(&phead1);

    printf("printf from end to head using recursive\n");
    printEndToHead_rec(&phead1);

    printf("\n\n");

    //5 3 2 1 12 4 5 9
    //5 3 2 1 12 4 5 9 8
    printf("insert 8 at index 6\n");
   insertAtIndex(&phead1, 8, 8); 
   printList(phead1);

   printf("\n");
   printf("list 2\n");

   Node *phead2 = new_list();
   push(&phead2, 1);
   addNodeAtEnd(&phead2, 2);
   addNodeAtEnd(&phead2, 2);
   addNodeAtEnd(&phead2, 3);
   addNodeAtEnd(&phead2, 4);
   addNodeAtEnd(&phead2, 5);
   printList(phead2);
   deleteAtIndex(&phead2,2);
   printf("after delete index 2\n");
   printList(phead2);

   printf("\n");
   printf("list 3\n");
   
   Node *phead3 = new_list();
   push(&phead3, 10);
   addNodeAtEnd(&phead3, 20);
   addNodeAtEnd(&phead3, 30);
   addNodeAtEnd(&phead3, 40);
   addNodeAtEnd(&phead3, 50);
   addNodeAtEnd(&phead3, 60);
   printList(phead3);
    deleteData(&phead3, 10);
    deleteData(&phead3, 40);
    deleteData(&phead3, 10);

    printf("after delete 10 and 40\n");
   printList(phead3);

   deleteNode_update(&phead3,30);
   printf("after delete 30 using delete update\n");
    printList(phead3);
   
   

   printf("\n\n");
   Node *test = new_list();
   insertAtIndex(&test,1,0);
  // insertAtIndex(&test,2, 1);
   printList(test);

   deleteData(&test, 2);
   printList(test);



    return EXIT_SUCCESS;
}