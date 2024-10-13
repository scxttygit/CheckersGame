Checkers Game in C

Overview

This project is a terminal-based implementation of the classic Checkers game, written in the C programming language. The game utilizes bitwise operations and binary arithmetic to efficiently manage the game state, allowing for fast and memory-efficient processing. The game supports standard Checkers rules, including piece movement, capturing opponent pieces, and promotion to kings.

The project includes a modular design with a utility class (utilities.c) for handling key operations such as moving pieces, promoting kings, and handling captures. This approach ensures clean, reusable code, making it easier to maintain and extend the functionality.

Key Features:

	•	Two-player game, alternating turns between Player 1 (black pieces) and Player 2 (red pieces).
	•	Pieces are represented on the board using bitwise operations.
	•	Supports all key Checkers features: movement, capturing, and promotion to kings.
	•	Memory-efficient game state representation using 64-bit integers (bitboards).

Project Structure

This project consists of the following files:

/Checkers-Game/
├── checkers.c         # Main game logic file
├── utilities.c        # Utility functions file
├── utilities.h        # Header file for utility functions
├── README.md          # This README file

File Descriptions:

	•	checkers.c: This file contains the main game loop, handles user input, and manages the overall game flow. It calls functions from the utilities module for all bitwise operations like moving, capturing, and promoting pieces.
	•	utilities.c: This file defines the core utility functions that manipulate the game state using bitwise operations. The functions include moving pieces, checking for valid captures, promoting pieces to kings, and removing captured pieces.
	•	utilities.h: This is the header file that declares the utility functions used by checkers.c. It ensures the separation between the game logic and the bitwise manipulation of the game state.

How to Run

Prerequisites:

	•	C compiler (e.g., GCC).
	•	Terminal or command-line interface.

Steps to Run:

	1.	Clone the repository:

git clone https://github.com/yourusername/Checkers-Game.git
cd Checkers-Game


	2.	Compile the code:
Compile both checkers.c and utilities.c files together using GCC:

gcc checkers.c utilities.c -o checkers_game


	3.	Run the game:
Run the executable file in your terminal:

./checkers_game


Gameplay Instructions:

	•	Player 1 (black pieces represented by O) and Player 2 (red pieces represented by X) take alternating turns.
	•	To move a piece, enter the start and end positions in the format: 2 A 3 B (moves the piece from row 2, column A to row 3, column B).
	•	The game will automatically handle captures and promotions to kings.
	•	Kings are represented by K for Player 1 and Q for Player 2.

Game Rules

	•	Pieces: Player 1 uses black pieces (O), and Player 2 uses red pieces (X).
	•	Moves: Pieces can only move diagonally on dark squares.
	•	Captures: A piece captures an opponent’s piece by jumping over it. The captured piece is removed from the board.
	•	Promotion to Kings: If a piece reaches the opposite side of the board, it is promoted to a king and can move both forward and backward diagonally.

Bitwise Operations and Binary Arithmetic

The game uses bitboards to represent the state of the board. Each 64-bit integer corresponds to an 8x8 board, where each bit represents a square. Binary arithmetic and hexadecimal values are used to initialize the board and perform game operations.

	•	Hexadecimal Representation: The game pieces’ starting positions are represented using hexadecimal values. For example, 0x0000000000AA55AAULL represents the black pieces’ starting positions on rows 1-3.
	•	Bitwise Operations:
	•	AND (&): Used to check if a square is occupied by a piece.
	•	OR (|): Used to move pieces or promote pieces to kings.
	•	NOT (~): Used to clear a square when a piece is moved or captured.

By using bitwise operations, we ensure efficient manipulation of the game state, making the game faster and using minimal memory.

Future Improvements

	•	Enhanced Rule Enforcement: Adding support for forced captures and additional rule validations.
	•	Graphical Interface: Implement a graphical user interface (GUI) for a more user-friendly experience.
	•	Save/Load Game: Implement functionality to save and load game states, allowing players to resume the game later.
	•	AI Opponent: Add a single-player mode with an AI opponent.
