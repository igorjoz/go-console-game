#pragma once

#include"conio2.h"
#include <cstdlib>
#include <string.h>

#include"Player.h"
#include"Point.h"
#include"Cursor.h"
#include"constants.h"


class Board
{
public:
	Board(Player* player1, Player* player2);
	Board(const Board& previousBoard);
	
	void printBoard();
	void static printTopAndBottomBorder();
	void static printLeftAndRightBorder();
	void static printBoardStructure();
	void static printBorderCorners();
	void static printBoardCorners();
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

	void restartGame();
	bool getIsInGameEditorMode();
	void setIsInGameEditorMode(bool isInEditorMode);
	
	int getBoardValueByCursorPosition(int cursorX, int cursorY);
	void setBoardValueByCursorPosition(int cursorX, int cursorY, short unsigned int value);
	int getBoardValue(int x, int y);
	void setBoardValue(int x, int y, short unsigned int value);
	
	int getColumnIndex(int cursorX);
	int getRowIndex(int cursorY);

	char* getBoardPositionText(int cursorX, int cursorY);
	char* getCurrentPlayerText();
	char* getPlayersScoreText();

private:
	int boardSize;
	bool isInEditorMode;
	short unsigned int **board;
	Player* player1;
	Player* player2;
	Player* currentPlayer;
};
