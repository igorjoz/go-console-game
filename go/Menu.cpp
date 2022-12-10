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


void Menu::showBoardSizeSelectionModal() {
	gotoxy(MENU_DISTANCE, 1);
	cputs("9x9");

	gotoxy(MENU_DISTANCE, 2);
	cputs("13x13");

	gotoxy(MENU_DISTANCE, 3);
	cputs("19x19");

	gotoxy(MENU_DISTANCE, 4);
	cputs("custom");

	/*struct text_info textInfo;
	gettextinfo(&textInfo);

	char screenWidthText[100];
	char screenHeightText[100];
	_itoa_s(textInfo.screenwidth, screenWidthText, 10);
	_itoa_s(textInfo.screenheight, screenHeightText, 10);
	
	gotoxy(MENU_DISTANCE, 6);
	cputs("screen width: ");
	cputs(screenWidthText);

	gotoxy(MENU_DISTANCE, 7);
	cputs("screen height: ");
	cputs(screenHeightText);*/
}


int Menu::incrementMenuRow() {
	return this->menuRowY++;
}


void Menu::restartMenuRow() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}
