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
	Player blackPlayer(BLACK_PLAYER_ID, 0);
	Player whitePlayer(WHITE_PLAYER_ID, 0);

	Board board(BOARD_SIZE, false, &blackPlayer, &whitePlayer, BLACK_PLAYER_ID);
	Menu menu;
	Cursor cursor;
	Console console;

	Console::setInitialProgramSettings();

	do {
		console.refreshSettings();

		if (!board.getIsBoardSizeSelected()) {
			if (cursor.getShouldResetPosition()) {
				cursor.resetToModalInitialPosition();
			}
			
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

				board = Board(newSize, true, board.getBlackPlayer(), board.getWhitePlayer(), BLACK_PLAYER_ID);
			}

			continue;
		}

		if (menu.getShouldDisplayCustomBoardSizeSelectionModal()) {
			if (cursor.getShouldResetPosition()) {
				cursor.resetToModalInitialPosition();
			}
			
			menu.showCustomBoardSizeSelectionModal(console, cursor);

			char digits[100];
			int digitIndex = 0;

			do {
				console.setKeyCode(getche());
				
				digits[digitIndex] = (char)(console.getKeyCode());
				digitIndex++;
				
			} while (console.getKeyCode() != ENTER_KEY_CODE);

			digitIndex--;

			int newSize = Helper::convertDigitsArrayIntoNumber(digits, digitIndex);
			board = Board(newSize, true, board.getBlackPlayer(), board.getWhitePlayer(), BLACK_PLAYER_ID);
			
			menu.setShouldDisplayCustomBoardSizeSelectionModal(false);

			continue;
		}

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
		else if (console.getKeyCode() == SAVE_GAME_KEY_CHARACTER) {
			//char fileName[100] = "test.txt";
			//board.saveBoardToFile(fileName);

			if (menu.getShouldDisplayFileNameInput()) {
				menu.showFileNameInputModal(console, cursor);

				char characters[100] = {};
				int characterIndex = 0;

				do {
					console.setKeyCode(getche());

						characters[characterIndex] = (char)(console.getKeyCode());
						characterIndex++;
				} while (console.getKeyCode() != ENTER_KEY_CODE);

				characterIndex--;

				characters[characterIndex] = '\0';
				
				board.saveBoardToFile(characters);

				//menu.setShouldDisplayFileNameInput(false);

				continue;
			}
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
