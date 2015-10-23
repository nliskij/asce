#include <stdio.h>
#include <stdlib.h>

typedef uint64_t bitboard_t

typedef struct board {
    bitboard_t w_pawns;
    bitboard_t w_knights;
    bitboard_t w_bishops;
    bitboard_t w_rooks;
    bitboard_t w_queens;
    bitboard_t w_king;
    bitboard_t b_pawns;
    bitboard_t b_knights;
    bitboard_t b_bishops;
    bitboard_t b_rooks;
    bitboard_t b_queens;
    bitboard_t b_king;
} board_t;

int main(int argc, char *argv[])
{
    return 0;
}
