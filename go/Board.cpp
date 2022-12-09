#include "Board.h"


Board::Board(Player player1, Player player2) {
	this->boardSize = BOARD_SIZE;
	
	for (int i = 0; i < this->boardSize; i++) {
		for (int j = 0; j < this->boardSize; j++) {
			board[i][j] = 0;
		}
	}
	
	this->currentPlayer = player1;
	this->player1 = player1;
	this->player2 = player2;
}


void Board::printBoard() {
	Board::printTopAndBottomBorder();
	Board::printLeftAndRightBorder();

	Board::printBoardStructure();

	Board::printBorderCorners();
	Board::printBoardCorners();

	this->printBoardState();
}

void Board::printTopAndBottomBorder() {
	for (int columnIndex = LEFT_BOARD_BORDER_X + 1; columnIndex <= RIGHT_BOARD_BORDER_X - 1; columnIndex++) {
		gotoxy(columnIndex, TOP_BOARD_BORDER_Y);
		putch(DOUBLE_HORIZONTAL_LINE_CODE);

		gotoxy(columnIndex, BOTTOM_BOARD_BORDER_Y);
		putch(DOUBLE_HORIZONTAL_LINE_CODE);

		if (columnIndex % 2 == 1) {
			gotoxy(columnIndex, TOP_BOARD_BORDER_Y + 1);
			putch(TOP_INTERSECTION_CHARACTER_CODE);

			gotoxy(columnIndex, BOTTOM_BOARD_BORDER_Y - 1);
			putch(BOTTOM_INTERSECTION_CHARACTER_CODE);
		}
		else if (columnIndex > LEFT_BOARD_BORDER_X + 2 and columnIndex < RIGHT_BOARD_BORDER_X - 2) {
			gotoxy(columnIndex, TOP_BOARD_BORDER_Y + 1);
			putch(HORIZONTAL_LINE_CHARACTER_CODE);

			gotoxy(columnIndex, BOTTOM_BOARD_BORDER_Y - 1);
			putch(HORIZONTAL_LINE_CHARACTER_CODE);
		}
	}
}

void Board::printLeftAndRightBorder() {
	for (int rowIndex = TOP_BOARD_BORDER_Y + 1; rowIndex <= BOTTOM_BOARD_BORDER_Y - 1; rowIndex++) {
		gotoxy(LEFT_BOARD_BORDER_X, rowIndex);
		putch(DOUBLE_VERTICAL_LINE_CODE);

		gotoxy(RIGHT_BOARD_BORDER_X, rowIndex);
		putch(DOUBLE_VERTICAL_LINE_CODE);

		gotoxy(LEFT_BOARD_BORDER_X + 2, rowIndex);
		putch(LEFT_INTERSECTION_CHARACTER_CODE);

		gotoxy(RIGHT_BOARD_BORDER_X - 2, rowIndex);
		putch(RIGHT_INTERSECTION_CHARACTER_CODE);
	}
}

void Board::printBoardStructure() {
	for (int rowIndex = TOP_BOARD_BORDER_Y + 2; rowIndex < BOTTOM_BOARD_BORDER_Y - 1; rowIndex++) {
		for (int columnIndex = LEFT_BOARD_BORDER_X + 4; columnIndex < RIGHT_BOARD_BORDER_X - 2; columnIndex += 2) {
			gotoxy(columnIndex, rowIndex);
			putch(INTERSECTION_CHARACTER_CODE);
		}
	}

	// fill gaps between rows
	for (int rowIndex = TOP_BOARD_BORDER_Y + 2; rowIndex < BOTTOM_BOARD_BORDER_Y - 1; rowIndex++) {
		for (int columnIndex = LEFT_BOARD_BORDER_X + 4; columnIndex < RIGHT_BOARD_BORDER_X; columnIndex += 2) {
			gotoxy(columnIndex - 1, rowIndex);
			putch(HORIZONTAL_LINE_CHARACTER_CODE);
		}
	}
}

void Board::printBorderCorners() {
	gotoxy(LEFT_BOARD_BORDER_X, TOP_BOARD_BORDER_Y);
	putch(TOP_LEFT_DOUBLE_LINE_CORNER_CODE);

	gotoxy(LEFT_BOARD_BORDER_X, BOTTOM_BOARD_BORDER_Y);
	putch(BOTTOM_LEFT_DOUBLE_LINE_CORNER_CODE);

	gotoxy(RIGHT_BOARD_BORDER_X, TOP_BOARD_BORDER_Y);
	putch(TOP_RIGHT_DOUBLE_LINE_CORNER_CODE);

	gotoxy(RIGHT_BOARD_BORDER_X, BOTTOM_BOARD_BORDER_Y);
	putch(BOTTOM_RIGHT_DOUBLE_LINE_CORNER_CODE);
}

void Board::printBoardCorners() {
	gotoxy(LEFT_BOARD_BORDER_X + 2, TOP_BOARD_BORDER_Y + 1);
	putch(TOP_LEFT_LINE_CORNER_CODE);

	gotoxy(LEFT_BOARD_BORDER_X + 2, BOTTOM_BOARD_BORDER_Y - 1);
	putch(BOTTOM_LEFT_LINE_CORNER_CODE);

	gotoxy(RIGHT_BOARD_BORDER_X - 2, TOP_BOARD_BORDER_Y + 1);
	putch(TOP_RIGHT_LINE_CORNER_CODE);

	gotoxy(RIGHT_BOARD_BORDER_X - 2, BOTTOM_BOARD_BORDER_Y - 1);
	putch(BOTTOM_RIGHT_LINE_CORNER_CODE);
}

void Board::printBoardState() {
	for (int rowIndex = TOP_BOARD_BORDER_Y + 1; rowIndex < BOTTOM_BOARD_BORDER_Y; rowIndex++) {
		for (int columnIndex = LEFT_BOARD_BORDER_X + 2; columnIndex < RIGHT_BOARD_BORDER_X; columnIndex += 2) {
			int boardValue = this->getBoardValueByCursorPosition(columnIndex, rowIndex);

			gotoxy(columnIndex, rowIndex);

			if (boardValue == 1) {
				textcolor(GREEN);
				//putch('O');
			}
			else if (boardValue == 2) {
				textcolor(BLUE);
				putch('O');
			}

			textcolor(WHITE);
		}
	}
}


Player Board::getCurrentPlayer() {
	return this->currentPlayer;
}


void Board::insertStone(int x, int y) {
	gotoxy(x, y);
	
	if (this->currentPlayer.getId() == 1) {
		this->setBoardValueByCursorPosition(x, y, 1);
		
		//textcolor(BLACK);
		//putch('O');
	}
	else if (this->currentPlayer.getId() == 2) {
		this->setBoardValueByCursorPosition(x, y, 2);
		
		//textcolor(WHITE);
		//putch('O');
	}

	this->changePlayer();
}

int Board::getBoardValueByCursorPosition(int x, int y) {
	return this->board[(y - TOP_BOARD_BORDER_Y - 1) / 2][(x - LEFT_BOARD_BORDER_X - 2) / 2];
}

void Board::setBoardValueByCursorPosition(int x, int y, int value) {
	this->board[(y - TOP_BOARD_BORDER_Y - 1) / 2][(x - LEFT_BOARD_BORDER_X - 2) / 2] = value;
}

void Board::changePlayer() {
	if (this->currentPlayer.getId() == 1) {
		this->currentPlayer = this->player2;
	}
	else if (this->currentPlayer.getId() == 2) {
		this->currentPlayer = this->player1;
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
