#pragma once


#ifndef CURSOR_h
#define CURSOR_h


#include <cstdlib>
#include <string.h>

#include "conio2.h"
#include "constants.h"


class Cursor;


class Cursor
{
public:
	Cursor();
	void moveCursor(int keyCode);
	void moveCursorInBoardSizeSelectionModal(int keyCode);
	char* getCursorPositionText();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	bool getShouldResetPosition();
	void setShouldResetPosition(bool shouldResetPosition);
	void resetToInitialPosition();
	void resetToModalInitialPosition();

private:
	int x;
	int y;
	bool shouldResetPosition;
};


#endif
