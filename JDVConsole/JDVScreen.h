#pragma once
#include "JDVCell.h"

#define WIDTH 49
#define LENGTH 210

class JDVScreen
{
private:
	JDVCell screen[WIDTH][LENGTH];

public:
	void setScreen(JDVCell sc[WIDTH][LENGTH]);
	void printScreen();
	JDVScreen();
	void updateScreen();

};

