#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"
#include <unistd.h>
#include <math.h>

int main(){
    int grid1[ROWS][COLS] ={
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int grid2[ROWS][COLS] =  {
            {0, 0, 8, 7, 0, 6, 2, 0, 0},
            {0, 0, 7, 0, 1, 0, 3, 0, 0},
            {0, 0, 0, 4, 0, 0, 0, 0, 0},
            {3, 0, 0, 0, 0, 0, 6, 0, 9},
            {0, 6, 0, 0, 7, 0, 0, 5, 0},
            {1, 0, 5, 0, 0, 0, 0, 0, 2},
            {0, 0, 0, 0, 0, 7, 0, 0, 0},
            {0, 0, 1, 0, 6, 0, 8, 0, 0},
            {0, 0, 4, 2, 0, 5, 7, 0, 0},
    };
    printf("Initial Grid \n");
    printGrid(grid2,ROWS,COLS);
    printf("\n");
    solver(grid2);   
    return (0);
}
/* ============= Very Important To Explain How We Validate The Grid*/
//    printf("Position %d ,%d is %s \n",0,0,(valid(grid,1,1,4)) ? "Valid" : "Not Valid");