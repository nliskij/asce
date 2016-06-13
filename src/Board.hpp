#ifndef __ASCE_BOARD_HPP
#define __ASCE_BOARD_HPP
#include <iostream>
#include <cstdint>

typedef uint64_t BitBoard;
#define BIT_BOARD_LITERAL(A, B, C, D, E, F, G, H) 0b##A##B##C##D##E##F##G##H

class Board {
public:
  Board();
  Move parseMove(std::string algNotation, Color color);
  bool isLegal(Move mv);
  void makeMove();
  BitBoard getWPawns() const;
  BitBoard getWKnights() const;
  BitBoard getWBishops() const;
  BitBoard getWRooks() const;
  BitBoard getWQueens() const;
  BitBoard getWKing() const;
  BitBoard getBPawns() const;
  BitBoard getBKnights() const;
  BitBoard getBBishops() const;
  BitBoard getBRooks() const;
  BitBoard getBQueens() const;
  BitBoard getBKing() const;
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
private:
  BitBoard wPieces;
  BitBoard bPieces;
  BitBoard allPieces;
};

bool getBit(BitBoard b, int col, int row);
bool getBit(BitBoard b, std::string coord);

std::ostream &operator<<(std::ostream &os, const Board& b);

const BitBoard kFullBoard = 0xffffffffffffffffULL;
const BitBoard kEmptyBoard = 0ULL;
const BitBoard kHFile = BIT_BOARD_LITERAL(
                         10000000,
                         10000000,
                         10000000,
                         10000000,
                         10000000,
                         10000000,
                         10000000,
                         10000000);
const BitBoard kAFile = BIT_BOARD_LITERAL(
                         00000001,
                         00000001,
                         00000001,
                         00000001,
                         00000001,
                         00000001,
                         00000001,
                         00000001);
#endif
