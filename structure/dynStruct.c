#include <stdio.h>
#include <stdlib.h>


// constructor is not availble in C, only in c++
// but you can make a fuction that take a pointer to point, and when you declare a point, you can call that function to 
// assign data to it.

typedef struct _Point
{
    int x;
    int y;
} Point;

// this function act as a constructor for struct Point
Point new_Point(int x, int y){
    Point pt = {x, y};
    return pt;
}

void printPts(Point *pts, int count){
    for(int i; i<count; i++){
        printf("point %d: (%d, %d)\n", i, pts[i].x, pts[i].y);
    }
}

void getPts(Point *pts, int *count){
    printf("how many point: ");
    scanf("%d", count);

    pts = malloc(*count*sizeof(Point));
    for(int i=0; i<*count; i++){
        int x,y;
        printf("enter point %d (x, y): ", i);
        scanf("%d%d", &x, &y);
        pts[i] = new_Point(x,y);
    }
}

void getCenter(Point *center, Point pts[], int count)
{
    /* int sumX =0;
    int sumY=0;
    int i;
    for(i=0; i<count; i++){
        sumX += pts[i].x;
        sumY += pts[i].y;
    }
    center->x = sumX/count;
    center->y = sumY/count; */
    center->x = 0;
    center->y = 0;
    for (int i = 0; i < count; i++)
    {
        center->x += pts[i].x;
        center->y += pts[i].y;
    }
    center->x /= count;
    center->y /= count;
}

// when using scanf, can't compile by vs studio code extension, have to use terminal
// remember this

int main(void)
{
    int count;
    Point *pts;
    printf("how many point: ");
    scanf("%d", &count);

    pts = malloc(count*sizeof(Point));
    for(int i=0; i<count; i++){
        int x,y;
        printf("enter point %d (x, y): ", i);
        scanf("%d%d", &x, &y);
        pts[i] = new_Point(x,y);
    }

    //getPts(pts, &count);
    
    printPts(pts, count);

    Point center;
    getCenter(&center, pts, count);
    printf("center is (%d,%d)\n", center.x, center.y);

    

    
    return EXIT_SUCCESS;
}