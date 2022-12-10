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
	Player player1(WHITE_PLAYER_ID);
	Player player2(BLACK_PLAYER_ID);
	
	Board board(&player1, &player2);
	Menu menu;
	Cursor cursor;
	Console console;

	Console::setInitialProgramSettings();

	board.setIsInGameEditorMode(false);

	do {
		console.refreshSettings();
		board.printBoard();
		menu.printMenu(console, board, cursor);

		console.setIsZeroFirstKeyCode(false);
		console.setKeyCode(getch());

		if (console.getKeyCode() == 0) {
			console.setIsZeroFirstKeyCode(true);
			console.setKeyCode(getch());

			cursor.moveCursor(console.getKeyCode());
		}
		else if (console.getKeyCode() == INSERT_STONE_KEY_CHARACTER) {
			board.insertStone();
		}
		else if (console.getKeyCode() == NEW_GAME_KEY_CHARACTER) {
			board.restartGame();
		}
		else if (console.getKeyCode() == ENTER_EXIT_GAME_EDITOR_KEY_CHARACTER) {
			bool newState = !board.getIsInGameEditorMode();
			board.setIsInGameEditorMode(newState);
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
