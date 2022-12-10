#include "Cursor.h"


Cursor::Cursor() {
	this->x = INITIAL_CURSOR_X_POSITION;
	this->y = INITIAL_CURSOR_Y_POSITION;
	this->shouldResetPosition = false;
}


void Cursor::moveCursor(int keyCode) {
	if (keyCode == LEFT_ARROW_KEY_CODE and this->x - 2 > LEFT_BOARD_BORDER_X) {
		this->x -= 2;
	}
	else if (keyCode == RIGHT_ARROW_KEY_CODE and this->x + 2 < RIGHT_BOARD_BORDER_X) {
		this->x += 2;
	}
	else if (keyCode == UP_ARROW_KEY_CODE and this->y - 1 > TOP_BOARD_BORDER_Y) {
		this->y--;
	}
	else if (keyCode == DOWN_ARROW_KEY_CODE and this->y + 1 < BOTTOM_BOARD_BORDER_Y) {
		this->y++;
	}
}


void Cursor::moveCursorInBoardSizeSelectionModal(int keyCode) {
	if (keyCode == LEFT_ARROW_KEY_CODE and this->x - 10 >= BOARD_SIZE_SELECTION_MODAL_DISTANCE - 1) {
		this->x -= 10;
	}
	else if (keyCode == RIGHT_ARROW_KEY_CODE and this->x + 10 <= BOARD_SIZE_SELECTION_MODAL_DISTANCE + 30) {
		this->x += 10;
	}
}


char* Cursor::getCursorPositionText() {
	char xCoordinate[32], yCoordinate[32];

	_itoa_s(this->getX(), xCoordinate, 10);
	_itoa_s(this->getY(), yCoordinate, 10);

	char* cursorPositionText = new char[32];
	strcpy_s(cursorPositionText, 32, "x: ");
	strcat_s(cursorPositionText, 32, xCoordinate);
	strcat_s(cursorPositionText, 32, " y: ");
	strcat_s(cursorPositionText, 32, yCoordinate);

	return cursorPositionText;
}


int Cursor::getX() {
	return this->x;
}


void Cursor::setX(int x) {
	this->x = x;
}


int Cursor::getY() {
	return this->y;
}


void Cursor::setY(int y) {
	this->y = y;
}


bool Cursor::getShouldResetPosition() {
	return this->shouldResetPosition;
}


void Cursor::setShouldResetPosition(bool shouldResetPosition) {
	this->shouldResetPosition = shouldResetPosition;
}


void Cursor::resetToInitialPosition() {
	this->x = INITIAL_CURSOR_X_POSITION;
	this->y = INITIAL_CURSOR_Y_POSITION;

	this->shouldResetPosition = false;
}
