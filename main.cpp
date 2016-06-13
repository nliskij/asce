#include "Board.hpp"

int main(void) {
  Board b = Board();
  std::cout << b;
  for (auto i = 0; i < 11; ++i) {
    std::cout << b.bitBoards[i] << std::endl;
  }

  return 0;
}
