#include "Board.h"


Board::Board(Player* player1, Player* player2) {
	this->size = BOARD_SIZE;
	this->isInEditorMode = false;
	this->isBoardSizeSelected = false;

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
	Board::printTopAndBottomBorder();
	Board::printLeftAndRightBorder();

	Board::printBoardStructure();

	Board::printBorderCorners();
	Board::printBoardCorners();

	this->printBoardState();
}


int Board::getBoardValueByCursorPosition(int cursorX, int cursorY) {
	return this->board[this->getRowIndex(cursorY)][this->getColumnIndex(cursorX)];
}


void Board::setBoardValueByCursorPosition(int cursorX, int cursorY, short unsigned int value) {
	this->board[this->getRowIndex(cursorY)][this->getColumnIndex(cursorX)] = value;
}


int Board::getBoardValue(int rowIndex, int columnIndex) {
	return this->board[rowIndex][columnIndex];
}

void Board::setBoardValue(int rowIndex, int columnIndex, short unsigned int value) {
	this->board[rowIndex][columnIndex] = value;
}


char* Board::getBoardPositionText(int cursorX, int cursorY) {
	char boardRow[32], boardColumn[32];
	int rowIndex = this->getRowIndex(cursorY);
	int columnIndex = this->getColumnIndex(cursorX);

	_itoa_s(rowIndex, boardRow, 10);
	_itoa_s(columnIndex, boardColumn, 10);

	char* boardPositionText = new char[32];
	strcpy_s(boardPositionText, 32, "row: ");
	strcat_s(boardPositionText, 32, boardRow);
	strcat_s(boardPositionText, 32, ", column: ");
	strcat_s(boardPositionText, 32, boardColumn);

	return boardPositionText;
}


char* Board::getCurrentPlayerText() {
	int currentPlayerId = this->getCurrentPlayerId();
	char* currentPlayerText = new char[32];

	strcpy_s(currentPlayerText, 32, "current player: ");

	if (currentPlayerId == WHITE_PLAYER_ID) {
		strcat_s(currentPlayerText, 32, "white");
	}
	else if (currentPlayerId == BLACK_PLAYER_ID) {
		strcat_s(currentPlayerText, 32, "black");
	}

	return currentPlayerText;
}


char* Board::getPlayersScoreText() {
	int whitePlayerScore = this->player1->getScore();
	int blackPlayerScore = this->player2->getScore();

	char* playersScoreText = new char[32];
	char whitePlayerScoreText[32];
	char blackPlayerScoreText[32];

	_itoa_s(whitePlayerScore, whitePlayerScoreText, 10);
	_itoa_s(blackPlayerScore, blackPlayerScoreText, 10);

	strcpy_s(playersScoreText, 32, "white: ");
	strcat_s(playersScoreText, 32, whitePlayerScoreText);

	strcat_s(playersScoreText, 32, ", black: ");
	strcat_s(playersScoreText, 32, blackPlayerScoreText);

	return playersScoreText;
}


int Board::getRowIndex(int cursorY) {
	return (cursorY - TOP_BOARD_BORDER_Y - 1);
}


int Board::getColumnIndex(int cursorX) {
	return (cursorX - LEFT_BOARD_BORDER_X - 2) / 2;
}


void Board::insertStone() {
	int cursorX = wherex();
	int cursorY = wherey();

	if (this->getIsInGameEditorMode()) {
		this->setBoardValueByCursorPosition(cursorX, cursorY, BLACK_PLAYER_ID);

		return;
	}

	int currentPlayerId = this->getCurrentPlayerId();

	if (!this->canInsertStone(cursorX, cursorY)) {
		return;
	}

	if (currentPlayerId == WHITE_PLAYER_ID) {
		this->setBoardValueByCursorPosition(cursorX, cursorY, WHITE_PLAYER_ID);
	}
	else {
		this->setBoardValueByCursorPosition(cursorX, cursorY, BLACK_PLAYER_ID);
	}

	this->changePlayer();
	this->removeStonesWithNoLiberties();
}


bool Board::canInsertStone(int x, int y) {
	int boardValue = this->getBoardValueByCursorPosition(x, y);

	if (boardValue != 0) {
		return false;
	}

	return true;
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


bool Board::getIsInGameEditorMode() {
	return this->isInEditorMode;
}


void Board::setIsInGameEditorMode(bool isInEditorMode) {
	this->isInEditorMode = isInEditorMode;
}


bool Board::getIsBoardSizeSelected() {
	return this->isBoardSizeSelected;
}


void Board::setIsBoardSizeSelected(bool isBoardSizeSelected) {
	this->isBoardSizeSelected = isBoardSizeSelected;
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


Player* Board::getCurrentPlayer() {
	return this->currentPlayer;
}


int Board::getCurrentPlayerId() {
	return this->currentPlayer->getId();
}


void Board::handleBoardSizeSelection(Cursor cursor) {
	int x = cursor.getX();

	if (x == BOARD_SIZE_SELECTION_MODAL_DISTANCE) {
		this->setSize(9);
	}
	else if (x == BOARD_SIZE_SELECTION_MODAL_DISTANCE + 10) {
		this->setSize(13);
	}
	else if (x == BOARD_SIZE_SELECTION_MODAL_DISTANCE + 20) {
		this->setSize(19);
	}
	else {
		// handle custom size selection

	}
}


int Board::getSize() {
	return this->size;
}


void Board::setSize(int size) {
	this->size = size;
	//this->setIsBoardSizeSelected(true);
}
