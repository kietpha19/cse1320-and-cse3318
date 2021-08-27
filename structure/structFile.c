#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

typedef struct _Point
{
    int x;
    int y;
} Point;

Point new_Point(int x, int y)
{
    Point pt = {x,y};
    //pt.x = x;
   // pt.y = y;
    return pt;
}
void printPts(Point *pts, int count)
{
    for (int i; i < count; i++)
    {
        printf("point %d: (%d, %d)\n", i, pts[i].x, pts[i].y);
    }
}

void getCenter(Point *center, Point *pts, int count)
{
    //confusing one
    center->x = 0;
    center->y = 0;
    for (int i = 0; i < count; i++)
    {
       // printf("pts.x %d\n", pts[i].x);
       // printf("pts.y %d\n", pts[i].y);

        center->x += pts[i].x;
        center->y += pts[i].y;
       // printf("center.x %d\n", center->x);
       // printf("center.y %d\n", center->y);

    }
    center->x /= count;
    center->y /= count;


    //correct one
    /* int sumX =0;
    int sumY=0;
    int i;
    for(i=0; i<count; i++){
        sumX += pts[i].x;
        sumY += pts[i].y;
    }
    center->x = sumX/count;
    center->y = sumY/count; */
}

int main(void)
{
    FILE *fp = fopen("data4.txt", "r");
    if (fp == NULL)
    {
        printf("could not open the file!\n");
        exit(EXIT_FAILURE);
    }

    char buff[MAX_CHARS_PER_LINE + 1];
    char delim[] = " ,\n";
    Point *pts;
    char *token;
    int count = 0;
    int x, y;

    pts = malloc(1 * sizeof(Point));
    int line = 0;
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        printf("line %d: %s", line, buff);
        printf("\n");
        line++;
        token = strtok(buff, delim);
        if (token != NULL)
        {
            x = atoi(token);
            printf("x = %d\n", x);
            token = strtok(NULL, delim);
            if (token != NULL)
            {
                y = atoi(token);
                printf("y = %d\n", y);
                pts[count] = new_Point(x, y);
                count++;
                pts = realloc(pts, (count + 1) * sizeof(Point));
            }
        }
    }

    printPts(pts, count);

    //printf("%d\n", count);
    Point center;
    getCenter(&center, pts, count);
    printf("center is: (%d, %d)\n", center.x, center.y);
    free(pts);
    fclose(fp);

    return EXIT_SUCCESS;
}
