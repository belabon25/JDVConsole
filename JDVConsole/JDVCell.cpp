#include "JDVCell.h"

JDVCell::JDVCell()
{
	border = false;
	status = false;
}
JDVCell::JDVCell(bool st, bool isBorder) : status(st)
{
	border = isBorder;
}

bool JDVCell::getStatus()
{
	return JDVCell::status;
}
void JDVCell::setBorder(bool isBorder)
{
	border = isBorder;
	status = false;
}
bool JDVCell::getBorder()
{
	return border;
}

void JDVCell::turnAlive()
{
	if (!border)
		JDVCell::status = true;
}

void JDVCell::turnDead()
{
	if (!border)
		status = false;
}

std::string JDVCell::toString()
{
	switch (border)
	{
	case(true):
		return "@";
	case(false):
		break;
	}
	switch (status)
	{
		case(true) :
			return "#";
		case(false) :
			return ".";
	}
}
