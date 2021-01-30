#include <iostream>
#include <array>
#include "Grid.h"
using namespace std;

void Grid::printGrid(const array<array<int,COLS>,ROWS>& grid){
    for(const auto& row: grid){
        for(const auto& cell: row){
            cout << cell << " ";
        }
        cout << endl;
    }
}

void  Grid::printData(const array<int,ROWS> &data){
    for(const auto& item: data){
        cout << item << " ";
    }
    cout << endl;
}
void  Grid::setCols(const array<array<int,COLS>,ROWS>& grid,array<int,COLS> &data,int col){
    for(size_t i{0};i < COLS;i++){
        data[i] = grid[i][col];
    }
}
void  Grid::setRows(const array<array<int,COLS>,ROWS>& grid,array<int,ROWS> &data,int row){
for(size_t i{0};i < COLS;i++){
        data[i] = grid[row][i];
    }
}

