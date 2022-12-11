#pragma once


#ifndef MENU_H
#define MENU_H


#include "conio2.h"

#include "Console.h"
#include "Cursor.h"
#include "Board.h";
#include "Player.h"


class Menu
{
public:
	Menu();
	void printMenu(Console console, Board border, Cursor cursor);
	void printStaticMenuPart();
	void showBoardSizeSelectionModal(Console console, Cursor cursor);
	void showCustomBoardSizeSelectionModal(Console console, Cursor cursor);

	int incrementMenuRow();
	void restartMenuRow();

	bool getShouldDisplayCustomBoardSizeSelectionModal();
	void setShouldDisplayCustomBoardSizeSelectionModal(bool shouldDisplayCustomBoardSizeSelectionModal);

	void showFileNameInputModal(Console console, Cursor cursor);
	bool getShouldDisplayFileNameInput();
	void setShouldDisplayFileNameInput(bool shouldDisplayFileNameInput);

private:
	int menuRowY;
	bool shouldDisplayCustomBoardSizeSelectionModal;
	bool shouldDisplayFileNameInput;
};


#endif
