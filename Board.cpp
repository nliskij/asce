#include "Board.hpp"
#include <iostream>
/* Board layout (flipped)
 * (a8)(b8)(c8)(d8)(e8)(f8)(g8)(h8)
 * (a7)(b7)(c7)(d7)(e7)(f7)(g7)(h7)
 * (a6)(b6)(c6)(d6)(e6)(f6)(g6)(h6)
 * (a5)(b5)(c5)(d5)(e5)(f5)(g5)(h5)
 * (a4)(b4)(c4)(d4)(e4)(f4)(g4)(h4)
 * (a3)(b3)(c3)(d3)(e3)(f3)(g3)(h3)
 * (a2)(b2)(c2)(d2)(e2)(f2)(g2)(h2)
 * (a1)(b1)(c1)(d1)(e1)(f1)(g1)(h1)
 */

Board::Board() {
  bPawns = BIT_BOARD_LITERAL(
              00000000,
              11111111,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000);
  bKnights = BIT_BOARD_LITERAL(
              01000010,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000);
  bBishops = BIT_BOARD_LITERAL(
              00100100,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000);
  bRooks = BIT_BOARD_LITERAL(
              10000001,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000);
  bQueens = BIT_BOARD_LITERAL(
              00001000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000);
  bKing = BIT_BOARD_LITERAL(
              00010000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000);
  wPawns = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              11111111,
              00000000);
  wKnights = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              01000010);
  wBishops = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00100100);
  wRooks = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              10000001);
  wQueens = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00010000);
  wKing = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00001000);
}

BitBoard Board::getWPawns() {
  return wPawns;
}
BitBoard Board::getWKnights() {
  return wKnights;
}
BitBoard Board::getWBishops() {
  return wBishops;
}
BitBoard Board::getWRooks() {
  return wRooks;
}
BitBoard Board::getWQueens() {
  return wQueens;
}
BitBoard Board::getWKing() {
  return wKing;
}
BitBoard Board::getBPawns() {
  return bPawns;
}
BitBoard Board::getBKnights() {
  return bKnights;
}
BitBoard Board::getBBishops() {
  return bBishops;
}
BitBoard Board::getBRooks() {
  return bRooks;
}
BitBoard Board::getBQueens() {
  return bQueens;
}
BitBoard Board::getBKing() {
  return bKing;
}

bool getBit(BitBoard b, int col, int row) {
  return (b >> (8 * row + col)) % 2;
}

bool getBit(BitBoard b, std::string col, int row) {
  return getBit(b, col.c_str()[0] - 'a', row - 1);
}

bool getBit(BitBoard b, std::string coord) {
  return getBit(b, coord[0], (int) coord.c_str()[1] - '0');
}

std::ostream &operator<<(std::ostream &os, const Board& b) {
  for (auto row = 0; row < 8; ++row) {
    for (auto col = 0; col < 8; ++col) {
      char piece = '.';
      for (auto i = 0; i < 12; ++i) {
        if (getBit(b.bitBoards[i], col, row)) {
          switch (i) {
            case 0:
              piece = 'p';
              break;
            case 1:
              piece = 'n';
              break;
            case 2:
              piece = 'b';
              break;
            case 3:
              piece = 'r';
              break;
            case 4:
              piece = 'q';
              break;
            case 5:
              piece = 'k';
              break;
            case 6:
              piece = 'P';
              break;
            case 7:
              piece = 'N';
              break;
            case 8:
              piece = 'B';
              break;
            case 9:
              piece = 'R';
              break;
            case 10:
              piece = 'Q';
              break;
            case 11:
              piece = 'K';
              break;
          }
        }
      }
      os << piece << " ";
    }
    os << std::endl;
  }
  return os;
}
