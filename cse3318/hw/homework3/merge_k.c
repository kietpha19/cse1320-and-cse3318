#include <stdlib.h>
#include <stdio.h>


#include "merge_k.h"  // includes list.h

/*  Sorts linked list L in pace using insertion sort. 
*/
nodePT sort_list(nodePT L){
	// implement insertion sort for linked list
	if(L == NULL || L->next == NULL) return L; // NULL or 1 element

	nodePT head = L;
	L = L->next;
	head->next = NULL;
	//nodePT trav = head;

	while(L != NULL){
		nodePT nd = L;
		L = L->next;
		if(nd->data < head->data){
			nd->next = head;
			head = nd;
		}else{
			nodePT cur = head;
			while(cur->next != NULL && cur->next->data < nd->data){
				cur = cur->next;
			}
			nd->next = cur->next;
			cur->next = nd;
		}
	}
	return head;
}

/* It is recommended to implement a sinkDown function in this file. 
You can declare its header at the top of this file (after include) 
write the implementation anywhere in this file. 
(You cannot modify any of the list.h or merge_k.h files) 
*/
int i_of_min(nodePT heap[], int p, int left, int right, int k){
	int i_min = p;
	if( left<k && heap[left]->data < heap[i_min]->data) i_min = left;
	if( right<k && heap[right]->data < heap[i_min]->data) i_min = right;
	return i_min;
}

void sinkDown(nodePT heap[], int p, int k){
	int left = 2*p +1;
	int right = 2*p +2;
	int i_min = i_of_min(heap, p, left, right, k);
	while(i_min != p){
		nodePT temp = heap[p];
		heap[p] = heap[i_min];
		heap[i_min] = temp;

		p = i_min;
		left = 2*p+1;
		right = 2*p +2;

		i_min = i_of_min(heap, p, left, right, k);
	}

}


/* Turns the given array (named heap) into an actual Min-Heap
   using the bottom-up method to build the heap. 
   (See buidMaxHeap pseudocode in slides)
*/
void make_heap(int k, nodePT heap[]){
	// write your code in here
	for(int p = (k-1)/2; p >=0; p--){
		sinkDown(heap, p, k);
	}

	printf("finished.\n");
	printf("the heap is: \n");
	for(int i =0; i< k; i++){
		print_list_pointer(heap[i]);
	}

}



/*  heap is a Min-Heap of linked lists
	remove_min will remove AND RETURN the first node of the list at index 0.
	k (size of heap) will only change when that removal leaves that list empty.
*/
nodePT remove_min(int* k, nodePT heap[]){
	// Replace the place holder code with the correct code
	nodePT nd = heap[0];
	
	heap[0] = nd->next;
	nd->next = NULL;
	if(heap[0] == NULL){
		/* int i;
		for(i = 0; i< *k; i++){
			heap[i] = heap[i+1];
		} */
		(*k)--;
		heap[0] = heap[*k];
		heap[*k] = NULL;
		sinkDown(heap, 0, *k);
	}else{
		sinkDown(heap, 0, *k);
	}


   return nd;  // place holder code. 
}


void print_heap(nodePT heap[], int k){
	printf("---- HEAP (start) -------\n");
	for(int i=0; i<k; i++){
		print_list_pointer(heap[i]);
	}
	printf("--- HEAP (end) -------\n");
}

/*
Input
   heap - is a Min-Heap array of SORTED single linked lists. 
   k - size of array heap. The first item is at index 0
   debug - debug on/off:
			if debug is 1, student code should print debugging information as well: heap and sorted result list
			if debug is 0, it does not print debugging infomation. 
			if debug is anything but 1, it does not print debugging infomation.
Returns: a sorted single linked list built by merging the k lists.

Algorithm
   Merging process: 
	- use the heap to identify and remove the node, np, with the smallest data out 
      of the k lists.
	- insert np at the end of result list.
*/
nodePT merge_k(int k, nodePT heap[], int debug){
	// Replace the place holder code with the correct code
	
	nodePT L = remove_min(&k, heap);
	if(debug == 1){
		print_list_pointer(L);
		printf("\n");
		print_heap(heap, k);
	}
	
	nodePT trav = L;
	while(heap[0] != NULL){
		trav->next = remove_min(&k, heap);
		trav = trav->next;
		if(debug == 1){
			printf("\n----------------- Sorted result list:\n");
			print_list_pointer(L);
			printf("\n");
			print_heap(heap, k);
		}
	}
	printf("Empty heap. No remove performed\n");
   return L;   // place holder code
}
