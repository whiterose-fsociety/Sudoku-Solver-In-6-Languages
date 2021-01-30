#ifndef SUDOKU_H
#define SUDOKU_H
#include <iomanip>
#include "Grid.h"
class Sudoku{
 public:
    Sudoku(const std::array<std::array<int,Grid::COLS>,Grid::ROWS>&);
    const std::array<std::array<int,Grid::COLS>,Grid::ROWS>& getSudokuGrid() const;
    static bool contains(std::array<int,Grid::ROWS> &,int key);
    bool canPlaceInSubGrid(const std::array<std::array<int,Grid::COLS>,Grid::ROWS>&,int row,int col,int key) const;
    bool canPlaceInSudoku(std::array<std::array<int,Grid::COLS>,Grid::ROWS>&,int row,int col,int key) const;
    void solveSudoku(std::array<std::array<int,Grid::COLS>,Grid::ROWS>&);
 private:
    std::array<std::array<int,Grid::COLS>,Grid::ROWS> sudokuGrid;
  

};
#endif