#ifndef __ASCE_MOVE_HPP
#define __ASCE_MOVE_HPP
#include <cstdint>

enum class Square : uint32_t {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8
};

enum class MoveFlag : uint16_t {
  KCastle,
  QCastle,
  EnPassant,
  QPromo,
  NPromo,
  BPromo,
  RPromo
};

class Move {
  // Don't know if this method of storage is needed
public:
  Move(Square from, Square to, MoveFlag flags) {
    moveBits = ((static_cast<uint32_t>(flags) & 0xf) << 12) |
        ((static_cast<uint32_t>(from) & 0x3f) << 6) |
        (static_cast<uint32_t>(to) & 0x3f);
  }

  uint32_t getTo() const {return moveBits & 0x3f;}
  uint32_t getFrom() const {return (moveBits >> 6) & 0x3f;}
  uint32_t getFlags() const {return (moveBits >> 12) & 0x0f;}

private:
  uint32_t moveBits;
};
#endif
