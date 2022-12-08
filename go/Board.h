#pragma once


int const BOARD_SIZE = 9;


class Board
{
public:
	Board();
	void printBoard();

private:
	int board[9];
};


