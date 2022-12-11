#include "Board.h"


int Board::getSize() {
	return this->size;
}



bool Board::getIsInGameEditorMode() {
	return this->isInEditorMode;
}


bool Board::getIsBoardSizeSelected() {
	return this->isBoardSizeSelected;
}


Player* Board::getCurrentPlayer() {
	return this->currentPlayer;
}


int Board::getCurrentPlayerId() {
	return this->currentPlayer->getId();
}


Player* Board::getPlayer1() {
	return this->player1;
}


Player* Board::getPlayer2() {
	return this->player2;
}


int Board::getBoardValueByCursorPosition(int cursorX, int cursorY) {
	return this->board[this->getRowIndex(cursorY)][this->getColumnIndex(cursorX)];
}


int Board::getBoardValue(int rowIndex, int columnIndex) {
	return this->board[rowIndex][columnIndex];
}


int Board::getRowIndex(int cursorY) {
	return (cursorY - this->topBoardBorderY - 1);
}


int Board::getColumnIndex(int cursorX) {
	return (cursorX - this->leftBoardBorderX - 2) / 2;
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


int Board::getTopBoardBorderY() {
	return this->topBoardBorderY;
}


int Board::getBottomBoardBorderY() {
	return this->bottomBoardBorderY;
}


int Board::getLeftBoardBorderX() {
	return this->leftBoardBorderX;
}


int Board::getRightBoardBorderX() {
	return this->rightBoardBorderX;
}

