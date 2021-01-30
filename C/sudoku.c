#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
//  ======================================= Bug Hunting =======================================
void printMessage();
//  ======================================= Bug Hunting =======================================

//  ======================================= Grid Methods =======================================

void printGrid(int grid[][COLS],int rows,int cols){
    for(int i =0;i < rows;i++){
        for(int j=0;j < cols;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
void printData(int data[],int size){
     for(int i=0;i < size;i++){
            printf("%d ",data[i]);
        }
        printf("\n");
}

void setCols(int grid[][COLS],int *array,int col){
    for(int i = 0;i < COLS;i++){
        array[i] = grid[i][col];
    }
}
void setRows(int grid[][COLS],int *array,int row){
    for(int i = 0;i < ROWS;i++){
        array[i] = grid[row][i];
    }
}

//  ======================================= Grid Methods =======================================



//  ======================================= Algorithm Methods =======================================
bool compare(const void *a,const void *b){
    return (*(int *)a == *(int *)b);
}
bool contains(void *arr,int arr_size,int ele_size,void *x,bool compare(const void *,const void *)){
    char *ptr = (char *) arr;
    int i;
    for(i = 0;i < arr_size;i++)
        if(compare(ptr+i * ele_size,x))
            return true;
    
    return false;
}

bool validate(int grid[][COLS],int row,int col,int key){
    int subRow = (int) floor(row / 3) * 3;
    int subCol = (int) floor(col / 3) * 3;
    for(int i =0;i < 3;i++){
        for(int j =0;j < 3;j++){
            if(grid[subRow + i][subCol + j] == key){
                return false;
            }
        }
    }
    return true;
}

bool valid(int grid[][COLS],int row,int col, int key){
    if(row < ROWS && col < COLS){
        int rows[ROWS];
        int cols[COLS];
        setRows(grid,rows,row);
        setCols(grid,cols,col);
        if(!contains(rows,ROWS,sizeof(int),&key,compare) && !contains(cols,COLS,sizeof(int),&key,compare) && validate(grid,row,col,key)){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

void solver(int grid[][COLS]){
    
    for(int i =0; i < ROWS;i++){
        for(int j = 0;j < COLS;j++){
            if(grid[i][j] == 0){
                // Decision Space
                for(int x = 1; x <= 9;x++){
                    if(valid(grid,i,j,x)){
                        grid[i][j] = x;
                        solver(grid);
                        grid[i][j] = 0;
                    }
                }
                return ;
            }
        }
    }
    printf("Solved Sudoku: \n");
    printGrid(grid,ROWS,COLS);
}
//  ======================================= Algorithm Methods =======================================