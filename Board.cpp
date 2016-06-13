#include "Board.hpp"
#include <cctype>

/*
Layout:
   HGFEDCBA
  8
  7
  6
  5
  4
  3
  1
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
  bKing = BIT_BOARD_LITERAL(
              00010000,
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
  wKing = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00010000);
  wQueens = BIT_BOARD_LITERAL(
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00000000,
              00001000);
  wPieces = wPawns | wRooks | wKnights | wBishops | wQueens | wKing;
  bPieces = bPawns | bRooks | bKnights | bBishops | bQueens | bKing;
  allPieces = wPieces | bPieces;
}

BitBoard Board::getWPawns() const {
  return wPawns;
}
BitBoard Board::getWKnights() const {
  return wKnights;
}
BitBoard Board::getWBishops() const {
  return wBishops;
}
BitBoard Board::getWRooks() const {
  return wRooks;
}
BitBoard Board::getWQueens() const {
  return wQueens;
}
BitBoard Board::getWKing() const {
  return wKing;
}
BitBoard Board::getBPawns() const {
  return bPawns;
}
BitBoard Board::getBKnights() const {
  return bKnights;
}
BitBoard Board::getBBishops() const {
  return bBishops;
}
BitBoard Board::getBRooks() const {
  return bRooks;
}
BitBoard Board::getBQueens() const {
  return bQueens;
}
BitBoard Board::getBKing() const {
  return bKing;
}

bool getBit(BitBoard b, int col, int row) {
  return ((b >> (8 * row + col)) % 2);
}

bool getBit(BitBoard b, std::string coord) {
  return getBit(b, (int) coord[0] - 'a', (int) coord.c_str()[1] - '1');
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
