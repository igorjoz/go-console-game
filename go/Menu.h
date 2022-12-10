#pragma once

#include "conio2.h"

#include "Console.h"
#include "Cursor.h"
#include"Board.h";
#include"Player.h"


class Menu
{
public:
	Menu();
	void printMenu(Console console, Board border, Cursor cursor);
	void printStaticMenuPart();
	int incrementMenuRow();
	void restartMenuRow();

private:
	int menuRowY;
};

