/* 
 When you run this program with Valgrind, you will find a memory leak.
 What is the cause of this leak?
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char* fname);

int main(int argc, char** argv) {
    read_file("fileread_data.txt");
    return (EXIT_SUCCESS);
}


void read_file(char* fname) {
    FILE * fp = fopen(fname, "r");
    if (fp == NULL) {
        return;
    }

    size_t len = 0;
    char * buffer = (char*) malloc(1001 * sizeof (char));
    int count = 0;    
    size_t read;
	    
    while ((read = getline(&buffer, &len, fp)) != -1) {
        printf("buffer = %s\n", buffer);
    }
	
    fclose(fp);
    free(buffer);    
}
