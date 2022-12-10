#define _CRT_SECURE_NO_WARNINGS

#include "Console.h"


Console::Console() {
	this->textColorCode = WHITE;
	this->backgroundColorCode = BLACK;
	this->isZeroFirstKeyCode = false;
	this->keyCode = 0;
	//this->keyCodeText = keyCodeText;
}


void Console::setInitialProgramSettings() {
#ifndef __cplusplus
	Conio2_Init();
#endif

	settitle(AUTHOR_NAME_SURNAME_INDEX);
	_setcursortype(_NOCURSOR);
}


void Console::setInitialConsoleSettings(int x, int y) {
	gotoxy(MENU_DISTANCE, KEY_CODE_ROW);
	cputs(this->keyCodeText);

	this->setCursor(x, y);
}


void Console::setCursor(int x, int y) {
	gotoxy(x, y);
	textcolor(this->textColorCode);
	textbackground(this->backgroundColorCode);

	putch('@');
}


void Console::refreshSettings() {
	textbackground(this->backgroundColorCode);
	clrscr();
	textcolor(this->textColorCode);

	settitle(AUTHOR_NAME_SURNAME_INDEX);
}


void Console::printKeyCode() {
	if (this->isZeroFirstKeyCode) {
		sprintf(this->keyCodeText, "key code: 0x00 0x%02x", this->keyCode);
	}
	else {
		sprintf(this->keyCodeText, "key code: 0x%02x", this->keyCode);
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


int Console::getKeyCode() {
	return this->keyCode;
}

void Console::setKeyCode(int keyCode) {
	this->keyCode = keyCode;
}


char* Console::getKeyCodeText() {
	return this->keyCodeText;
}

void Console::setKeyCodeText(char keyCodeText[]) {
	for (int i = 0; i < 32; i++) {
		this->keyCodeText[i] = keyCodeText[i];
	}
}
