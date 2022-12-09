#include "Menu.h"
#include <cstdlib>
#include <string.h>


Menu::Menu() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}


void Menu::printMenu(Console console, Cursor cursor) {
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

	char coordinates[32] = "x: ";
	strcat_s(coordinates, xCoordinate);
	strcat_s(coordinates, " y: ");
	strcat_s(coordinates, yCoordinate);
	cputs(coordinates);

	console.printKeyCode();
	console.setInitialConsoleSettings(cursor.getX(), cursor.getY());
}

int Menu::incrementMenuRow() {
	return this->menuRowY++;
}

void Menu::restartMenuRow() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}
