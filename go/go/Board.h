#pragma once


#ifndef BOARD_H
#define BOARD_H


#include"conio2.h"
#include <cstdlib>
#include <string.h>

#include"Player.h"
#include"Point.h"
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

	int getSize();
	bool getIsInGameEditorMode();
	bool getIsBoardSizeSelected();
	Player* getCurrentPlayer();
	int getCurrentPlayerId();
	Player* getPlayer1();
	Player* getPlayer2();
	
	int getBoardValueByCursorPosition(int cursorX, int cursorY);
	int getBoardValue(int x, int y);
	int getRowIndex(int cursorY);
	int getColumnIndex(int cursorX);

	char* getBoardPositionText(int cursorX, int cursorY);
	char* getCurrentPlayerText();
	char* getPlayersScoreText();

	int getTopBoardBorderY();
	int getBottomBoardBorderY();
	int getLeftBoardBorderX();
	int getRightBoardBorderX();

	
	void setSize(int size);
	void setIsInGameEditorMode(bool isInEditorMode);
	void setIsBoardSizeSelected(bool isBoardSizeSelected);

	void setTopBoardBorderY(int y);
	void setBottomBoardBorderY(int y);
	void setLeftBoardBorderX(int x);
	void setRightBoardBorderX(int x);
	
	void setBoardValueByCursorPosition(int cursorX, int cursorY, short unsigned int value);
	void setBoardValue(int x, int y, short unsigned int value);
	

	bool insertStone();
	bool isPositionOccupied(int rowIndex, int columnIndex);
	bool isStoneSuicider(int rowIndex, int columnIndex);
	bool isKo();
	void removeStonesWithNoLiberties();
	bool hasLiberty(int rowIndex, int columnIndex);
	void changePlayer();
	void incrementCurrentPlayerScore();

	void restartGame(Console console, Cursor cursor);
	
	int interpretBoardSizeSelection(Cursor cursor);
	
	void captureChain(int rowIndex, int columnIndex, int color);
	bool isSurroundedBySameColorChain(int rowIndex, int columnIndex, int color);
	bool isPartOfSameColorChain(int rowIndex, int columnIndex, int color);
	

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
