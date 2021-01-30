#include <iostream>
#include "Sudoku.h"
#include "Grid.h"
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;


int main(){
    std::array<std::array<int, Grid::COLS>, Grid::ROWS> grid{
    5, 3, 0, 0, 7, 0, 0, 0, 0,
    6, 0, 0, 1, 9, 5, 0, 0, 0,
    0, 9, 8, 0, 0, 0, 0, 6, 0,
    8, 0, 0, 0, 6, 0, 0, 0, 3,
    4, 0, 0, 8, 0, 3, 0, 0, 1,
    7, 0, 0, 0, 2, 0, 0, 0, 6,
    0, 6, 0, 0, 0, 0, 2, 8, 0,
    0, 0, 0, 4, 1, 9, 0, 0, 5,
    0, 0, 0, 0, 8, 0, 0, 7, 9
    };
    
    Sudoku firstSudoku(grid);
    cout << "Initial Grid" << endl;
    Grid::printGrid(firstSudoku.getSudokuGrid());
    cout << endl;
    firstSudoku.solveSudoku(grid);
    return 0;
}