#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("passing arguments incorrectly!!\n");
        printf("usage: filefind filename num\n");
    }

    char buffer[MAX_CHARS_PER_LINE+1];
    char delimeter[] = " ,\t";
    char *token;

    int num = atoi(argv[2]);
    FILE* fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("could not onpen file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int line=1;
    int count =0;
    

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        printf("line %d: %s\n", line, buffer );

        token = strtok(buffer, delimeter);
        while(token != NULL){
            printf("num = %s\n", token);

            if (num == atoi(token))
            {
                count++;
            }
            token = strtok(NULL, delimeter);
        }
        printf("count = %d\n", count);
        line++;
    }

    fclose(fp);
    printf("the number %d has appeared in the file %s %d time\n", num, argv[1], count);

    return EXIT_SUCCESS;
}