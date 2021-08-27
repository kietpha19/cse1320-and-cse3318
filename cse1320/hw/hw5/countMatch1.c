#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80

unsigned int coutMatching(const char fileName[], const char match[]){
    FILE *input = fopen(fileName, "r");
    char stringEntry[MAX_CHARS_PER_LINE];
    int count = 0;
  
    if (input == NULL)
    {
        printf("ERROR: The input file %s does not exist:\n", fileName);
        return 0;
    }
   
    while ( !feof(input))
    { 
    
        fscanf(input, "%s", stringEntry );
        if (strcmp(stringEntry, match) == 0)
        {
            count++;
        }
    }
  
    fclose(input);
    return count; 
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("passing arguments incorrectly!\n");
        printf("usage: fileExe fileName matchingWord\n");
        exit(EXIT_FAILURE);
    }

    unsigned numOfMatching = coutMatching(argv[1], argv[2]);
    printf("there are %d matching result with the string %s\n", numOfMatching, argv[2]);
    return EXIT_SUCCESS;
}
