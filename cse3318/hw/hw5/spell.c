#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "spell.h"

/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MAX_LEN:
Student answer:  Theta(T*(MAX_LEN)^2)


Worst case to do an unsuccessful binary search in a dictionary with D words, when 
all dictionary words and the searched word have length MAX_LEN 
Student answer:  Theta(DlogD*(MAX_LEN)^2)

*/


/* You can write helper functions here */
int get_min(int a, int b, int c){
	if(b<a){
		if(b<c) return b;
		else return c;
	}else{
		if(a<c) return a;
		else return c;
	}
}
void print_line(int len){
	printf("\n");
	if(len < 15){
		for(int i=0; i<= (len+2)*5; i++){
			printf("-");
		}
		printf("\n");
	}else if(len > 15){
		for(int i=0; i<= (len+2)*6; i++){
			printf("-");
		}
		printf("\n");
	}
	
}

void printting_table(int *a, int rows, int cols, char *first_string, char *second_string){
	printf("     |     |");
	for(int i=0; i<strlen(second_string); i++){
		printf("%5c|", second_string[i]);
	}
	print_line(cols);
	printf("     |");
	for(int j=0; j< cols; j++){
		printf("%5d|", *((a)+j));
	}
	print_line(cols);
	for(int i =1; i<rows; i++){
		printf("%5c|", first_string[i-1]);
		for(int j =0; j<cols; j++){
			printf("%5d|", *((a+i*cols)+j));
		}
		print_line(cols);
	}
}

/*
Parameters:
first_string - pointer to the first string (displayed vertical in the table)
second_string - pointer to the second string (displayed horizontal in the table)
print_table - If 1, the table with the calculations for the edit distance will be printed.
              If 0 (or any value other than 1)it will not print the table
(See sample run)
Return:  the value of the edit distance (e.g. 3)
*/
int edit_distance(char * first_string, char * second_string, int print_table){
	// replace this line with your code
	int m = strlen(first_string);
	int n = strlen(second_string);

	//if one of the word is empty, then return either m or n. n+m equal either m or n because either m or n equal 0
	if(n*m == 0) return n+m; 

	int a[m+1][n+1];

	//initialize the border
	for(int i = 0; i < m+1; i++){
		a[i][0] = i;
	}
	for(int j = 0; j< n+1; j++){
		a[0][j] = j;
	}

	//compute edit distance
	for(int i =1; i<m+1; i++){
		for(int j =1; j<n+1; j++){
			int up = a[i-1][j] + 1;
			int right = a[i][j-1]+1;
			int diagonal;
			if(first_string[i-1] == second_string[j-1]){
				diagonal = a[i-1][j-1];
			}else{
				diagonal = a[i-1][j-1]+1;
			}
			a[i][j] = get_min(up, right, diagonal);
		}
	}
	if(print_table == 1){
		//printting_table((int*)a, m+1, n+1, first_string, second_string);
	}
	return a[m][n];  
}
	  

/*
Parameters:
testname - string containing the name of the file with the paragraph to spell check, includes .txt e.g. "text1.txt" 
dictname - name of file with dictionary words. Includes .txt, e.g. "dsmall.txt"
printOn - If 1 it will print EXTRA debugging/tracing information (in addition to what it prints when 0):
			 dictionary as read from the file	
			 dictionary AFTER sorting in lexicographical order
			 for every word searched in the dictionary using BINARY SEARCH shows all the "probe" words and their indices indices
			 See sample run.
	      If 0 (or anything other than 1) does not print the above information, but still prints the number of probes.
		     See sample run.
*/
FILE *created_output_file(char *testname){
	char *output = malloc(5+strlen(testname)); //len of out_ is 4, +1 for the null terminator
	if(output == NULL){
		printf("Can not open output file\n");
		exit(EXIT_FAILURE);
	}
	strcpy(output, "out_");
	strcat(output, testname);
	FILE *fp = fopen(output, "w");
	if(fp == NULL){
		printf("Can not open output file\n");
		exit(EXIT_FAILURE);
		return NULL;
	}
	printf("Corrected output filename: %s\n", output);
	printf("\n");
	free(output);
	return fp;
}

char **get_dict_table(FILE *fp_dict, int *dict_size){
	char *line = NULL;
	size_t len =0;
	ssize_t read;

	//read the first line, which is the number or words in the dictionary
	if((read = getline(&line, &len, fp_dict)) != -1){
		*dict_size = atoi(line);
	}

	//create a table that include dict_size slots of char pointers
	char **dict_table = malloc((*dict_size)*sizeof(char*));
	if(dict_table == NULL){
		printf("fail to allocate memory for dictionary table\n");
		exit(EXIT_FAILURE);
	}

	//get every words in the file to the dictionary table
	int count =0;
	while((read = getline(&line, &len, fp_dict)) != -1){
		if(count > (*dict_size)){
			printf("too many word in the dictionary\n");
			exit(EXIT_FAILURE);
		}
		dict_table[count] = malloc((read)*sizeof(char));
		if(dict_table[count] == NULL){
			printf("fail to allocate memory for words in dictionary table\n");
			exit(EXIT_FAILURE);
		}
		if((count == 0) || (count== 999)) printf("%sdfffffffff\n", line);
		strcat(dict_table[count], line);
		(dict_table[count])[read-1] = '\0';
		count++;
	}

	fclose(fp_dict);
	if(line) free(line);
	return dict_table;
}

