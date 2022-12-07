#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"conio2.h"

#include"Board.h"


int const LEFT_ARROW_KEY_CODE = 0x4b;
int const RIGHT_ARROW_KEY_CODE = 0x4d;
int const UP_ARROW_KEY_CODE = 0x48;
int const DOWN_ARROW_KEY_CODE = 0x50;
int const ENTER_KEY_CODE = 0x0d;

int const BOARD_SIZE = 9;
int const MENU_DISTANCE = 48;

int const INITIAL_CURSOR_X_POSITION = 2;
int const INITIAL_CURSOR_Y_POSITION = 2;


void setInitialProgramSettings() {
	#ifndef __cplusplus
		Conio2_Init();
	#endif

	settitle("Igor Jozefowicz, 193257");
	_setcursortype(_NOCURSOR);
}


void setInitialConsoleSettings(char keyCodeText[], int x, int y, int textColorCode, int backgroundColorCode) {
	gotoxy(48, 5);
	cputs(keyCodeText);

	gotoxy(x, y);
	textcolor(textColorCode);
	textbackground(backgroundColorCode);

	putch('@');
}


void printMenu() {
	gotoxy(MENU_DISTANCE, 1);
	cputs("q       = exit");
	gotoxy(MENU_DISTANCE, 2);
	cputs("cursors = moving");
	gotoxy(MENU_DISTANCE, 3);
	cputs("space   = change color");
	gotoxy(MENU_DISTANCE, 4);
	cputs("enter   = change background color");
}


void printKeyCode(bool isZeroFirstKeyCode, char keyCodeText[], int keyCode) {
	if (isZeroFirstKeyCode) {
		sprintf(keyCodeText, "key code: 0x00 0x%02x", keyCode);
	}
	else {
		sprintf(keyCodeText, "key code: 0x%02x", keyCode);
	}
}


void printBoard() {
	for (int columnIndex = 1; columnIndex <= BOARD_SIZE + 2; columnIndex++) {
		gotoxy(columnIndex, 1);
		putch('-');
	}
	
	for (int rowIndex = 2; rowIndex < BOARD_SIZE + 2; rowIndex++) {
		for (int columnIndex = 2; columnIndex < BOARD_SIZE + 2; columnIndex++) {
			gotoxy(columnIndex, rowIndex);
			putch('+');
		}
	}
	
	

	for (int rowIndex = 1; rowIndex <= BOARD_SIZE + 2; rowIndex++) {
		gotoxy(1, rowIndex);
		putch('|');
	}

	for (int rowIndex = 1; rowIndex <= BOARD_SIZE + 2; rowIndex++) {
		gotoxy(BOARD_SIZE + 2, rowIndex);
		putch('|');
	}

	for (int columnIndex = 1; columnIndex <= BOARD_SIZE + 2; columnIndex++) {
		gotoxy(columnIndex, BOARD_SIZE + 2);
		putch('-');
	}
}


void moveCursor(int keyCode, int* x, int* y) {
	if (keyCode == LEFT_ARROW_KEY_CODE and *x > 2) {
		(*x)--;
	}
	else if (keyCode == RIGHT_ARROW_KEY_CODE and *x < BOARD_SIZE + 1) {
		(*x)++;
	}
	else if (keyCode == UP_ARROW_KEY_CODE and *y > 2) {
		(*y)--;
	}
	else if (keyCode == DOWN_ARROW_KEY_CODE and *y < BOARD_SIZE + 1) {
		(*y)++;
	}
}


void setNextTextColor(int* textColorCode) {
	*textColorCode = ((*textColorCode) + 1) % 16;
}


void setNextBackgroundColor(int* backgroundColorCode) {
	*backgroundColorCode = ((*backgroundColorCode) + 1) % 16;
}


int main() {
	int keyCode = 0;
	int x = INITIAL_CURSOR_X_POSITION, y = INITIAL_CURSOR_Y_POSITION;
	int textColorCode = WHITE, backgroundColorCode = BLACK;
	bool isZeroFirstKeyCode = false;
	char keyCodeText[32];

	setInitialProgramSettings();

	do {
		textbackground(BLACK);
		clrscr();
		textcolor(WHITE);

		printBoard();

		printMenu();

		printKeyCode(isZeroFirstKeyCode, keyCodeText, keyCode);

		setInitialConsoleSettings(keyCodeText, x, y, textColorCode, backgroundColorCode);

		isZeroFirstKeyCode = false;
		keyCode = getch();

		if (keyCode == 0) {
			isZeroFirstKeyCode = true;
			keyCode = getch();

			moveCursor(keyCode, &x, &y);
		}
		else if (keyCode == ' ') {
			setNextTextColor(&textColorCode);
		}
		else if (keyCode == ENTER_KEY_CODE or keyCode == '\r') {
			setNextBackgroundColor(&backgroundColorCode);
		}
	} while (keyCode != 'q');

	_setcursortype(_NORMALCURSOR);

	return 0;
}
