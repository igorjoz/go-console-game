#include "Menu.h"
#include <cstdlib>
#include <string.h>


Menu::Menu() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}


void Menu::printMenu(Console console, Board board, Cursor cursor) {
	int keyCode = 0;
	this->restartMenuRow();

	int cursorX = cursor.getX();
	int cursorY = cursor.getY();

	textcolor(WHITE);
	textbackground(BLACK);
	
	this->printStaticMenuPart();

	this->incrementMenuRow();
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs(cursor.getCursorPositionText());

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs(board.getBoardPositionText(cursorX, cursorY));

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs(board.getCurrentPlayerText());

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs(board.getPlayersScoreText());

	board.printIsInGameEditorMode();

	console.printKeyCode();
	console.setInitialConsoleSettings(cursor.getX(), cursor.getY());
}


void Menu::printStaticMenuPart() {	
	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("i        -> insert a stone");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("q        -> exit game");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("n        -> new game");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("s        -> save game");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("l        -> load game");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("e        -> enter / exit game editor");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("arrows	-> move cursor");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("space    -> change color");

	gotoxy(MENU_DISTANCE, this->incrementMenuRow());
	cputs("enter    -> change background color");
}


int Menu::incrementMenuRow() {
	return this->menuRowY++;
}


void Menu::restartMenuRow() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}
