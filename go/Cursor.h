#pragma once

#include <cstdlib>
#include <string.h>

#include "conio2.h"
#include "constants.h"


int const LEFT_ARROW_KEY_CODE = 0x4b;
int const RIGHT_ARROW_KEY_CODE = 0x4d;
int const UP_ARROW_KEY_CODE = 0x48;
int const DOWN_ARROW_KEY_CODE = 0x50;

int const INITIAL_CURSOR_X_POSITION = LEFT_BOARD_BORDER_X + 2;
int const INITIAL_CURSOR_Y_POSITION = TOP_BOARD_BORDER_Y + 1;


class Cursor
{
public:
	Cursor();
	void moveCursor(int keyCode);
	char* getCursorPositionText();
	int getX();
	int getY();

private:
	int x;
	int y;
};

