#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"conio2.h"

#include"Board.h"
#include"Console.h"
#include"Cursor.h"
#include"Menu.h"
#include"Player.h"


int main() {
	Player player1(WHITE_PLAYER_ID);
	Player player2(BLACK_PLAYER_ID);

	Board board(&player1, &player2);
	Menu menu;
	Cursor cursor;
	Console console;

	Console::setInitialProgramSettings();

	// reset cursor
	/*cursor.setX(INITIAL_CURSOR_X_POSITION);
	cursor.setY(INITIAL_CURSOR_Y_POSITION);*/
	cursor.resetToInitialPosition();

	do {
		if (cursor.getShouldResetPosition()) {
			cursor.resetToInitialPosition();
		}

		console.refreshSettings();

		if (!board.getIsBoardSizeSelected()) {
			menu.showBoardSizeSelectionModal(console, cursor);

			console.setIsZeroFirstKeyCode(false);
			console.setKeyCode(getch());

			if (console.getKeyCode() == 0) {
				console.setIsZeroFirstKeyCode(true);
				console.setKeyCode(getch());

				cursor.moveCursorInBoardSizeSelectionModal(console.getKeyCode());
			}
			else if (console.getKeyCode() == ENTER_KEY_CODE or console.getKeyCode() == '\r') {
				board.setIsBoardSizeSelected(true);
				cursor.setShouldResetPosition(true);
				board.handleBoardSizeSelection(cursor);
			}
			//else if (console.getKeyCode() == 0x74) {
			//	gotoxy(BOARD_SIZE_SELECTION_MODAL_DISTANCE, 2);
			//	cputs("test");
			//}
		}
		else {
			if (cursor.getShouldResetPosition()) {
				cursor.resetToInitialPosition();
			}

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
				board.restartGame(console, cursor);
				cursor.setShouldResetPosition(true);
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
		}
	} while (console.getKeyCode() != 'q');

	_setcursortype(_NORMALCURSOR);

	return 0;
}
