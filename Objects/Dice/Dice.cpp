#include "Dice.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

	Dice::Dice()
	{
		totalRolls = 0;
		srand((unsigned int) time(nullptr)); //seed random number with the current time
	}

	//rolls 1 or many dice, depending on the number parameter
	 int Dice::roll()
	{
		 
		int roll = 1 + rand() % 6;

		if (roll == 1 || roll == 2 || roll == 3)
		{
			totalRolls++;
			return roll;
		}

		else {
			totalRolls++;
			return 0;
		}
		 
	}
