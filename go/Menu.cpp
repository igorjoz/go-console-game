#include "Menu.h"
#include <cstdlib>
#include <string.h>


Menu::Menu() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}


void Menu::printMenu(Console console, Board board, Cursor cursor) {
	int keyCode = 0;
	this->restartMenuRow();
	
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("i        -> insert a stone");
	
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("q        -> exit game");
	
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("arrows	-> moving");
	
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("space    -> change color");
	
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("enter    -> change background color");

	this->incrementMenuRow();
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());

	char xCoordinate[32], yCoordinate[32];
	_itoa_s(cursor.getX(), xCoordinate, 10);
	_itoa_s(cursor.getY(), yCoordinate, 10);

	char coordinatesText[32] = "x: ";
	strcat_s(coordinatesText, xCoordinate);
	strcat_s(coordinatesText, " y: ");
	strcat_s(coordinatesText, yCoordinate);
	cputs(coordinatesText);

	char currentPlayerText[32] = "current player: ";
	if (board.getCurrentPlayer().getId() == WHITE_PLAYER_ID) {
		strcat_s(currentPlayerText, "white");
	}
	else {
		strcat_s(currentPlayerText, "black");
	}

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs(currentPlayerText);

	console.printKeyCode();
	console.setInitialConsoleSettings(cursor.getX(), cursor.getY());
}

int Menu::incrementMenuRow() {
	return this->menuRowY++;
}

void Menu::restartMenuRow() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}
