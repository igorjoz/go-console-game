#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"conio2.h"

#include"Board.h"
#include"Console.h"
#include"Cursor.h"
#include"Menu.h"


int const ENTER_KEY_CODE = 0x0d;


int main() {
	int keyCode = 0;
	
	char keyCodeText[32];

	Board board;
	Cursor cursor;
	Console console;

	Console::setInitialProgramSettings();

	do {
		textbackground(BLACK);
		clrscr();
		textcolor(WHITE);

		board.printBoard();

		Menu::printMenu();

		console.printKeyCode(keyCodeText, keyCode);

		console.setInitialConsoleSettings(keyCodeText, cursor.getX(), cursor.getY());

		console.setIsZeroFirstKeyCode(false);
		keyCode = getch();

		if (keyCode == 0) {
			console.setIsZeroFirstKeyCode(true);
			keyCode = getch();

			cursor.moveCursor(keyCode);
		}
		else if (keyCode == ' ') {
			console.setNextTextColor();
		}
		else if (keyCode == ENTER_KEY_CODE or keyCode == '\r') {
			console.setNextBackgroundColor();
		}
	} while (keyCode != 'q');

	_setcursortype(_NORMALCURSOR);

	return 0;
}
