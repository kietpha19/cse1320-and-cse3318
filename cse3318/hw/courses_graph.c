#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 31
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS_visit(int **graph, int N, int u, int *color, int *res, bool *cycle, int *p){
    color[u] = GRAY;
    for(int v=0; v<N; v++){
        if(graph[u][v] == 1 && color[v] == GRAY){
            *cycle = true;
            return;
        }
        else if(graph[u][v] == 1 && color[v] == WHITE){
            DFS_visit(graph, N, v, color, res, cycle, p);
        }
    }
    color[u] = BLACK;
    res[(*p)] = u;
    (*p)++;
    return;
}

int main(){
    char fileName[MAX_LEN];
    char line[1001];
    char c;
    char **courses = NULL;
    int N =0;

    printf("This program will read, from a file, a list of courses and their prerequesites and will print the list in which to take courses.\n");
    printf("Enter file name: ");
    scanf("%s%c", fileName, &c);

    //open the file
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("could not open the input file %s. Exit\n", fileName);
        exit(EXIT_FAILURE);
    }

    //store the courses and their prerequisite to a char pointer array
    while(fgets(line, sizeof(line), fp) != NULL){
        //printf("%s\n", line);
        N++;
        courses = realloc(courses, N*sizeof(char*));
        courses[N-1] = malloc((strlen(line)+1)*sizeof(char));
        strcpy(courses[N-1], line);
        //printf("%s\n", courses[N-1]);
    }
    fclose(fp);

    //store only the courses as a string array
    printf("Number of vertices in built graph: N = %d\n", N);
    char **class = malloc(N*sizeof(char*));
    char *token;
    char buffer[1001];
    for(int i=0; i<N; i++){
        strcpy(buffer, courses[i]);
        token = strtok(buffer, " \n");
        class[i] = malloc((strlen(token)+1)*sizeof(char));
        strcpy(class[i], token);
        printf("%d - %s\n", i, class[i]);
    }

    //create 2d array for the graph
    int **graph = malloc(N*sizeof(int *));
    for(int i=0; i<N; i++){
        graph[i] = malloc(N*sizeof(int));
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            graph[i][j] = 0;
        }
    }
    for(int j=0; j<N; j++){
       token = strtok(courses[j], " \n"); //skip the first one
       token = strtok(NULL, " \n"); 
        while(token != NULL){
            for(int i=0; i<N; i++){
                if(strcmp(token, class[i]) == 0){
                    graph[i][j] = 1;
                    i = N; //break out of the for loop
                }
            }
            token = strtok(NULL, " \n");
        }
    }

    // //print the matrix that represent the graph
    printf("\nAdjacency matrix: \n");
    printf("%5c", '|');
    for(int i=0; i<N; i++){
        printf("%5d", i);
    }
    printf("\n");
    for(int i=0; i<N; i++){
        printf("-------");
    }
    printf("\n");
    for(int i=0; i<N;i++){
        printf("%4d|", i);
        for(int j=0; j<N; j++){
            printf("%5d", graph[i][j]);
        }
        printf("\n");
    }
    
    //topological sorting
    //////////////////////////////////////////////////////////////////////////////
    int res[N]; //resul array
    bool cycle = false;
    //color array
    int color[N];
    for(int i=0; i<N; i++){
        color[i] = WHITE;
        res[i] = -1;
    }

    int p =0;
    for(int u=0; u<N; u++){
        if(color[u] == WHITE){
            DFS_visit(graph, N, u, color, res, &cycle,&p);
        }
    }

    if(cycle){
        printf("\nThere was at least one cycle. There is no possible ordering of the courses.\n");
    }else{
        printf("\nOrder in which to take courses:\n");
        for(int i=N-1; i>=0; i--){
            printf("%d. - %s (corresponds to graph vertex %d)\n", N-i, class[res[i]], res[i]);
        }
    }
    //////////////////////////////////////////////////////////////////////////////

    //free courses memory
    for(int i=0; i<N; i++){
        free(courses[i]);
        free(class[i]);
        free(graph[i]);
    }
    free(courses);
    free(class);
    free(graph);

    return EXIT_SUCCESS;
}