#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80
#define MAX_ODD_NUMS 20

unsigned int countOdd(const char file[]){
    FILE* fp;
    fp = fopen(file, "r");
    char buffer[MAX_CHARS_PER_LINE];
    bool found;
    int i,j = 0;
    int num;
    int oddNums[MAX_ODD_NUMS];
    int count =0;

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        if(j > MAX_ODD_NUMS){
            printf("too many odd numbers\n");
            exit(EXIT_FAILURE);
        }
        num = atoi(buffer);
        if(num%2 != 0){
            /* i=0;
            found = false;
            while(!found && i<j){
                found = num == oddNums[i++];
            }
            if(!found){
                oddNums[j++]= num;
            } */
            count++;
        } 
    }

    fclose(fp);    
   // return j; 
   return count;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("passing arguments incorrectly!!\n");
        printf("usage: fileExe filename\n");
        exit(EXIT_FAILURE);
    }
    unsigned int numOfOdd = countOdd(argv[1]);
    printf("there are %d odd numbers in file %s\n", numOfOdd, argv[1]);


}