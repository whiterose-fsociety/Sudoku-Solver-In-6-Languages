#include <iostream>
#include <array>
#include <cmath>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(const array<array<int,Grid::COLS>,Grid::ROWS>& grid) : sudokuGrid(grid){}
const array<array<int,Grid::COLS>,Grid::ROWS>& Sudoku::getSudokuGrid() const{
    return sudokuGrid;
}

bool Sudoku::contains(array<int,Grid::ROWS> &array,int key){
    for(size_t i{0};i < array.size();++i){
        if(array[i] == key ){
            return true;
        }
    }
    return false;
}

bool Sudoku::canPlaceInSubGrid(const std::array<std::array<int,Grid::COLS>,Grid::ROWS>& grid,int row,int col,int key) const{
    int subRow = (int) floor(row / 3) * 3;  // static_cast<int> (floor(row / 3) * 3);
    int subCol = (int) floor(col / 3) * 3;
    for(size_t i{0}; i < 3;++i){
        for(size_t j{0};j < 3;j++){
            if(grid[subRow + i][subCol + j] == key){
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::canPlaceInSudoku(std::array<std::array<int,Grid::COLS>,Grid::ROWS>& grid,int row,int col,int key) const{
    if(row < Grid::ROWS && col < Grid::COLS){
        std::array<int,Grid::ROWS> rows; // C - int rows[ROWS];
        std::array<int,Grid::COLS> cols;
        Grid::setRows(grid,rows,row);
        Grid::setCols(grid,cols,col);
        if(!contains(rows,key) && !contains(cols,key) && canPlaceInSubGrid(grid,row,col,key)){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

void Sudoku::solveSudoku(std::array<std::array<int,Grid::COLS>,Grid::ROWS>& grid){
    for(size_t i{0};i < Grid::ROWS;i++){
        for(size_t j{0};j < Grid::COLS;j++){
            if(grid[i][j] == 0){
                for(int x = 1;x<=Grid::DECISION_SPACE;x++){
                    if(canPlaceInSudoku(grid,i,j,x)){
                        grid[i][j] = x;
                        solveSudoku(grid);
                        grid[i][j] = 0;
                    }
                }
                return ;
            }
        }
    }
    cout << "Solved Sudoku" << endl;
    Grid::printGrid(grid);
}
