#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdint.h>

int movePiece(uint64_t* playerPieces, uint64_t* opponentPieces, int startRow, int startCol, int endRow, int endCol);
void promoteKing(uint64_t* playerPieces, uint64_t* playerKings, int endRow, int endCol, int player);
int isCaptureMove(uint64_t playerPieces, uint64_t opponentPieces, int startRow, int startCol, int endRow, int endCol);
int capturePiece(uint64_t* playerPieces, uint64_t* opponentPieces, int startRow, int startCol, int endRow, int endCol);

#endif
