#include <stdio.h>
#include <stdlib.h>
#include "list.h"

nodePT list_from_list(nodePT L){
    if(L == NULL || L->next == NULL) return L;

    nodePT nd = new_node(L->data);
    nd->next = list_from_list(L->next);
    return nd;
}

nodePT deleteByValue(nodePT nd, int val){
    if(nd == NULL) return nd;
    if(nd->data == val){
        nodePT del = nd;
        nd = nd->next;
        free(del);
        return nd;
    }
    nodePT pre_trav = nd;
    nodePT trav = nd->next;
    while(trav != NULL){
        if(trav->data == val){
            pre_trav->next = trav->next;
            free(trav);
            return nd;
        }
        trav = trav->next;
        pre_trav = pre_trav->next;
    }
    return nd;
}

int main(){
    int arr[5] = {1,2,7,4,5};
    nodePT L  = array_2_list(arr, 5);
    print_list_horiz(L);

    nodePT L2 = list_from_list(L);
    print_list_horiz(L2);

    nodePT L3 = deleteByValue(L2, 8);
    print_list_horiz(L3);
    destroy_list(L);
    //destroy_list(L2);
   // print_list_horiz(L);
    return 0;
}