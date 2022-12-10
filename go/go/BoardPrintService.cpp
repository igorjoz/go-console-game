#include "Board.h"


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
				textcolor(LIGHTGRAY);
				putch('O');
			}
			else if (boardValue == 2) {
				textcolor(LIGHTBLUE);
				putch('O');
			}

			textcolor(WHITE);
		}
	}
}

void Board::printIsInGameEditorMode() {
	/*if (this->isInEditorMode) {
		gotoxy(LEFT_BOARD_BORDER_X, 1);
		cputs("Game Editor Mode: ON");
	}*/
}
