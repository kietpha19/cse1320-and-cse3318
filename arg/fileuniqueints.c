// Fileuniqueints (C99)
// Find and print all unique values in a file
// Static memory allocation of unique value storage

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80
#define MAX_UNIQUE_INTS 20

// usage: fileuniqueints filename
// filename is the file to open
// file contains multiple integers per line
// values can be comma, space, or tab delimited

int main(int argc, char* argv[])
{
    FILE *file;
    int temp;
    int count = 0;
    char buffer[MAX_CHARS_PER_LINE + 1];
    char *token;
    char delim[] = " \t,";
    //int values[MAX_UNIQUE_INTS];
    int* values;  // this is for dynamic memory program
    int uniqueValues = 0;
    bool found;
    int i;

    // Validate number of arguments
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        printf("usage: fileuniqueints filename\n");
        exit(EXIT_FAILURE);
    }

    // Open file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    //allocate one value, similar to values[1]
    values = malloc(1*sizeof(int));
    if(values == NULL){
        printf("out of memory\n");
        exit(EXIT_FAILURE);
    }
    
    // Parse lines of the file
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("fgets returns: %s\n", buffer);
        token = strtok(buffer, delim);
        while (token != NULL)
        {
            printf("  strtok returns: %s\n", token);
            temp = atoi(token);

            // Search the list of previous found integers
            found = false;
            i = 0;
            while(!found && i < uniqueValues)
            {
                found = temp == values[i++]; // assign found then increment i
            }
            // If not found, add to the list of values if room
            if (!found) // if found == false. if not found the num, then the codition is true, the code execute
            {
                // static memory
                /* if (uniqueValues == MAX_UNIQUE_INTS)
                {
                    printf("Too many unique values to store\n");
                    exit(EXIT_FAILURE);
                } */
                values[uniqueValues++] = temp;
                values = realloc(values, (uniqueValues+1)* sizeof(int));
                
                if(values == NULL){
                    printf("out of memory\n");
                    exit(EXIT_FAILURE);
                }

            }

            token = strtok(NULL, delim);
        }
    }

    // Close file
    fclose(file);

    // Print unique values
    printf("Unique values as found in the file:\n");
    for (i = 0; i < uniqueValues; i++)
        printf("%d\n", values[i]);

    return EXIT_SUCCESS;
}
