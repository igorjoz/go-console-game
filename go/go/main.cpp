#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "conio2.h"

#include "Board.h"
#include "Console.h"
#include "Cursor.h"
#include "Menu.h"
#include "Player.h"
#include "Helper.h"


int main() {
	Player blackPlayer(BLACK_PLAYER_ID);
	Player whitePlayer(WHITE_PLAYER_ID);

	Board board(BOARD_SIZE, false, &blackPlayer, &whitePlayer);
	Menu menu;
	Cursor cursor;
	Console console;

	Console::setInitialProgramSettings();

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
				cursor.setShouldResetPosition(true);
				board.setIsBoardSizeSelected(true);
				int newSize = board.interpretBoardSizeSelection(cursor);

				if (newSize == -1) {
					menu.setShouldDisplayCustomBoardSizeSelectionModal(true);
					continue;
				}

				board = Board(newSize, true, board.getBlackPlayer(), board.getWhitePlayer());
			}

			continue;
		}

		if (menu.getShouldDisplayCustomBoardSizeSelectionModal()) {
			menu.showCustomBoardSizeSelectionModal(console, cursor);

			console.setKeyCode(NEW_GAME_KEY_CHARACTER);
			
			char digits[100];
			int digitIndex = 0;

			do {
				console.setKeyCode(getche());
				
				digits[digitIndex] = (char)(console.getKeyCode());
				digitIndex++;
				
			} while (console.getKeyCode() != ENTER_KEY_CODE);

			digitIndex--;

			for (int i = 0; i < digitIndex; i++) {
				putch(digits[i]);
			}

			int newSize = Helper::convertDigitsArrayIntoNumber(digits, digitIndex);
			board = Board(newSize, true, board.getBlackPlayer(), board.getWhitePlayer());
			
			menu.setShouldDisplayCustomBoardSizeSelectionModal(false);

			continue;
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
		else if (console.getKeyCode() == SAVE_GAME_KEY_CHARACTER) {
			char fileName[100] = "test.txt";
			board.saveBoardToFile(fileName);

			/*if (menu.getShouldDisplayCustomBoardSizeSelectionModal()) {
				menu.showCustomBoardSizeSelectionModal(console, cursor);

				console.setKeyCode(NEW_GAME_KEY_CHARACTER);

				char digits[100];
				int digitIndex = 0;

				do {
					console.setKeyCode(getche());

					digits[digitIndex] = (char)(console.getKeyCode());
					digitIndex++;

				} while (console.getKeyCode() != ENTER_KEY_CODE);

				digitIndex--;

				for (int i = 0; i < digitIndex; i++) {
					putch(digits[i]);
				}

				int newSize = Helper::convertDigitsArrayIntoNumber(digits, digitIndex);
				board = Board(newSize, true, board.getBlackPlayer(), board.getWhitePlayer());

				menu.setShouldDisplayCustomBoardSizeSelectionModal(false);

				continue;
			}*/
		}
		else if (console.getKeyCode() == LOAD_GAME_KEY_CHARACTER) {
			char fileName[100] = "test.txt";
			board.loadBoardFromFile(fileName);
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
