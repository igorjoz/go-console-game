#include "Board.h"


void Board::printTopAndBottomBorder() {
	for (int columnIndex = this->leftBoardBorderX + 1; columnIndex <= this->rightBoardBorderX - 1; columnIndex++) {
		gotoxy(columnIndex, this->topBoardBorderY);
		putch(DOUBLE_HORIZONTAL_LINE_CODE);

		gotoxy(columnIndex, this->bottomBoardBorderY);
		putch(DOUBLE_HORIZONTAL_LINE_CODE);

		if (columnIndex % 2 == 1) {
			gotoxy(columnIndex, this->topBoardBorderY + 1);
			putch(TOP_INTERSECTION_CHARACTER_CODE);

			gotoxy(columnIndex, this->bottomBoardBorderY - 1);
			putch(BOTTOM_INTERSECTION_CHARACTER_CODE);
		}
		else if (columnIndex > this->leftBoardBorderX + 2 and columnIndex < this->rightBoardBorderX - 2) {
			gotoxy(columnIndex, this->topBoardBorderY + 1);
			putch(HORIZONTAL_LINE_CHARACTER_CODE);

			gotoxy(columnIndex, this->bottomBoardBorderY - 1);
			putch(HORIZONTAL_LINE_CHARACTER_CODE);
		}
	}
}


void Board::printLeftAndRightBorder() {
	for (int rowIndex = this->topBoardBorderY + 1; rowIndex <= this->bottomBoardBorderY - 1; rowIndex++) {
		gotoxy(this->leftBoardBorderX, rowIndex);
		putch(DOUBLE_VERTICAL_LINE_CODE);

		gotoxy(this->rightBoardBorderX, rowIndex);
		putch(DOUBLE_VERTICAL_LINE_CODE);

		gotoxy(this->leftBoardBorderX + 2, rowIndex);
		putch(LEFT_INTERSECTION_CHARACTER_CODE);

		gotoxy(this->rightBoardBorderX - 2, rowIndex);
		putch(RIGHT_INTERSECTION_CHARACTER_CODE);
	}
}


void Board::printBoardStructure() {
	for (int rowIndex = this->topBoardBorderY + 2; rowIndex < this->bottomBoardBorderY - 1; rowIndex++) {
		for (int columnIndex = this->leftBoardBorderX + 4; columnIndex < this->rightBoardBorderX - 2; columnIndex += 2) {
			gotoxy(columnIndex, rowIndex);
			putch(INTERSECTION_CHARACTER_CODE);
		}
	}

	// fill gaps between rows
	for (int rowIndex = this->topBoardBorderY + 2; rowIndex < this->bottomBoardBorderY - 1; rowIndex++) {
		for (int columnIndex = this->leftBoardBorderX + 4; columnIndex < this->rightBoardBorderX; columnIndex += 2) {
			gotoxy(columnIndex - 1, rowIndex);
			putch(HORIZONTAL_LINE_CHARACTER_CODE);
		}
	}
}


void Board::printBorderCorners() {
	gotoxy(this->leftBoardBorderX, this->topBoardBorderY);
	putch(TOP_LEFT_DOUBLE_LINE_CORNER_CODE);

	gotoxy(this->leftBoardBorderX, this->bottomBoardBorderY);
	putch(BOTTOM_LEFT_DOUBLE_LINE_CORNER_CODE);

	gotoxy(this->rightBoardBorderX, this->topBoardBorderY);
	putch(TOP_RIGHT_DOUBLE_LINE_CORNER_CODE);

	gotoxy(this->rightBoardBorderX, this->bottomBoardBorderY);
	putch(BOTTOM_RIGHT_DOUBLE_LINE_CORNER_CODE);
}


void Board::printBoardCorners() {
	gotoxy(this->leftBoardBorderX + 2, this->topBoardBorderY + 1);
	putch(TOP_LEFT_LINE_CORNER_CODE);

	gotoxy(this->leftBoardBorderX + 2, this->bottomBoardBorderY - 1);
	putch(BOTTOM_LEFT_LINE_CORNER_CODE);

	gotoxy(this->rightBoardBorderX - 2, this->topBoardBorderY + 1);
	putch(TOP_RIGHT_LINE_CORNER_CODE);

	gotoxy(this->rightBoardBorderX - 2, this->bottomBoardBorderY - 1);
	putch(BOTTOM_RIGHT_LINE_CORNER_CODE);
}


void Board::printBoardState() {
	for (int rowIndex = this->topBoardBorderY + 1; rowIndex < this->bottomBoardBorderY; rowIndex++) {
		for (int columnIndex = this->leftBoardBorderX + 2; columnIndex < this->rightBoardBorderX; columnIndex += 2) {
			int boardValue = this->getBoardValueByCursorPosition(columnIndex, rowIndex);

			gotoxy(columnIndex, rowIndex);

			if (boardValue == BLACK_PLAYER_ID) {
				textcolor(LIGHTBLUE);
				putch('O');
			}
			else if (boardValue == WHITE_PLAYER_ID) {
				textcolor(LIGHTGRAY);
				putch('O');
			}

			textcolor(WHITE);
		}
	}
}

void Board::printIsInGameEditorMode() {
	/*if (this->isInEditorMode) {
		gotoxy(this->leftBoardBorderX, 1);
		cputs("Game Editor Mode: ON");
	}*/
}
