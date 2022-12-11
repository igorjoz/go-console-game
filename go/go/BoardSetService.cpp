#include "Board.h"



void Board::setSize(int size) {
	this->size = size;

	/*if (this->board != NULL) {
		for (int i = 0; i < this->size; i++) {
			delete[] this->board[i];
		}

		delete[] this->board;
	}*/

	//this = ;

	this->board = new short unsigned int* [this->size];

	for (int i = 0; i < this->size; i++) {
		this->board[i] = new short unsigned int[this->size];

		for (int j = 0; j < this->size; j++) {
			this->board[i][j] = 0;
		}
	}

	//this->setIsBoardSizeSelected(true);
}


void Board::setIsInGameEditorMode(bool isInGameEditorMode) {
	this->isInGameEditorMode = isInGameEditorMode;
}


void Board::setIsBoardSizeSelected(bool isBoardSizeSelected) {
	this->isBoardSizeSelected = isBoardSizeSelected;
}


void Board::setBoardValueByCursorPosition(int cursorX, int cursorY, short unsigned int value) {
	this->board[this->getRowIndex(cursorY)][this->getColumnIndex(cursorX)] = value;
}


void Board::setBoardValue(int rowIndex, int columnIndex, short unsigned int value) {
	this->board[rowIndex][columnIndex] = value;
}


void Board::setPreviousBoardValue(int rowIndex, int columnIndex, short unsigned int value) {
	this->previousBoard[rowIndex][columnIndex] = value;
}


void Board::setTopBoardBorderY(int y) {
	this->topBoardBorderY = y;
}


void Board::setBottomBoardBorderY(int y) {
	this->bottomBoardBorderY = y;
}


void Board::setLeftBoardBorderX(int x) {
	this->leftBoardBorderX = x;
}


void Board::setRightBoardBorderX(int x) {
	this->rightBoardBorderX = x;
}