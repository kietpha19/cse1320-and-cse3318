// HW7
// Parsing CSV File with double-quoted fields
// Dynamic allocation array of pointer to strings (char**)
// C99

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hw6_fns.h"


#define MAX_CHARS_PER_LINE 200

int main(int argc, char* argv[])
{
    FILE *file;
    char **b;
    int i;
    int count = 0;
    char buffer[MAX_CHARS_PER_LINE+1];
    char temp[MAX_CHARS_PER_LINE+1];
   // char *str;
    // Check argument count
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        exit(EXIT_FAILURE);
    }
    // Open file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Coulf not open file\n");
        exit(EXIT_FAILURE);
    }
    // Allocate one char* in array
    b = malloc(1*sizeof(char*));
    if (fgets(buffer, sizeof(buffer), file) == NULL)
    {
        printf("Error reading top line\n");
        exit(EXIT_FAILURE);
    }
    // Read in each line and store business string
    // Resize array in anticipation of adding next char*
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        getBusiness(temp, buffer);

        bool found = false;
        int i=0;
        while(!found && i<count){
            found = strcmp(temp, b[i++]) ==0;
        }

        if(!found){

           // str = malloc((strlen(temp)+1)*sizeof(char)); 

            b[count] = malloc((strlen(temp)+1)*sizeof(char));
              // str and temp still has differnet address after this line
             //strcpy(str, temp);  // temp is an static string, str is dynamic string, b[count] is an dynamic string. 

              //b[count++] = str; // this line literaly tell the poiter b[count] to point to the the address of str
            strcpy(b[count++],temp); // can strcpy from a static string to a dynamic string. 
            b = realloc(b, (count+1)*sizeof(char*));
        }
        
    }
    // Close file
    fclose(file);
    // Print business names
    printf("%d records found\n\n", count);
    for (i = 0; i < count; i++)
    {
        printf("Business: %s\n", b[i]);
    }
    // Release memory
    for (i = 0; i < count; i++)
        free(b[i]);
    free(b);
    return EXIT_SUCCESS;
}

