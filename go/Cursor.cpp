#include "Cursor.h"


Cursor::Cursor() {
	this->x = INITIAL_CURSOR_X_POSITION;
	this->y = INITIAL_CURSOR_Y_POSITION;
}

void Cursor::moveCursor(int keyCode) {
	if (keyCode == LEFT_ARROW_KEY_CODE and this->x > 2) {
		this->x--;
	}
	else if (keyCode == RIGHT_ARROW_KEY_CODE and this->x < BOARD_SIZE + 1) {
		this->x++;
	}
	else if (keyCode == UP_ARROW_KEY_CODE and this->y > 2) {
		this->y--;
	}
	else if (keyCode == DOWN_ARROW_KEY_CODE and this->y < BOARD_SIZE + 1) {
		this->y++;
	}
}

int Cursor::getX() {
	return this->x;
}

int Cursor::getY() {
	return this->y;
}
