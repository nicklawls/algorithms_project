#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

// PROVIDE BOUNDS CHECKING SUITABLE TO USE CASES


Board::Board(int n, int m) :column_depth(n), row_length(m)
{
  for (int i = 0; i < column_depth; i++) {
    cells.push_back(vector<int>(row_length, 0));
  }
}


int Board::get_cell(int a, int b) const
{
  int value = cells.at(a).at(b);
  return value;
}

void Board::set_cell(int a, int b, int value)
{
  cells.at(a).at(b) = value;
}

void Board::print()
{
  for (auto row: cells) {
    for (auto cell: row) {
      cout << cell << " ";
    }
    cout << endl;
  }
}

int Board::length() const
{
  return row_length;
}
int Board::depth() const
{
  return column_depth;
}
