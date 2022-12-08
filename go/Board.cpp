#include "Board.h"
#include"conio2.h"

#include <array>
#include <cstdint>
#include <string>
#include <vector>


struct Point {
	int x, y;
};


struct Move {
	Point point;
	int player;  // 1 for black, 2 for white
};


Board::Board() {
	for (int i = 0; i < 9; i++) {
		//for (int j = 0; j < boardSize; j++) {
		//board[i][j] = 0;
		board[i] = 0;
		//}
	}
}


void Board::printBoard() {
	for (int columnIndex = 1; columnIndex <= BOARD_SIZE + 2; columnIndex++) {
		gotoxy(columnIndex, 1);
		putch('-');
	}

	for (int rowIndex = 1; rowIndex <= BOARD_SIZE + 2; rowIndex++) {
		gotoxy(1, rowIndex);
		putch('|');
	}

	for (int rowIndex = 1; rowIndex <= BOARD_SIZE + 2; rowIndex++) {
		gotoxy(BOARD_SIZE + 2, rowIndex);
		putch('|');
	}

	for (int columnIndex = 1; columnIndex <= BOARD_SIZE + 2; columnIndex++) {
		gotoxy(columnIndex, BOARD_SIZE + 2);
		putch('-');
	}

	for (int rowIndex = 2; rowIndex < BOARD_SIZE + 2; rowIndex++) {
		for (int columnIndex = 2; columnIndex < BOARD_SIZE + 2; columnIndex++) {
			gotoxy(columnIndex, rowIndex);
			putch('+');
		}
	}
}
	

//class Board {
//public:
//	// Constructs a new Go board with the given dimensions.
//	Board(int width, int height):
//		width_(width),
//		height_(height),
//		current_player_(1),
//		board_(height, std::vector<int>(width, 0)) {}
//
//	// Returns the width of the board.
//	int Width() const { return width_; }
//
//	// Returns the height of the board.
//	int Height() const { return height_; }
//
//	// Returns the current player (1 for black, 2 for white).
//	int CurrentPlayer() const { return current_player_; }
//
//	// Returns the state of the board at the given point.
//	// 0 indicates an empty point, 1 indicates a black stone,
//	// and 2 indicates a white stone.
//	int GetState(const Point& point) const {
//		return board_[point.y][point.x];
//	}
//
//	// Makes a move on the board for the current player at the given point.
//  // Returns true if the move is successful, or false if the move is invalid.
//	bool MakeMove(const Point& point) {
//		// Check if the point is within the bounds of the board.
//		if (point.x < 0 || point.x >= width_ || point.y < 0 || point.y >= height_) {
//			return false;
//		}
//
//		// Check if the point is already occupied.
//		if (board_[point.y][point.x] != 0) {
//			return false;
//		}
//
//		// Make the move.
//		board_[point.y][point.x] = current_player_;
//		moves_.push_back({ point, current_player_ });
//		current_player_ = 3 - current_player_;  // Switch to the other player.
//		return true;
//	}
//
//	// Undoes the last move made on the board.
//	void UndoMove() {
//		if (moves_.empty()) {
//			return;
//		}
//
//		auto last_move = moves_.back();
//		moves_.pop_back();
//		board_[last_move.point.y][last_move.point.x] = 0;
//		current_player_ = last_move.player;
//	}
//
//	// Returns a string representation of the board.
//	std::string ToString() const;
//
//
//
//private:
//	int width_, height_;
//	int current_player_;
//	std::vector<Move> moves_;
//	std::vector<std::vector<int>> board_;
//};