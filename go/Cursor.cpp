#include "Cursor.h"


Cursor::Cursor() {
	this->x = INITIAL_CURSOR_X_POSITION;
	this->y = INITIAL_CURSOR_Y_POSITION;
}


void Cursor::moveCursor(int keyCode) {
	if (keyCode == LEFT_ARROW_KEY_CODE and this->x - 1 > LEFT_BOARD_BORDER_X) {
		this->x--;
	}
	else if (keyCode == RIGHT_ARROW_KEY_CODE and this->x + 1 < RIGHT_BOARD_BORDER_X) {
		this->x++;
	}
	else if (keyCode == UP_ARROW_KEY_CODE and this->y - 1 > TOP_BOARD_BORDER_Y) {
		this->y--;
	}
	else if (keyCode == DOWN_ARROW_KEY_CODE and this->y + 1 < BOTTOM_BOARD_BORDER_Y) {
		this->y++;
	}
}


int Cursor::getX() {
	return this->x;
}


int Cursor::getY() {
	return this->y;
}
