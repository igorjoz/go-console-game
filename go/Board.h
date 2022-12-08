#pragma once

#include"conio2.h"

#include"Player.h"


int const BOARD_SIZE = 9;

int const VERTICAL_BOARD_PADDING = 2;
int const HORIZONTAL_BOARD_PADDING = 4;

int constexpr TOP_BOARD_BORDER_Y = VERTICAL_BOARD_PADDING + 1;
int constexpr BOTTOM_BOARD_BORDER_Y = BOARD_SIZE + VERTICAL_BOARD_PADDING + 1;
int constexpr LEFT_BOARD_BORDER_X = HORIZONTAL_BOARD_PADDING + 1;
int constexpr RIGHT_BOARD_BORDER_X = BOARD_SIZE + HORIZONTAL_BOARD_PADDING + 1;

int const I_KEY_CODE = 0x69;

class Board
{
public:
	Board(Player player = Player(1));
	//Board();
	void printBoard();
	void insertStone(int x, int y);
	//Player getCurrentPlayer();

private:
	int boardSize;
	short unsigned int board[BOARD_SIZE][BOARD_SIZE];
	Player currentPlayer = Player(1);
};
