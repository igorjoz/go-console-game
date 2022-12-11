#include "Board.h"

#include"Cursor.h"


Board::Board(int size, bool isBoardSizeSelected, Player* blackPlayer, Player* whitePlayer, int currentPlayerId) {
	this->size = size;
	this->isInGameEditorMode = false;
	this->isBoardSizeSelected = isBoardSizeSelected;

	this->bottomBoardBorderY = size + VERTICAL_BOARD_PADDING + 2;
	this->rightBoardBorderX = size * 2 + HORIZONTAL_BOARD_PADDING + 3;

	this->topBoardBorderY = VERTICAL_BOARD_PADDING + 1;
	this->leftBoardBorderX = HORIZONTAL_BOARD_PADDING + 1;

	board = new short unsigned int* [this->size];
	previousBoard = new short unsigned int* [this->size];

	for (int i = 0; i < this->size; i++) {
		board[i] = new short unsigned int[this->size];
		previousBoard[i] = new short unsigned int[this->size];

		for (int j = 0; j < this->size; j++) {
			board[i][j] = 0;
			previousBoard[i][j] = 0;
		}
	}

	this->blackPlayer = blackPlayer;
	this->whitePlayer = whitePlayer;

	if (currentPlayerId == BLACK_PLAYER_ID) {
		this->currentPlayer = this->blackPlayer;
	}
	else {
		this->currentPlayer = this->whitePlayer;
	}
}


Board::Board(const Board& prevBoard) : // copy constructor
	size(prevBoard.size),
	blackPlayer(prevBoard.blackPlayer),
	whitePlayer(prevBoard.whitePlayer) {

	this->isInGameEditorMode = false;
	this->isBoardSizeSelected = false;

	this->bottomBoardBorderY = size + VERTICAL_BOARD_PADDING + 2;
	this->rightBoardBorderX = size * 2 + HORIZONTAL_BOARD_PADDING + 3;

	this->topBoardBorderY = VERTICAL_BOARD_PADDING + 1;
	this->leftBoardBorderX = HORIZONTAL_BOARD_PADDING + 1;
	
	board = new short unsigned int* [this->size];
	previousBoard = new short unsigned int* [this->size];

	for (int i = 0; i < this->size; i++) {
		board[i] = new short unsigned int[this->size];
		previousBoard[i] = new short unsigned int[this->size];

		for (int j = 0; j < this->size; j++) {
			board[i][j] = 0;
			previousBoard[i][j] = 0;
		}
	}
	
	this->blackPlayer = blackPlayer;
	this->whitePlayer = whitePlayer;
	this->currentPlayer = blackPlayer;
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
	
	int rowIndex = this->getRowIndex(cursorY);
	int columnIndex = this->getColumnIndex(cursorX);

	this->copyBoardIntoPreviousBoard();

	// if in game editor mode, black player can insert any number of stones before start of the game
	if (this->isInGameEditorMode) {
		this->previousBoard[rowIndex][columnIndex] = BLACK_PLAYER_ID;
		this->board[rowIndex][columnIndex] = BLACK_PLAYER_ID;

		this->getWhitePlayer()->incrementScore();

		return true;
	}

	if (this->isPositionOccupied(rowIndex, columnIndex)) {
		return false;
	}

	this->board[rowIndex][columnIndex] = currentPlayerId;
	
	this->removeNeighbouringStonesWithNoLiberties(rowIndex, columnIndex);

	bool isKo = this->isKo();

	if (isKo) {
		this->board[rowIndex][columnIndex] = EMPTY_POSITION_ID;
		
		return false;
	}

	/*if (this->isStoneSuicider(rowIndex, columnIndex, currentPlayerId)) {
		return false;
	}*/

	this->changePlayer();
	//this->removeStonesWithNoLiberties();

	return true;
}


bool Board::isPositionOccupied(int rowIndex, int columnIndex) {
	int boardValue = this->board[rowIndex][columnIndex];

	if (boardValue != EMPTY_POSITION_ID) {
		return true;
	}

	return false;
}


bool Board::isStoneSuicider(int rowIndex, int columnIndex, short int currentPlayerId) {
	if (this->hasLiberty(rowIndex, columnIndex, currentPlayerId)) {
		return false;
	}

	return true;
}


bool Board::isKo() {
	if (this->areBoardsEqual()) {
		return true;
	}
	
	return false;
}


bool Board::areBoardsEqual() {
	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			if (this->getBoardValue(rowIndex, columnIndex) != this->getPreviousBoardValue(rowIndex, columnIndex)) {
				return false;
			}
		}
	}

	return true;
}


