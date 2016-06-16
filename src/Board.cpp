#include "Board.hpp"

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

std::ostream &operator<<(std::ostream &os, const Board& b) {
  for (auto row = 0; row < 8; ++row) {
    for (auto col = 0; col < 8; ++col) {
      char piece = '.';
      if (getBit(b.getBKing(), col, row)) {
        piece = 'k';
      } else if (getBit(b.getWKing(), col, row)) {
        piece = 'K';
      } else if (getBit(b.getBQueens(), col, row)) {
        piece = 'q';
      } else if (getBit(b.getWQueens(), col, row)) {
        piece = 'Q';
      } else if (getBit(b.getBBishops(), col, row)) {
        piece = 'b';
      } else if (getBit(b.getWBishops(), col, row)) {
        piece = 'B';
      } else if (getBit(b.getBKnights(), col, row)) {
        piece = 'n';
      } else if (getBit(b.getWKnights(), col, row)) {
        piece = 'N';
      } else if (getBit(b.getBRooks(), col, row)) {
        piece = 'r';
      } else if (getBit(b.getWRooks(), col, row)) {
        piece = 'R';
      } else if (getBit(b.getBPawns(), col, row)) {
        piece = 'p';
      } else if (getBit(b.getWPawns(), col, row)) {
        piece = 'P';
      }

      os << piece << " ";
    }
    os << std::endl;
  }
  return os;
}
