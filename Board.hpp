#ifndef __ASCE_BOARD_HPP
#define __ASCE_BOARD_HPP
#include <iostream>
#include <cstdint>

typedef uint64_t BitBoard;
#define BIT_BOARD_LITERAL(A, B, C, D, E, F, G, H) 0b##A##B##C##D##E##F##G##H

enum Square {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8
};

enum Color {
  White = 0, Black
};

enum PieceType {
  Pawn, Rook, Knight, Bishop, Queen, King
};

struct Piece {
  Piece(PieceType t, Color c);
  PieceType type;
  Color color;
};

enum MoveType {
  Normal, KCastle, QCastle, EnPassant
};

struct Move {
  Move(MoveType t, Square o, Square d);
  MoveType type;
  Square origin;
  Square dest;
};

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
