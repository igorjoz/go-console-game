#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"conio2.h"

/* Comment: in the final program declare appropriate constants, e.g.,
   to eliminate from your program numerical values by replacing them
   with well defined identifiers */

int main() {
	int zn = 0, x = 40, y = 12, attr = 7, back = 0, zero = 0;
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

		gotoxy(48, 1);
		cputs("q       = exit");
		gotoxy(48, 2);
		cputs("cursors = moving");
		gotoxy(48, 3);
		cputs("space   = change color");
		gotoxy(48, 4);
		cputs("enter   = change background color");

		if (zero) {
			sprintf(txt, "key code: 0x00 0x%02x", zn);
		}
		else {
			sprintf(txt, "key code: 0x%02x", zn);
		}

		gotoxy(48, 5);
		cputs(txt);

		gotoxy(x, y);
		textcolor(attr);
		textbackground(back);
		putch('*');

		// most key codes correspond to the characters, like
		// a is 'a', 2 is '2', + is '+', but some special keys
		// like cursors provide two characters, where the first
		// one is zero, e.g., "up arrow" is zero and 'H'
		zero = 0;
		zn = getch();
		// we do not want the key 'H' to play role of "up arrow"
		// so we check if the first code is zero
		if (zn == 0) {
			zero = 1;		// if this is the case then we read
			zn = getch();		// the next code knowing that this
			if (zn == 0x48) y--;	// will be a special key
			else if (zn == 0x50) y++;
			else if (zn == 0x4b) x--;
			else if (zn == 0x4d) x++;
		}
		else if (zn == ' ') attr = (attr + 1) % 16;
		else if (zn == 0x0d) back = (back + 1) % 16;	// enter key is 0x0d or '\r'
	} while (zn != 'q');

	_setcursortype(_NORMALCURSOR);	// show the cursor so it will be
					// visible after the program ends
	return 0;
}
