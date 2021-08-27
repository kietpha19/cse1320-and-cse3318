#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80
#define MAX_UNIQUE_NUMS 20

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("passing arguments incorrectly!!\n");
        printf("usage: filefind filename\n");
    }

    char buffer[MAX_CHARS_PER_LINE+1];
    char delimeter[] = " ,\t";
    int uniqueNums[MAX_UNIQUE_NUMS]; //STATIC MEMORY
    int i,j = 0;
    char* token;
    int num;
    bool found;

    FILE* fp;
    fp = fopen(argv[1], "r");

    int line =1;
    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        printf("line %d: %s\n", line, buffer);

        token = strtok(buffer, delimeter);
        while(token != NULL){
            if(j > MAX_UNIQUE_NUMS){
                printf("too many unique number in file %s\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            num = atoi(token);
            printf("num = %d\n", num);
            found = false;
            i = 0;
            while(!found && i<j){
                found = num == uniqueNums[i++];
            }

            if(!found){
                uniqueNums[j++] = num;
            }
            token = strtok(NULL, delimeter);
        }
        line++;
    }

    fclose(fp);

    if(j == 0){
        printf("there is no unique numbers in %s\n", argv[1]);
        return EXIT_SUCCESS;
    }
    printf("the unique number found in %s are:\n", argv[1]);
    for(i=0; i<j; i++){
        printf("%d\n", uniqueNums[i]);
    }

    return EXIT_SUCCESS;
}