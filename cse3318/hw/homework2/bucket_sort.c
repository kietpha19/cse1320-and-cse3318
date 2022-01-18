/* 
 * Updated 2/25/2021 - Alexandra Stefan
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "list.h"


/* 
compile with -g to collect debugging info needed for Valgrind: 
gcc -g bucket_sort.c list.c

run with Valgrind:
valgrind --leak-check=full --show-leak-kinds=all ./a.out

run without Valgrind:
./a.out
*/

void print_array(int arr[], int N);

/* // recommended helper functions:
// function to insert a new node in a sorted list.
nodePT insert_sorted(nodePT L, nodePT newP);
//  function to sort an array sing bucket sort
void bucket_sort(int arr[], int N)
*/

void print_array(int arr[], int N){
	int j;
	printf("\n array: ");
	for(j= 0; j<N; j++){
		printf("%5d,", arr[j]);
	}
	printf("\n");
}

//-------------------------------------------------------------
int get_min(int arr[], int N){
	int min = arr[0];
	for(int i =1; i<N; i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	return min;
}

int get_max(int arr[], int N){
	int max = arr[0];
	for(int i =1; i<N; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

//remember to handle the scope, doesn't work out for every int
int get_idx(int x, int min, int max, int N){
	if(min > (-pow(2,32)/2) && max < (pow(2,32)/2-1)){
		//printf("kkkk\n"); //for debugging only
		return (x-min)*N/(max-min+1);
	}
	//printf("not run\n"); //for debugginng only
	return (x/(2*N)-min/(2*N))*N/(max/(2*N)-min/(2*N)+1);
}

int get_idx_data_type(int x, int min, int max, int N){
	double idx = ((double)x - (double)min)*(double)N/((double)max - (double)min +1);
	return (int)idx;
}

nodePT insert_sorted(nodePT L, int num){
	//this is the case when the list only have one element
	if(L->next == NULL){
		if(L->data < num){
			/* L->next = malloc(1*sizeof(struct node));
			L->next->data = num;
			L->next->next = NULL; */
			L->next = new_node(num);
		}else{
			nodePT newNode = new_node(num);
			newNode->next = L;
			L = newNode;
		}
		return L;
	}

	nodePT pre_trav = L;
	nodePT trav = pre_trav->next;
	while(pre_trav != NULL){
		if(trav == NULL || trav->data > num){
			nodePT newNode = new_node(num);
			pre_trav->next = newNode;
			newNode->next = trav;
			break;
		}
		pre_trav = trav;
		trav = trav->next;
	}

	return L;
}

void bucket_sort(int arr[], int N){
	int min = get_min(arr, N);
	int max = get_max(arr, N);
	printf("Bucketsort: min = %d, max = %d, N = %d buckets\n", min, max, N);

	//construct array of list
	nodePT *buckets = (nodePT *)calloc(N,sizeof(nodePT));
	for(int i=0; i< N; i++){
		int idx = get_idx_data_type(arr[i], min, max, N);
		printf("arr[%d] = %d, idx = %d\n", i, arr[i], idx);

		if(buckets[idx] == NULL){
			buckets[idx] = new_node(arr[i]);
		}else{
			buckets[idx] = insert_sorted(buckets[idx], arr[i]);
		}
	}

	//print each bucket
	for(int i =0; i<N; i++){
		printf("\n");
		printf("------ List at index %d\n", i);
		print_list_horiz(buckets[i]);
	}
	
	//copy from bucket list to original array
	int count = 0;
	int i = 0;
	while(i < N){
		if(buckets[i] != NULL){
			nodePT trav = buckets[i];
			while(trav != NULL){
				arr[count++] = trav->data;
				trav = trav->next;
			}
		}
		i++;
	}	
	//print_array(arr, N);

	//free list memory
	for(int i =0; i<N; i++){
		destroy_list(buckets[i]);
		//printf("\n");
	}
	//free array list memory
	free(buckets);
}

void get_array(int **nums, int *N){
	char fname[100];
	FILE *fp;

	//get the file name from user input
	printf("Enter the filename: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");

	//check if the file exist or null
	if(fp == NULL){
		printf("File could not be opened.\n");
		return;
	}
	else{
		//get the size of the array
		int n;
		fscanf(fp, "%d", &n);
		*nums = (int *)malloc(n*sizeof(int));
		*N = n;

		//read number from file and populate array
		int i;
		for(i =0; i<n; i++){
			int num;
			fscanf(fp, "%d ", &num);
			(*nums)[i] = num;
		}
	}
	fclose(fp);
}

void run1(){
  // Fill in your code here. You should not write everything in this function.  
  // Write some helper functions to separate the work.	
	//printf("\n-------run1 - this is a place holder. You need to edit this function.------ \n");
	int *arr;
	int N=0;
	get_array(&arr, &N);
	if(N == 0){
		return;
	}
	printf("\n");
	print_array(arr, N); //print original array
	printf("\n");

	bucket_sort(arr, N);
	print_array(arr, N); //print sorted array
	free(arr); //free dynamic array
}

int main()
{
	printf("This program will read a file name, load data for an array from there and print the sorted array.\n");
	printf("The array is sorted using bucket sort.\n");
	printf("This will be repeated as long as the user wants.\n");
	int option;
	do {
		run1();
		printf("\nDo you want to repeat? Enter 1 to repeat, or 0 to stop) ");
		scanf("%d",&option);
	} while (option == 1);

   return 0;
}