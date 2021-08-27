// Structs_File
// Dynamically store points from a file
// Crowd-sourced solution from section 001
// This version handles an incomplete or blank last line correctly
// C99

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

// Point
typedef struct _Point
{
    int x;
    int y;
} Point;

// Pass an array of "count" points
// Function will calculate the center of the points and return center
void getCenter(Point *center, Point points[], int count)
{
    int sumX = 0;
    int sumY = 0;
    int meanX, meanY;
    int i;
    for (i = 0; i < count; i++)
    {
        sumX += points[i].x;
        sumY += points[i].y;
    }
    meanX = sumX / count;
    meanY = sumY / count;
    center->x = meanX;
    center->y = meanY;
}

int main(void)
{
    int count = 0;
    Point *points;
    Point center;
    FILE *file;
    char buffer[MAX_CHARS_PER_LINE+1];
    char *token;
    char delim[] = " ,\n";
    points = malloc(1*sizeof(Point));
    file = fopen("data4.txt", "r");
    if (file == NULL)
    {
        printf("File could not be opened\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
#ifdef DEBUG
        printf("Line: %s\n", buffer);
#endif
        token = strtok(buffer, delim);
        if (token != NULL)
        {
    #ifdef DEBUG
            printf("Token 1: %s\n", token);
    #endif
            points[count].x = atoi(token);
            token = strtok(NULL, delim);
            if (token != NULL)
            {
        #ifdef DEBUG
                printf("Token 2: %s\n", token);
        #endif
                points[count].y = atoi(token);
                count++;
                points = realloc(points, (count+1)*sizeof(Point));
            }
        }
    }
    getCenter(&center, points, count);
    printf("Center was at (%d, %d)\n", center.x, center.y);
    free(points);
    fclose(file);
    return EXIT_SUCCESS;
}
