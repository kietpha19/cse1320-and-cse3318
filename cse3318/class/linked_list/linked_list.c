/* Updated 2/25/2021 - Alexandra Stefan
 */

#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/* compile:
gcc -g test_list.c list.c
run:
./a.out
run with Valgrind:
valgrind --leak-check=full --show-leak-kinds=all ./a.out
 */

nodePT array_2_list_rec(int arr[], int N){
    if(N==0) return NULL;

    //easier to understand but not optimal
    /* int i =0;
    nodePT nd = new_node(arr[i]);
    nd->next = array_2_list_rec(&arr[i+1], N-1);
 */
    nodePT nd = new_node(arr[0]);
    nd->next = array_2_list_rec(&arr[1], N-1);

    return nd;
}

nodePT array_2_list_rev_rec(int arr[], int N){
    if(N==0) return NULL;

    nodePT nd = new_node(arr[N-1]);
    nd->next = array_2_list_rev_rec(arr, N-1);
    return nd;
}

nodePT build_rev_list(nodePT l, nodePT* l_rev){
    if(l->next == NULL){
        nodePT last = new_node(l->data);
        (*l_rev) = last;
        return last;
    }
    nodePT pre_trav = new_node(l->data);
    nodePT trav = build_rev_list(l->next, l_rev);
    trav->next = pre_trav;
    return pre_trav;
}

nodePT list_2_list_rev(nodePT l){
    if(l == NULL || l->next == NULL) return l;
    nodePT l_rev = NULL;
    build_rev_list(l, &l_rev);
    return l_rev;
}

int main()
{    
    int arr[] = {9,1,7,260};
   int N = sizeof(arr)/sizeof(int);

   struct node * L = array_2_list_rec(arr, N);
    //struct node* L = array_2_list_rev_rec(arr, N);
    print_list_horiz(L);
   //print_list_pointer(L);

    nodePT L_rev = list_2_list_rev(L);
    print_list_horiz(L_rev);

  // L = delete_node(L, NULL);
    destroy_list(L);
    destroy_list(L_rev);
    /*
   print_list_pointer(L);

   nodePT ptr = new_node(25);

   L = insert_node(L, NULL, ptr); // try to run just: insert_node(L, NULL, ptr); see Valrind error.

   print_list_pointer(L);

   int length = compute_length(L);
   printf("The length of the list is %d.\n", length);

   // https://en.wikipedia.org/wiki/Endianness
   printf("\nSee below the integers in the array are: \n");
   for(int i =0; i<N; i++){
	   printf("%p, ", &arr[i]);
   }
   printf("\nsize of int is: %ld\n", sizeof(int));

   destroy_list(L); */

   return 0;
}