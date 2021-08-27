#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80

unsigned int coutMatching(const char fileName[], const char match[]){
    FILE* fp;
    fp = fopen(fileName, "r");
    char buffer[MAX_CHARS_PER_LINE];
    int count =0;
    char* token;

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        /* bool different = false;
        int i =0;
        while(!different && i<strlen(match)){
            different = match[i] != buffer[i++];
           // i++;
        }
        if(!different){
            count++;
        } */
        buffer[strcspn(buffer,"\n")] = 0;
        if(strcmp(buffer, match) == 0){
            count++;
        }
    }

    fclose(fp);
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
