#include "Board.h"

#include"Cursor.h"


Board::Board(int size, bool isBoardSizeSelected, Player* player1, Player* player2) {
	this->size = size;
	this->isInEditorMode = false;
	this->isBoardSizeSelected = isBoardSizeSelected;

	this->bottomBoardBorderY = size + VERTICAL_BOARD_PADDING + 2;
	this->rightBoardBorderX = size * 2 + HORIZONTAL_BOARD_PADDING + 3;

	board = new short unsigned int* [this->size];

	for (int i = 0; i < this->size; i++) {
		board[i] = new short unsigned int[this->size];

		for (int j = 0; j < this->size; j++) {
			board[i][j] = 0;
		}
	}

	this->player1 = player1;
	this->player2 = player2;
	this->currentPlayer = player1;
}


// copy constructor
Board::Board(const Board& previousBoard) :
	size(previousBoard.size),
	player1(previousBoard.player1),
	player2(previousBoard.player2) {

	this->isInEditorMode = false;
	this->isBoardSizeSelected = false;
	this->currentPlayer = this->player1;

	board = new short unsigned int* [this->size];

	for (int i = 0; i < this->size; i++) {
		board[i] = new short unsigned int[this->size];

		for (int j = 0; j < this->size; j++) {
			board[i][j] = 0;
		}
	}
}


void Board::printBoard() {
	this->printTopAndBottomBorder();
	this->printLeftAndRightBorder();

	this->printBoardStructure();

	this->printBorderCorners();
	this->printBoardCorners();

	this->printBoardState();
}


bool Board::insertStone() {
	int currentPlayerId = this->getCurrentPlayerId();
	int cursorX = wherex();
	int cursorY = wherey();

	// if in game editor mode, black player can insert any number of stones before start of the game
	if (this->getIsInGameEditorMode()) {
		this->setBoardValueByCursorPosition(cursorX, cursorY, BLACK_PLAYER_ID);

		return true;
	}

	if (this->isPositionOccupied(cursorX, cursorY)) {
		//if (this->isPositionOccupied(cursorX, cursorY) or this->isStoneSuicider(cursorX, cursorY)) {
		return false;
	}

	this->setBoardValueByCursorPosition(cursorX, cursorY, currentPlayerId);

	//this->isKo();

	this->changePlayer();
	this->removeStonesWithNoLiberties();

	return true;
}


bool Board::isPositionOccupied(int rowIndex, int columnIndex) {
	int boardValue = this->getBoardValueByCursorPosition(rowIndex, columnIndex);

	if (boardValue != 0) {
		return true;
	}

	return false;
}


bool Board::isStoneSuicider(int rowIndex, int columnIndex) {
	if (this->hasLiberty(rowIndex, columnIndex)) {
		return false;
	}

	return true;
}


bool Board::isKo() {
	return false;
}


void Board::removeStonesWithNoLiberties() {
	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			if (!this->hasLiberty(rowIndex, columnIndex)) {
				this->setBoardValue(rowIndex, columnIndex, 0);
				this->incrementCurrentPlayerScore();
			}
		}
	}
}


bool Board::hasLiberty(int rowIndex, int columnIndex) {
	int leftPositionValue = -1;
	int rightPositionValue = -1;
	int topPositionValue = -1;
	int bottomPositionValue = -1;

	int currentPlayerId = this->getCurrentPlayerId();

	int totalLiberties = 0;
	bool hasLiberty = false;

	if (rowIndex - 1 >= 0) {
		leftPositionValue = this->getBoardValue(rowIndex - 1, columnIndex);

		if (leftPositionValue == 0 or leftPositionValue == currentPlayerId) {
			totalLiberties++;
		}
	}

	if (rowIndex + 1 < this->size) {
		rightPositionValue = this->getBoardValue(rowIndex + 1, columnIndex);

		if (rightPositionValue == 0 or rightPositionValue == currentPlayerId) {
			totalLiberties++;
		}
	}

	if (columnIndex - 1 >= 0) {
		topPositionValue = this->getBoardValue(rowIndex, columnIndex - 1);

		if (topPositionValue == 0 or topPositionValue == currentPlayerId) {
			totalLiberties++;
		}
	}

	if (columnIndex + 1 < this->size) {
		bottomPositionValue = this->getBoardValue(rowIndex, columnIndex + 1);

		if (bottomPositionValue == 0 or bottomPositionValue == currentPlayerId) {
			totalLiberties++;
		}
	}

	return totalLiberties > 0;
}


