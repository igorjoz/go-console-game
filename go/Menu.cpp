#include "Menu.h"
#include <cstdlib>
#include <string.h>


Menu::Menu() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}


void Menu::printMenu(Console console, Cursor cursor) {
	int keyCode = 0;
	this->restartMenuRow();
	
	gotoxy(MENU_DISTANCE, this->getMenuRowAndIncrement());
	cputs("i        -> insert a stone");
	
	gotoxy(MENU_DISTANCE, this->getMenuRowAndIncrement());
	cputs("q        -> exit game");
	
	gotoxy(MENU_DISTANCE, this->getMenuRowAndIncrement());
	cputs("arrows	-> moving");
	
	gotoxy(MENU_DISTANCE, this->getMenuRowAndIncrement());
	cputs("space    -> change color");
	
	gotoxy(MENU_DISTANCE, this->getMenuRowAndIncrement());
	cputs("enter    -> change background color");

	gotoxy(MENU_DISTANCE, this->getMenuRowAndIncrement());

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

int Menu::getMenuRowAndIncrement() {
	return this->menuRowY++;
}

void Menu::restartMenuRow() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}
