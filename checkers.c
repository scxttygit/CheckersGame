#include <stdio.h>
#include <stdint.h>
#include "utilities.h"
#include "utilities.c"

#define BOARD_SIZE 8

uint64_t blackPieces, redPieces;
uint64_t blackKings, redKings;

void initializeBitboards();
void printBoard();
int letterToColumn(char colLetter);

void initializeBitboards() {
    blackPieces = 0x0000000000AA55AAULL;
    redPieces = 0x55AA550000000000ULL;
    blackKings = 0;
    redKings = 0;
}

// the board
void printBoard() {
    printf("    A   B   C   D   E   F   G   H\n");
    printf("  +---+---+---+---+---+---+---+---+\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d | ", row + 1);  // Print row number
        for (int col = 0; col < BOARD_SIZE; col++) {
            int bitIndex = row * 8 + col;
            if ((row + col) % 2 == 0) {
                printf("  | ");  // Light squares are not playable
            } else if (blackPieces & (1ULL << bitIndex)) {
                printf("O | ");
            } else if (redPieces & (1ULL << bitIndex)) {
                printf("X | ");
            } else if (blackKings & (1ULL << bitIndex)) {
                printf("K | ");
            } else if (redKings & (1ULL << bitIndex)) {
                printf("Q | ");
            } else {
                printf("  | ");  // Empty playable square
            }
        }
        printf("%d\n", row + 1);  // Print row number on the right side
        printf("  +---+---+---+---+---+---+---+---+\n");
    }

    printf("    A   B   C   D   E   F   G   H\n");  // Column letters again at the bottom
}


int letterToColumn(char colLetter) {
    return colLetter - 'A';
}

int main() {
    initializeBitboards();
    char startColLetter, endColLetter;
    int startRow, endRow, player = 1;  // 1 = black, 2 = red

    while (1) {
        printBoard();
        printf("Player %d's turn (%s).\n", player, player == 1 ? "O" : "X");
        printf("Enter move (ex., 2 A 3 B): ");
        scanf("%d %c %d %c", &startRow, &startColLetter, &endRow, &endColLetter);

        startRow -= 1;
        endRow -= 1;
        int startCol = letterToColumn(startColLetter);
        int endCol = letterToColumn(endColLetter);

        if (player == 1) {
    if (isCaptureMove(blackPieces, redPieces, startRow, startCol, endRow, endCol)) {
        // Perform the capture
        if (capturePiece(&blackPieces, &redPieces, startRow, startCol, endRow, endCol)) {
            promoteKing(&blackPieces, &blackKings, endRow, endCol, player);
            player = 2;  // Switch to red player
        } else {
            printf("Invalid capture move, try again.\n");
        }
    } else if (movePiece(&blackPieces, &redPieces, startRow, startCol, endRow, endCol)) {
        promoteKing(&blackPieces, &blackKings, endRow, endCol, player);
        player = 2;  // Switch to red player
    } else {
        printf("Invalid move, try again.\n");
    }
} else {
    if (isCaptureMove(redPieces, blackPieces, startRow, startCol, endRow, endCol)) {
        // Perform the capture
        if (capturePiece(&redPieces, &blackPieces, startRow, startCol, endRow, endCol)) {
            promoteKing(&redPieces, &redKings, endRow, endCol, player);
            player = 1;  // Switch to black player
        } else {
            printf("Invalid capture move, try again.\n");
        }
    } else if (movePiece(&redPieces, &blackPieces, startRow, startCol, endRow, endCol)) {
        promoteKing(&redPieces, &redKings, endRow, endCol, player);
        player = 1;  // Switch to black player
    } else {
        printf("Invalid move, try again.\n");
    }
}
    }

    return 0;
}
