#pragma once

#include "conio2.h"
#include "Board.h"


int const LEFT_ARROW_KEY_CODE = 0x4b;
int const RIGHT_ARROW_KEY_CODE = 0x4d;
int const UP_ARROW_KEY_CODE = 0x48;
int const DOWN_ARROW_KEY_CODE = 0x50;

int const INITIAL_CURSOR_X_POSITION = 2;
int const INITIAL_CURSOR_Y_POSITION = 2;


class Cursor
{
public:
	Cursor();
	void moveCursor(int keyCode);
	int getX();
	int getY();

private:
	int x;
	int y;
};

