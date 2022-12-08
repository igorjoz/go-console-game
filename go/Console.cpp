#define _CRT_SECURE_NO_WARNINGS

#include "Console.h"


Console::Console() {
	this->textColorCode = WHITE;
	this->backgroundColorCode = BLACK;
	this->isZeroFirstKeyCode = false;
}


void Console::setInitialProgramSettings() {
#ifndef __cplusplus
	Conio2_Init();
#endif

	settitle("Igor Jozefowicz, 193257");
	_setcursortype(_NOCURSOR);
}


void Console::setInitialConsoleSettings(char keyCodeText[], int x, int y) {
	gotoxy(48, 5);
	cputs(keyCodeText);

	gotoxy(x, y);
	textcolor(this->textColorCode);
	textbackground(this->backgroundColorCode);

	putch('@');
}


void Console::printKeyCode(char keyCodeText[], int keyCode) {
	if (this->isZeroFirstKeyCode) {
		sprintf(keyCodeText, "key code: 0x00 0x%02x", keyCode);
	}
	else {
		sprintf(keyCodeText, "key code: 0x%02x", keyCode);
	}
}


void Console::setNextTextColor() {
	this->textColorCode = ((this->textColorCode) + 1) % 16;
}


void Console::setNextBackgroundColor() {
	this->backgroundColorCode = ((this->backgroundColorCode) + 1) % 16;
}


int Console::getIsZeroFirstKeyCode() {
	return this->isZeroFirstKeyCode;
}

void Console::setIsZeroFirstKeyCode(bool isZeroFirstKeyCode) {
	this->isZeroFirstKeyCode = isZeroFirstKeyCode;
}
