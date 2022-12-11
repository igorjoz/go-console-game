#pragma once


#ifndef CONSOLE_H
#define CONSOLE_H


#include "conio2.h"
#include<stdio.h>

#include "constants.h"


class Console
{
public:
	Console();
	void static setInitialProgramSettings();
	void setInitialConsoleSettings(int x, int y);
	void setCursor(int x, int y);
	void refreshSettings();
	void printKeyCode();
	void setNextTextColor();
	void setNextBackgroundColor();
	int getIsZeroFirstKeyCode();
	void setIsZeroFirstKeyCode(bool isZeroFirstCode);
	int getKeyCode();
	void setKeyCode(int keyCode);
	char* getKeyCodeText();
	void setKeyCodeText(char keyCodeText[]);

private:
	int textColorCode;
	int backgroundColorCode;
	bool isZeroFirstKeyCode;
	int keyCode;
	char keyCodeText[32];
};


#endif
