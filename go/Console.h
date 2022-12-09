#pragma once

#include "conio2.h"
#include<stdio.h>

class Menu;


char const AUTHOR_NAME_SURNAME_INDEX[30] = "Igor Jozefowicz, 193257";
int const KEY_CODE_ROW = 11;


class Console
{
public:
	Console();
	void static setInitialProgramSettings();
	void setInitialConsoleSettings(int x, int y);
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
