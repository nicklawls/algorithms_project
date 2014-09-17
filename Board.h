#ifndef __BOARD__
#define __BOARD__

#include <vector>

class Board {
private:
  int column_depth;
  int row_length;
  std::vector<std::vector<int>> cells;

public:
  Board(int, int);
  int length() const;
  int depth() const;
  void fill();
  int get_cell(int, int) const;
  void set_cell(int, int, int);
  void print();
};

#endif
