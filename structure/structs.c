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
    center->y = sumY/count;  */
    for(int i=0;i<count;i++){
        center->x += pts[i].x;
        center->y += pts[i].y;
    }
    center->x /=count;
    center->y /=count;
}

int main(void)
{
    struct _Point pt1;
    pt1.x = 18;
    pt1.y = 29;

    Point pt2;
    pt2.x = 6;
    pt2.y = 9;

   // struct _Point pt3 = {4,8};
   Point pt3 = {2,1};
//#ifdef DEBUG
    printf("point 1: (%d, %d)\n", pt1.x, pt1.y);
//#endif
    printf("point 2: (%d, %d)\n", pt2.x, pt2.y );
    printf("Point 3: (%d, %d)\n", pt3.x, pt3.y);

    Point pts[3];
    //pts[0] = {10,20}; //this is wrong, we can't declare new Point this way
    pts[0] = pt1;
    pts[1] = pt2;
    pts[2] = pt3;

    Point center;

    getCenter(&center, pts, 3);

    printf("the center is (%d, %d)\n", center.x, center.y);

    Point pt4 = new_Point(9,7);
    printf("this point was created by constructor\n");
    printf("Point 4: (%d, %d) \n", pt4.x, pt4.y);

    

    
    return EXIT_SUCCESS;
}