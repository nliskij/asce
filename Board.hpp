#ifndef __ASCE_BOARD_HPP
#define __ASCE_BOARD_HPP
#include <iostream>
#include <cstdint>

typedef uint64_t BitBoard;
#define BIT_BOARD_LITERAL(A, B, C, D, E, F, G, H) 0b##A##B##C##D##E##F##G##H

class Board {
public:
  Board();
  BitBoard getWPawns();
  BitBoard getWKnights();
  BitBoard getWBishops();
  BitBoard getWRooks();
  BitBoard getWQueens();
  BitBoard getWKing();
  BitBoard getBPawns();
  BitBoard getBKnights();
  BitBoard getBBishops();
  BitBoard getBRooks();
  BitBoard getBQueens();
  BitBoard getBKing();
  // Public for stupid reasons
  union { // Just some type punning to iterate through boards
    struct {
      BitBoard wPawns;
      BitBoard wKnights;
      BitBoard wBishops;
      BitBoard wRooks;
      BitBoard wQueens;
      BitBoard wKing;
      BitBoard bPawns;
      BitBoard bKnights;
      BitBoard bBishops;
      BitBoard bRooks;
      BitBoard bQueens;
      BitBoard bKing;
    };
    BitBoard bitBoards[12];
  };
};

bool getBit(BitBoard b, int col, int row);
bool getBit(BitBoard b, std::string col, int row);
bool getBit(BitBoard b, std::string coord);

std::ostream &operator<<(std::ostream &os, const Board& b);

const BitBoard fullBoard = 0xffffffffffffffffULL;
const BitBoard emptyBoard = 0ULL;
#endif
