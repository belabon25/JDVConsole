#pragma once

#include <string>
class JDVCell
{
public:
	JDVCell();
	JDVCell(bool st, bool isBorder=false);
	std::string toString();
	void turnAlive();
	void turnDead();
	bool getStatus();
	void setBorder(bool isBorder);
	bool getBorder();
private:
	bool status=false;
	bool border = false;
};

