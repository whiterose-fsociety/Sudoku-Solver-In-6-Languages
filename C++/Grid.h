#ifndef GRID_H
#define GRID_H
#include <iomanip>
class Grid{
 public:
  static const size_t ROWS{9};
  static const size_t COLS{9};
  static const size_t DECISION_SPACE{9};
  static void printGrid(const std::array<std::array<int,COLS>,ROWS>&);
  static void printData(const std::array<int,ROWS> &);
  static void convertTxtToGrid();
  static void setCols(const std::array<std::array<int,COLS>,ROWS>&,std::array<int,COLS> &,int col);
  static void setRows(const std::array<std::array<int,COLS>,ROWS>&,std::array<int,ROWS> &,int row);
 private:
};
#endif