void Board::restartGame(Console console, Cursor cursor) {
	//cursor.setX(INITIAL_CURSOR_X_POSITION);
	//cursor.setY(INITIAL_CURSOR_Y_POSITION);

	//gotoxy(INITIAL_CURSOR_X_POSITION, INITIAL_CURSOR_Y_POSITION);
	//putch('@');

	*this = Board(*this);
}


void Board::changePlayer() {
	int currentPlayerId = this->getCurrentPlayerId();

	if (currentPlayerId == WHITE_PLAYER_ID) {
		this->currentPlayer = this->player2;
	}
	else if (currentPlayerId == BLACK_PLAYER_ID) {
		this->currentPlayer = this->player1;
	}
}


void Board::incrementCurrentPlayerScore() {
	this->currentPlayer->incrementScore();
}


int Board::interpretBoardSizeSelection(Cursor cursor) {
	int x = cursor.getX();

	if (x == BOARD_SIZE_SELECTION_MODAL_DISTANCE - 1) {
		return 9;
	}
	else if (x == BOARD_SIZE_SELECTION_MODAL_DISTANCE - 1 + 10) {
		return 13;
	}
	else if (x == BOARD_SIZE_SELECTION_MODAL_DISTANCE - 1 + 20) {
		return 19;
	}
	
	return -1;
}


void Board::captureChain(int rowIndex, int columnIndex, int color)
{
	if (this->board[rowIndex][columnIndex] == color)
	{
		this->board[rowIndex][columnIndex] = 0;

		if (rowIndex - 1 >= 0) {
			captureChain(rowIndex - 1, columnIndex, color);
		}
		
		if (rowIndex < this->getSize() - 1) {
			captureChain(rowIndex + 1, columnIndex, color);
		}
		
		if (columnIndex - 1 >= 0) {
			captureChain(rowIndex, columnIndex - 1, color);
		}
		
		if (columnIndex + 1 < this->getSize()) {
			captureChain(rowIndex, columnIndex + 1, color);
		}
	}
}


bool Board::isSurroundedBySameColorChain(int i, int j, int color)
{
	if (i > 0 && this->board[i - 1][j] == color)
	{
		// Check if the position above the given position is part of a chain of the given color
		if (this->isPartOfSameColorChain(i - 1, j, color))
		{
			return true;
		}
	}
	
	if (i < this->size - 1 && this->board[i + 1][j] == color)
	{
		// Check if the position below the given position is part of a chain of the given color
		if (this->isPartOfSameColorChain(i + 1, j, color))
		{
			return true;
		}
	}
	
	if (j > 0 && this->board[i][j - 1] == color)
	{
		// Check if the position to the left of the given position is part of a chain of the given color
		if (this->isPartOfSameColorChain(i, j - 1, color))
		{
			return true;
		}
	}
	
	if (j < this->size - 1 && this->board[i][j + 1] == color)
	{
		if (this->isPartOfSameColorChain(i, j + 1, color))
		{
			return true;
		}
	}

	// If the given position is not surrounded by a chain of the given color, return false
	return false;
}

bool Board::isPartOfSameColorChain(int i, int j, int color)
{
	// Check if the position at the given coordinates is the given color
	if (this->board[i][j] == color)
	{
		// Check if the position above the given position is the given color
		if (i > 0 && this->board[i - 1][j] == color)
		{
			// Recursively call the isPartOfSameColorChain() function on the position above the given position
			return this->isPartOfSameColorChain(i - 1, j, color);
		}
		// Check if the position below the given position is the given color
		else if (i < this->size - 1 && this->board[i + 1][j] == color)
		{
			// Recursively call the isPartOfSameColorChain() function on the position below the given position
			return this->isPartOfSameColorChain(i + 1, j, color);
		}
		// Check if the position to the left of the given position is the given color
		else if (j > 0 && board[i][j - 1] == color)
		{
			// Recursively call the isPartOfSameColorChain() function on the position to the left of the given position
			return this->isPartOfSameColorChain(i, j - 1, color);
		}
	}
}
