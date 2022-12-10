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
	Board(Player player1, Player player2);
	Board(const Board& previousBoard);
	void printBoard();
	void static printTopAndBottomBorder();
	void static printLeftAndRightBorder();
	void static printBoardStructure();
	void static printBorderCorners();
	void static printBoardCorners();
	void printBoardState();
	void insertStone(int cursorX, int cursorY);
	int getBoardValue(int x, int y);
	void setBoardValue(int x, int y, short unsigned int value);
	char* getBoardPositionText(int cursorX, int cursorY);
	int getColumnIndex(int cursorX);
	int getRowIndex(int cursorY);
	void newGame();
	void changePlayer();
	Player getCurrentPlayer();

private:
	int boardSize;
	short unsigned int **board;
	Player currentPlayer;
	Player player1, player2;
};
