// Structs_File
// Dynamically store points from a file
// Crowd-sourced solution from section 002
// This version will error on an incomplete line
// C99

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

typedef struct _Point
{
    int x;
    int y;
} Point;

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
    Point *points;
    Point center;
    int count = 0;
    FILE *file;
    char buffer[MAX_CHARS_PER_LINE+1];
    char *token;
    int i;
    char delim[] = ", ";
    file = fopen("data4.txt", "r");
    if (file == NULL)
    {
        printf("File could not be opened\n");
        exit(EXIT_FAILURE);
    }
    points = malloc(1*sizeof(Point));
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    { 
#ifdef DEBUG
        printf("Line: %s\n", buffer);
#endif
        token = strtok(buffer, delim);
#ifdef DEBUG
        printf("x: %s\n", token);
#endif
        points[count].x = atoi(token);
        token = strtok(NULL, delim);
#ifdef DEBUG
        printf("y: %s\n", token);
#endif
        points[count].y = atoi(token);
        count++;
        points = realloc(points, (count+1)*sizeof(Point));
    }
    getCenter(&center, points, count);
    printf("Center was at (%d, %d)\n", center.x, center.y);
    for (i = 0; i < count; i++)
    {
        printf("&points[%d]   = %p\n", i, &points[i]);
        printf("&points[%d].x = %p\n", i, &points[i].x);
        printf("&points[%d].y = %p\n", i, &points[i].y);
    }
    printf("sizeof(int)   = %d\n", (int) sizeof(int));
    printf("sizeof(Point) = %d\n", (int) sizeof(Point));
    printf("sizeof(points) = %d\n", (int) sizeof(points));
    printf("sizeof(Point *) = %d\n", (int) sizeof(Point *));
    fclose(file);
    return EXIT_SUCCESS;
}