void print_dict_table(char **dict_table, int dict_size){
	for(int i=0; i<dict_size; i++){
		printf("\n%d. ", i);
		printf("%s", dict_table[i]);
	}
	printf("\n\n");
}

int static compar(const void* a, const void* b){
	return strcmp(*(const char**)a, *(const char**)b);
}

char **sort_dict_table(char **dict_table, int dict_size){
	qsort(dict_table, dict_size, sizeof(const char*), compar);
	return dict_table;
}

void reset_word(char **word){
	for(int i =0; i<101; i++){
		(*word)[i] = '\0';
	}
}

bool isSeperator(char c){
	char seperator[] = " 	.,?!()\"\'"; //can add on any others seperators if desired
	for(int i =0; i<strlen(seperator); i++){
		if(c == seperator[i]) return true;
	}
	return false;
}

bool binary_search(char **dict_table, int dict_size, char *word, int printOn){
	char word_lowercase[strlen(word)];
	for(int i=0; i <strlen(word); i++){
		word_lowercase[i] = tolower(word[i]);
	}
	//word_lowercase[strlen(word)-1] = '\0';
	if(printOn == 1){
		printf("\nBinary search for: %s\n", word_lowercase); //if
	}
	
	int left = 0;
	int right = dict_size-1;
	
	int count =0;
	while(left<=right){
		int mid = left + (right - left)/2;
		count++;
		if(printOn == 1){
			printf("dict[%d] = %s\n", mid, dict_table[mid]); //if
		}

		//printf("%lu\n", strlen(dict_table[mid]));
		//printf("%lu\n", strlen(word_lowercase));
		if(strcmp(dict_table[mid], word_lowercase) == 0){
			printf("---> |%s| (words compared when searching: %d)\n", word, count);
			return true;
		}
		else if(strcmp(dict_table[mid], word_lowercase) < 0) left = mid +1;
		else right = mid -1;
	}
	if(printOn == 1){
		printf("Not found\n\n"); //if
	}
	
	printf("---> |%s| (words compared when searching: %d)\n", word, count);
	return false;
}

void spell_check(char * testname, char * dictname, int printOn){
	// Write your code here

	//create the output file and check error for all the file
	FILE *fp_test = fopen(testname, "r");
	if(fp_test == NULL){
		printf("Could not open text file\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp_output = created_output_file(testname);
	FILE *fp_dict = fopen(dictname, "r");
	if(fp_test == NULL){
		printf("Could not open dictionary file\n");
		exit(EXIT_FAILURE);
	}
	printf("Loading the dictionary file: %s\n\n", dictname);

	//create dictionary table
	int dict_size =0;
	char **dict_table = get_dict_table(fp_dict, &dict_size);

	//print the original dictionary
	printf("Dictonary has size: %d\n", dict_size);
	if(printOn == 1){
		printf("  the Original dictionary: \n");
		print_dict_table(dict_table, dict_size);
	}
	
	//sort the dictionary table and print
	dict_table = sort_dict_table(dict_table, dict_size);
	if(printOn == 1){
		printf("  Sorted dictionary (alphabetical order) :\n");
		print_dict_table(dict_table, dict_size);
	}
	
	char c;
	int count = 0;
	char *word = malloc(101*sizeof(char));
	c = fgetc(fp_test);
	while(c != EOF){
		if(!isSeperator(c)){
			word[count++] = c;
			c = fgetc(fp_test);
		}else if(isSeperator(c)){
			count =0;
			c = fgetc(fp_test);
			if(strlen(word) > 0){
				//printf("%s\n", word); //for debugging
				bool good = binary_search(dict_table, dict_size, word, printOn);
				//working on: if it good and not good
				if(good){
					printf("	- OK\n\n");
				}else{
					printf("not ok\n\n");
				}

				reset_word(&word);
			}
		}
		if(c==EOF){
			if(strlen(word) > 0){
				//printf("%s\n", word); //for debugging
				bool good = binary_search(dict_table, dict_size, word, printOn);

				//working on: if it good and not good
				if(good){
					printf("- OK\n\n");
				}else{
					printf("not ok\n");
				}
				reset_word(&word);
			}
		}
	}
}
