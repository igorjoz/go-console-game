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
	Board(int size, bool isBoardSizeSelected, Player* blackPlayer, Player* whitePlayer);
	Board(const Board& previousBoard);

	void printBoard();

	bool insertStone();
	void removeStonesWithNoLiberties();
	void changePlayer();
	void incrementCurrentPlayerScore();
	void incrementBlackPlayerScore();
	void incrementWhitePlayerScore();
	void restartGame(Console console, Cursor cursor);
	
	bool isPositionOccupied(int rowIndex, int columnIndex);
	bool isStoneSuicider(int rowIndex, int columnIndex);
	bool isKo();
	bool areBoardsEqual();
	
	bool hasLiberty(int rowIndex, int columnIndex);
	
	int interpretBoardSizeSelection(Cursor cursor);

	void captureChain(int rowIndex, int columnIndex, int color);
	bool isSurroundedBySameColorChain(int rowIndex, int columnIndex, int color);
	bool isPartOfSameColorChain(int rowIndex, int columnIndex, int color);
	

	// BoardPrintService
	void printTopAndBottomBorder();
	void printLeftAndRightBorder();
	void printBoardStructure();
	void printBorderCorners();
	void printBoardCorners();
	void printBoardState();
	void printIsInGameEditorMode();

	
	// BoardGetService
	int getSize();
	bool getIsInGameEditorMode();
	bool getIsBoardSizeSelected();
	Player* getCurrentPlayer();
	int getCurrentPlayerId();
	Player* getBlackPlayer();
	Player* getWhitePlayer();
	
	short unsigned int getBoardValueByCursorPosition(int cursorX, int cursorY);
	short unsigned int getBoardValue(int rowIndex, int columnIndex);
	short unsigned int getPreviousBoardValue(int rowIndex, int columnIndex);
	int getRowIndex(int cursorY);
	int getColumnIndex(int cursorX);

	char* getBoardPositionText(int cursorX, int cursorY);
	char* getCurrentPlayerText();
	char* getPlayersScoreText();

	int getTopBoardBorderY();
	int getBottomBoardBorderY();
	int getLeftBoardBorderX();
	int getRightBoardBorderX();

	
	// BoardSetService
	void setSize(int size);
	void setIsInGameEditorMode(bool isInEditorMode);
	void setIsBoardSizeSelected(bool isBoardSizeSelected);

	void setTopBoardBorderY(int y);
	void setBottomBoardBorderY(int y);
	void setLeftBoardBorderX(int x);
	void setRightBoardBorderX(int x);
	
	void setBoardValueByCursorPosition(int cursorX, int cursorY, short unsigned int value);
	void setBoardValue(int rowIndex, int columnIndex, short unsigned int value);
	void setPreviousBoardValue(int rowIndex, int columnIndex, short unsigned int value);
	

private:
	int size;
	bool isInGameEditorMode;
	bool isBoardSizeSelected;
	short unsigned int** board;
	short unsigned int** previousBoard;
	Player* blackPlayer;
	Player* whitePlayer;
	Player* currentPlayer;

	int topBoardBorderY;
	int bottomBoardBorderY;
	int leftBoardBorderX;
	int rightBoardBorderX;
};


#endif
