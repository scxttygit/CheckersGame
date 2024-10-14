#include "utilities.h"

int movePiece(uint64_t* playerPieces, uint64_t* opponentPieces, int startRow, int startCol, int endRow, int endCol) {
    int startIndex = startRow * 8 + startCol;
    int endIndex = endRow * 8 + endCol;

    if ((*playerPieces & (1ULL << startIndex)) == 0) {
        return 0;  // No piece to move
    }

    *playerPieces &= ~(1ULL << startIndex);  // Clear start bit
    *playerPieces |= (1ULL << endIndex);     // Set end bit

    return 1;
}

// Promote a piece to king if it reaches the opposite end
void promoteKing(uint64_t* playerPieces, uint64_t* playerKings, int endRow, int endCol, int player) {
    int endIndex = endRow * 8 + endCol;
    if ((player == 1 && endRow == 7) || (player == 2 && endRow == 0)) {
        // Promote to king (transfer from pieces to kings bitboard)
        *playerKings |= *playerPieces & (1ULL << endIndex);  // Set king bit
        *playerPieces &= ~(1ULL << endIndex);  // Remove from regular pieces
    }
}

// Check if a capture is valid
int isCaptureMove(uint64_t playerPieces, uint64_t opponentPieces, int startRow, int startCol, int endRow, int endCol) {
    int middleRow = (startRow + endRow) / 2;
    int middleCol = (startCol + endCol) / 2;
    int middleIndex = middleRow * 8 + middleCol;

    return (opponentPieces & (1ULL << middleIndex)) != 0;  // Opponent's piece must be in the middle
}

// Capture an opponent's piece
int capturePiece(uint64_t* playerPieces, uint64_t* opponentPieces, int startRow, int startCol, int endRow, int endCol) {
    int startIndex = startRow * 8 + startCol;
    int endIndex = endRow * 8 + endCol;
    int middleRow = (startRow + endRow) / 2;
    int middleCol = (startCol + endCol) / 2;
    int middleIndex = middleRow * 8 + middleCol;

    // Make sure there is an opponent's piece to capture
    if (!isCaptureMove(*playerPieces, *opponentPieces, startRow, startCol, endRow, endCol)) {
        return 0;
    }

    // Clear the captured piece from the opponent's bitboard
    *opponentPieces &= ~(1ULL << middleIndex);  // Remove the opponent's piece

    // Move the player's piece
    *playerPieces &= ~(1ULL << startIndex);  // Clear start bit
    *playerPieces |= (1ULL << endIndex);     // Set end bit

    return 1;
}
