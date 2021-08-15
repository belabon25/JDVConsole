#include "JDVScreen.h"
#include <iostream>

JDVScreen::JDVScreen()
{
	int i,j;
	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
		    if(i==0 || j==0 || i==WIDTH-1||j==LENGTH-1)
			{
				screen[i][j] = JDVCell(false,true);
			}
			else
			{
				screen[i][j] = JDVCell(false);
			}
		}
	}

	screen[20][3].turnAlive();
	screen[20][4].turnAlive();
	screen[20][5].turnAlive();
	screen[4][3].turnAlive();
	screen[4][4].turnAlive();
	screen[3][4].turnAlive();
	screen[3][3].turnAlive();

}

void JDVScreen::printScreen()
{
	std::string sortie = "";
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			sortie= sortie + screen[i][j].toString();
		}
		sortie = sortie + "\n";
	}
	std::cout << sortie;
}

void JDVScreen::setScreen(JDVCell sc[WIDTH][LENGTH])
{
	for (int i=1; i <= WIDTH - 2; i++)
	{
		for (int j=1; j <= LENGTH - 2; j++)
		{
			screen[i][j] = sc[i][j];
		}
	}
}

/*
012
3 4
567
*/
void JDVScreen::updateScreen() 
{
	JDVCell screenTemp[WIDTH][LENGTH]{};
	
	int i=1, j=1,numberNeighborCell;
	bool k[8];
	for (i=1; i < WIDTH - 2; i++)
	{
		for (j=1; j < LENGTH - 2; j++)
		{
			if (!screen[i][j].getBorder())
			{
				for(int tableResetter=0;tableResetter<8;tableResetter++)
				{
					k[tableResetter] = true;
				}				
				k[0] = screen[i - 1][j - 1].getBorder() ? false : screen[i - 1][j - 1].getStatus();
				k[1] = screen[i - 1][j].getBorder() ? false : screen[i - 1][j].getStatus();
				k[2] = screen[i - 1][j + 1].getBorder() ? false : screen[i - 1][j + 1].getStatus();
				k[3] = screen[i][j - 1].getBorder() ? false : screen[i][j - 1].getStatus();
				k[4] = screen[i][j + 1].getBorder() ? false : screen[i][j + 1].getStatus();
				k[5] = screen[i + 1][j - 1].getBorder() ? false : screen[i + 1][j - 1].getStatus();
				k[6] = screen[i + 1][j].getBorder() ? false : screen[i + 1][j].getStatus();
				k[7] = screen[i + 1][j + 1].getBorder() ? false : screen[i + 1][j + 1].getStatus();

				numberNeighborCell = 0;
				for (int cpt = 0; cpt < 8; cpt++)
				{
					if (k[cpt])
					{
						numberNeighborCell++;
					}
				}
				if (screen[i][j].getStatus() && (numberNeighborCell == 2 || numberNeighborCell == 3))
				{
					//si en vie 2 ou 3
					screenTemp[i][j].turnAlive();
				}
				else if ((!screen[i][j].getStatus()) && numberNeighborCell == 3)
				{
					//si mort 3
					screenTemp[i][j].turnAlive();
				}
				else
				{
					//sinon
					screenTemp[i][j].turnDead();
				}
			}
		}
	}
	setScreen(screenTemp);
}


