#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6_fns.h"

#define POS_BUSINESS 6
#define POS_ADDRESS 4
#define POS_CONTACT 8

void getBusiness(char strBusiness[], const char strLine[]){
    char *str;
    str = malloc((strlen(strLine)+1)*sizeof(char));
    strcpy(str, strLine);

    char *token;
    int skip =0;
    char delim[] = "\"";

    token = strtok(str, delim);
    while(token!=NULL && skip<POS_BUSINESS){
        token = strtok(NULL, delim);
        skip++;
    }
    if(token != NULL){
        if(strcmp(token, ",") == 0)
            strcpy(strBusiness, "(none)");
        else
            strcpy(strBusiness, token);
    }
    free(str);
}

void getAddress(char strAddress[], const char strLine[]){
    char *str;
    str = malloc((strlen(strLine)+1)*sizeof(char));
    strcpy(str, strLine);

    char *token;
    int skip =0;
    char delim[] = "\"";

    token = strtok(str, delim);
    while(token!=NULL && skip<POS_ADDRESS){
        token = strtok(NULL, delim);
        skip++;
    }
    if(token != NULL){
        if(strcmp(token, ",") == 0)
            strcpy(strAddress, "(none)");
        else
            strcpy(strAddress, token);
    }
    free(str);
}

void getContact(char strContact[], const char strLine[]){
    char *str;
    str = malloc((strlen(strLine)+1)*sizeof(char));
    strcpy(str, strLine);

    char *token;
    int skip =0;
    char delim[] = "\"";

    token = strtok(str, delim);
    while(token!=NULL && skip<POS_CONTACT){
        token = strtok(NULL, delim);
        skip++;
    }
    if(token != NULL){
        if(strcmp(token, ",") == 0)
            strcpy(strContact, "(none)");
        else
            strcpy(strContact, token);
    }
    free(str);
}
