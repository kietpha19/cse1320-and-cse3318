/* 
  Alexandra Stefan
  
  Reads k lists into an array of linked lists, 
  sorts the lists using insertion sort, 
  turns the array into a min-Heap using bottom-up and then
  merges the lists by repeating until the heap is empty:
   - remove_min from heap and insert it at the end of result list.
  
  Notes: 
  1. the heap array keeps data starting at index 0.
  2. After you implement YOUR WORK (to merge the k lists), 
  the result sorted list (called sorted) will be destroyed (and all it's nodes freed)
  and thus all the memory should be freed. 
  However since the merge is not yet implemented and the list 'sorted' is 
  empty, the nodes from the k lists are NOT freed and so until you finish 
  your code this project has memory leaks. 
  After you finish your part there should not be any memory leaks.   
 */
 
/* compile: 
gcc merge_k_client.c merge_k.c list.c
run:
./a.out 

Valgrind:
gcc -g merge_k_client.c merge_k.c list.c
run:
valgrind --leak-check=full ./a.out 
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include "merge_k.h"   // heap.h includes list.h


void read_k_lists(int k, nodePT arrL[k], FILE* fp) {
   int i,N;
   printf("Reading %d lists in the format: list size (N) and then N integers", k);
   for (i = 0; i<k; i++) {
      fscanf(fp, "%d", &N);
      nodePT L = build_list_N(N, fp);
      arrL[i] = L; // copy memory address stored in L;
      print_list_pointer(L); // check list was read correctly
   }
}


int main()   {
   int k,i;
   char fname[501];
   int debug = 0;
   printf("This program will read k lists from a file and merge them using Min-Heap.\n ");   
   
   printf("\nEnter the run mode: 1-debug, 0-release (no debugging information)  ");
   scanf("%d", &debug);
   
   printf("Enter a filename (with the linked lists data): ");
   scanf("%s", fname);
   FILE* fp = fopen(fname, "r");
   if (fp == NULL) {
	   printf("FIle failed to open. Exit.\n");
	   return 0;
   }
   //read the number of lists, k 
   fscanf(fp, "%d", &k);
   
   nodePT heap[k];
   for(i=0; i<k; i++) { 
	  heap[i] = NULL;  
   }
   read_k_lists(k, heap, fp);
   fclose(fp);
   
   printf("\n\nSorting each linked list: \n");
   for(i=0; i<k; i++){
      print_list_pointer(heap[i]);
      heap[i] = sort_list(heap[i]);
      printf("Sorted list:");
      print_list_pointer(heap[i]);
   }
   

   printf("\nConstructing the Heap (turns the array into a heap using bottom up) ...\n");
   make_heap(k, heap);

   printf("\nMerging ...\n");   
   nodePT sorted = merge_k(k, heap, debug);   
   // if debug is 1, student code should print debugging information as well: heap and sorted result list

   printf("\n\nSorted result list is:");   
   print_list_pointer(sorted);
   destroy_list(sorted);   
    
   return 0;
}