void Board::removeStonesWithNoLiberties() {
	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			short unsigned int boardValue = this->board[rowIndex][columnIndex];
			
			if (!this->hasLiberty(rowIndex, columnIndex, boardValue)) {
				if (boardValue == BLACK_PLAYER_ID) {
					this->incrementWhitePlayerScore();
				}
				else if (boardValue == WHITE_PLAYER_ID) {
					this->incrementBlackPlayerScore();
				}
				
				this->board[rowIndex][columnIndex] = EMPTY_POSITION_ID;
			}
		}
	}
}


void Board::removeNeighbouringStonesWithNoLiberties(int rowIndex, int columnIndex) {
	short int currentPlayerId = this->board[rowIndex][columnIndex];
	short int opponentPlayerId = this->getOpponentPlayerId(currentPlayerId);

	if (rowIndex - 1 >= 0 and !this->hasLiberty(rowIndex - 1, columnIndex, opponentPlayerId)) {
		this->incrementBlackPlayerScore();
		this->incrementWhitePlayerScore();
		this->board[rowIndex - 1][columnIndex] = EMPTY_POSITION_ID;
	}

	if (rowIndex + 1 < this->size and !this->hasLiberty(rowIndex + 1, columnIndex, opponentPlayerId)) {
		this->incrementBlackPlayerScore();
		this->incrementWhitePlayerScore();
		this->board[rowIndex + 1][columnIndex] = EMPTY_POSITION_ID;
	}

	if (columnIndex - 1 and !this->hasLiberty(rowIndex, columnIndex - 1, opponentPlayerId)) {
		this->incrementBlackPlayerScore();
		this->incrementWhitePlayerScore();
		this->board[rowIndex][columnIndex - 1] = EMPTY_POSITION_ID;
	}

	if (columnIndex + 1 < this->size and !this->hasLiberty(rowIndex, columnIndex + 1, opponentPlayerId)) {
		this->incrementBlackPlayerScore();
		this->incrementWhitePlayerScore();
		this->board[rowIndex][columnIndex + 1] = EMPTY_POSITION_ID;
	}
}


bool Board::hasLiberty(int rowIndex, int columnIndex, short unsigned int color) {
	int leftPositionValue = -1;
	int rightPositionValue = -1;
	int topPositionValue = -1;
	int bottomPositionValue = -1;

	int totalLiberties = 0;
	bool hasLiberty = false;

	if (board[rowIndex][columnIndex] == EMPTY_POSITION_ID) {
		return true;
	}

	if (rowIndex - 1 >= 0) {
		leftPositionValue = this->getBoardValue(rowIndex - 1, columnIndex);

		if (leftPositionValue == EMPTY_POSITION_ID or leftPositionValue == color) {
			totalLiberties++;
		}
	}

	if (rowIndex + 1 < this->size) {
		rightPositionValue = this->getBoardValue(rowIndex + 1, columnIndex);

		if (rightPositionValue == EMPTY_POSITION_ID or rightPositionValue == color) {
			totalLiberties++;
		}
	}

	if (columnIndex - 1 >= 0) {
		topPositionValue = this->getBoardValue(rowIndex, columnIndex - 1);

		if (topPositionValue == EMPTY_POSITION_ID or topPositionValue == color) {
			totalLiberties++;
		}
	}

	if (columnIndex + 1 < this->size) {
		bottomPositionValue = this->getBoardValue(rowIndex, columnIndex + 1);

		if (bottomPositionValue == EMPTY_POSITION_ID or bottomPositionValue == color) {
			totalLiberties++;
		}
	}

	return totalLiberties > 0;
}


void Board::restartGame(Console console, Cursor cursor) {
	*this = Board(*this);
}


void Board::changePlayer() {
	int currentPlayerId = this->getCurrentPlayerId();


	if (currentPlayerId == BLACK_PLAYER_ID) {
		this->currentPlayer = this->whitePlayer;
	}
	else {
		this->currentPlayer = this->blackPlayer;
	}
}


void Board::incrementCurrentPlayerScore() {
	this->currentPlayer->incrementScore();
}


void Board::incrementBlackPlayerScore() {
	this->blackPlayer->incrementScore();
}


void Board::incrementWhitePlayerScore() {
	this->whitePlayer->incrementScore();
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

void Board::copyBoardIntoPreviousBoard() {
	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			this->previousBoard[rowIndex][columnIndex] = this->board[rowIndex][columnIndex];
		}
	}
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
