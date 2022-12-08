#pragma once

#include "conio2.h"
#include<stdio.h>


class Console
{
public:
	Console();
	void static setInitialProgramSettings();
	void setInitialConsoleSettings(char keyCodeText[], int x, int y);
	void printKeyCode(char keyCodeText[], int keyCode);
	void setNextTextColor();
	void setNextBackgroundColor();
	int getIsZeroFirstKeyCode();
	void setIsZeroFirstKeyCode(bool isZeroFirstCode);

private:
	int textColorCode;
	int backgroundColorCode;
	bool isZeroFirstKeyCode;
};
