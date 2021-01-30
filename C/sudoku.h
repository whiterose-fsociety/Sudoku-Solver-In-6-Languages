#ifndef SUDOKU_H
#define SUDOKU_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define ROWS 9
#define COLS 9
//  ======================================= Bug Hunting =======================================
void printMessage();
//  ======================================= Bug Hunting =======================================

//  ======================================= Grid Methods =======================================
void printGrid(int grid[][COLS],int rows,int cols);
void printData(int data[],int size);
void setCols(int grid[][COLS],int *array,int col);
void setRows(int grid[][COLS],int *array,int row);


//  ======================================= Grid Methods =======================================



//  ======================================= Algorithm Methods =======================================
bool compare(const void *a,const void *b);
bool contains(void *arr,int arr_size,int ele_size,void *x,bool compare(const void *,const void *));
bool validate(int grid[][COLS],int row,int col,int key);
bool valid(int grid[][COLS],int row,int col, int key);
void solver(int grid[][COLS]);
//  ======================================= Algorithm Methods =======================================
#endif