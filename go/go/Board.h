#pragma once

#ifndef BOARD_H
#define BOARD_H

#include"conio2.h"
#include <cstdlib>
#include <string.h>

#include"Player.h"
#include"Point.h"
//#include"Cursor.h"
#include"Console.h"
#include"constants.h"


class Cursor;


class Board
{
public:
	Board(int size, bool isBoardSizeSelected, Player* player1, Player* player2);
	Board(const Board& previousBoard);

	void printBoard();
	void printTopAndBottomBorder();
	void printLeftAndRightBorder();
	void printBoardStructure();
	void printBorderCorners();
	void printBoardCorners();
	void printBoardState();
	void printIsInGameEditorMode();

	void insertStone();
	bool canInsertStone(int x, int y);
	void removeStonesWithNoLiberties();
	bool hasLiberty(int rowIndex, int columnIndex);
	void changePlayer();
	void incrementCurrentPlayerScore();
	Player* getCurrentPlayer();
	int getCurrentPlayerId();
	Player* getPlayer1();
	Player* getPlayer2();
	

	void restartGame(Console console, Cursor cursor);
	bool getIsInGameEditorMode();
	void setIsInGameEditorMode(bool isInEditorMode);
	bool getIsBoardSizeSelected();
	void setIsBoardSizeSelected(bool isBoardSizeSelected);

	int getBoardValueByCursorPosition(int cursorX, int cursorY);
	void setBoardValueByCursorPosition(int cursorX, int cursorY, short unsigned int value);
	int getBoardValue(int x, int y);
	void setBoardValue(int x, int y, short unsigned int value);

	int getColumnIndex(int cursorX);
	int getRowIndex(int cursorY);

	char* getBoardPositionText(int cursorX, int cursorY);
	char* getCurrentPlayerText();
	char* getPlayersScoreText();

	int interpretBoardSizeSelection(Cursor cursor);
	int getSize();
	void setSize(int size);

	int getTopBoardBorderY();
	void setTopBoardBorderY(int y);
	int getBottomBoardBorderY();
	void setBottomBoardBorderY(int y);
	int getLeftBoardBorderX();
	void setLeftBoardBorderX(int x);
	int getRightBoardBorderX();
	void setRightBoardBorderX(int x);

private:
	int size;
	bool isInEditorMode;
	bool isBoardSizeSelected;
	short unsigned int** board;
	Player* player1;
	Player* player2;
	Player* currentPlayer;

	int topBoardBorderY = VERTICAL_BOARD_PADDING + 1;
	int bottomBoardBorderY = BOARD_SIZE + VERTICAL_BOARD_PADDING + 2;
	int leftBoardBorderX = HORIZONTAL_BOARD_PADDING + 1;
	int rightBoardBorderX = (BOARD_SIZE * 2) + HORIZONTAL_BOARD_PADDING + 3;
};

#endif
