#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"conio2.h"

#include"Board.h"
#include"Console.h"
#include"Cursor.h"
#include"Menu.h"
#include"Player.h"


int const ENTER_KEY_CODE = 0x0d;


int main() {
	Player player1(1);
	Player player2(2);
	
	//Board board(player1);
	Board board;
	Menu menu;
	Cursor cursor;
	Console console;

	Console::setInitialProgramSettings();

	do {
		console.refreshSettings();
		board.printBoard();
		menu.printMenu(console, cursor);

		console.setIsZeroFirstKeyCode(false);
		console.setKeyCode(getch());

		if (console.getKeyCode() == 0) {
			console.setIsZeroFirstKeyCode(true);
			console.setKeyCode(getch());

			cursor.moveCursor(console.getKeyCode());
		}
		else if (console.getKeyCode() == I_KEY_CODE) {
			board.insertStone(cursor.getX(), cursor.getY());
		}
		else if (console.getKeyCode() == ' ') {
			console.setNextTextColor();
		}
		else if (console.getKeyCode() == ENTER_KEY_CODE or console.getKeyCode() == '\r') {
			console.setNextBackgroundColor();
		}
	} while (console.getKeyCode() != 'q');

	_setcursortype(_NORMALCURSOR);

	return 0;
}
