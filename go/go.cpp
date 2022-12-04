#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"conio2.h"


int const LEFT_ARROW_KEY_CODE = 0x4b;
int const RIGHT_ARROW_KEY_CODE = 0x4d;
int const UP_ARROW_KEY_CODE = 0x48;
int const DOWN_ARROW_KEY_CODE = 0x50;
int const ENTER_KEY_CODE = 0x0d;

int const MENU_DISTANCE = 48;


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


int main() {
	int keyCode = 0;
	int x = 40, y = 12;
	int textColorCode = 7, backgroundColorCode = 0;
	bool isZeroFirstKeyCode = false;
	char txt[32];

	#ifndef __cplusplus
		Conio2_Init();
	#endif

	settitle("Igor Jozefowicz, 193257");
	_setcursortype(_NOCURSOR);

	do {
		textbackground(BLACK);
		clrscr();
		textcolor(WHITE);

		printMenu();

		if (isZeroFirstKeyCode) {
			sprintf(txt, "key code: 0x00 0x%02x", keyCode);
		}
		else {
			sprintf(txt, "key code: 0x%02x", keyCode);
		}

		gotoxy(48, 5);
		cputs(txt);

		gotoxy(x, y);
		textcolor(textColorCode);
		textbackground(backgroundColorCode);
		putch('*');

		isZeroFirstKeyCode = false;
		keyCode = getch();

		if (keyCode == 0) {
			isZeroFirstKeyCode = true;
			keyCode = getch();

			if (keyCode == UP_ARROW_KEY_CODE) {
				y--;
			}
			else if (keyCode == DOWN_ARROW_KEY_CODE) {
				y++;
			}
			else if (keyCode == LEFT_ARROW_KEY_CODE) {
				x--;
			}
			else if (keyCode == RIGHT_ARROW_KEY_CODE) {
				x++;
			}
		}
		else if (keyCode == ' ') {
			textColorCode = (textColorCode + 1) % 16;
		}
		else if (keyCode == ENTER_KEY_CODE or keyCode == '\r') {
			backgroundColorCode = (backgroundColorCode + 1) % 16;
		}
	} while (keyCode != 'q');

	_setcursortype(_NORMALCURSOR);

	return 0;
}
