#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 10

int main(void){
    for(int row=0; row < NUM_ROWS; row++){
        for(int col=0; col < NUM_COLS; col++ ){
            printf("%d\t", row*NUM_COLS + col);
        }
        printf("\n");
    
    }

    return EXIT_SUCCESS;
}
