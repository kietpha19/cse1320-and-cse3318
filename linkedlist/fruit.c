#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *fp = fopen("fruit.txt", "r");
    if(fp == NULL){
        printf("could not open the file\n");
        exit(EXIT_SUCCESS);
    }

    char **fruit;
    fruit = malloc(1*sizeof(char*));
    if(fruit == NULL){
        printf("out of memory\n");
        exit(EXIT_FAILURE);
    }

    char buff[81];
    int count =0;
    while(fgets(buff, sizeof(buff), fp) != NULL){
        fruit[count] = malloc((strlen(buff)+1) * sizeof(char));
        strcpy(fruit[count], buff);
        count ++;
        fruit = realloc(fruit, (count+1)*sizeof(char*));
    }

    for(int i=0; i < count; i++){
        printf("%s\n", fruit[i]);
    }
    for(int i=0; i<coutn; i++){
        free(fruit[i]);
    }
    free(fruit);

    fclose(fp;)

    return EXIT_SUCCESS;
}