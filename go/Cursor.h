#pragma once

#include <cstdlib>
#include <string.h>

#include "conio2.h"
#include "constants.h"


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

