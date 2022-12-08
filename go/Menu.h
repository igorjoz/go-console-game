#pragma once

#include "conio2.h"
#include "Console.h"
#include "Cursor.h"


int const MENU_DISTANCE = 48;


class Menu
{
public:
	Menu();
	void printMenu(Console console, Cursor cursor);
	int getMenuRowAndIncrement();
	void restartMenuRow();

private:
	int menuRowY;
};

