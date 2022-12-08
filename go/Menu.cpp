#include "Menu.h"

void Menu::printMenu() {
	gotoxy(MENU_DISTANCE, 1);
	cputs("q       = exit");
	gotoxy(MENU_DISTANCE, 2);
	cputs("cursors = moving");
	gotoxy(MENU_DISTANCE, 3);
	cputs("space   = change color");
	gotoxy(MENU_DISTANCE, 4);
	cputs("enter   = change background color");
}
