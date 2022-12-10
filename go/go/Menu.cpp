#include "Menu.h"
#include <cstdlib>
#include <string.h>


Menu::Menu() {
	this->menuRowY = TOP_BOARD_BORDER_Y + 1;
}


void Menu::printMenu(Console console, Board board, Cursor cursor) {
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
	console.setInitialConsoleSettings(cursorX, cursorY);
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


void Menu::showBoardSizeSelectionModal(Console console, Cursor cursor) {
	//console.setCursor(cursorX, cursorY);*/


	//int cursorX = 1;

	//cursor.setX(INITIAL_CURSOR_X_POSITION);
	//cursor.x = 7;
	//cursor.setY(INITIAL_CURSOR_Y_POSITION);

	//int cursorX = INITIAL_CURSOR_X_POSITION;
	int cursorX = cursor.getX();
	int cursorY = cursor.getY();

	// convert cursorX to array of characters
	char cursorXString[10];
	_itoa_s(cursorX, cursorXString, 10);

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE, 10);
	cputs(cursorXString);


	console.printKeyCode();
	console.setInitialConsoleSettings(cursorX, cursorY);

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE, 2);
	cputs("Board size selection");

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE, 4);
	cputs("9x9");

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE + 10, 4);
	cputs("13x13");

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE + 20, 4);
	cputs("19x19");

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE + 30, 4);
	cputs("custom");

	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE, 6);
	cputs("Click ENTER to confirm choice");


	// 
	//console.setInitialConsoleSettings(10, 4);


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
