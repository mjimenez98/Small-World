#include "Dice.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

	Dice::Dice()
	{
		totalRolls = 0;
		srand(time(NULL)); //seed random number with the current time

	}

	//rolls 1 or many dice, depending on the number parameter
	 int Dice::roll()
	{
		 int * percent = percentages; 
		 
			int roll = 1 + rand() % 6;


			if (roll == 1 || roll == 2 || roll == 3)
			{
				percent[roll - 1] += 1;
				totalRolls += 1;
				return roll;
			}

			else
			{
				
				percent[3] += 1;
				totalRolls += 1;
				return 0;
			}

		 
	}

	 void Dice::displayPercentages()
	 {
		 
		 cout << "Results: " << endl <<
		     "1: " << (percentages[0]*100 / totalRolls) << " %" <<
			 "\n2: " << (percentages[1] * 100 / totalRolls) << " %" <<
			 "\n3: " << (percentages[2] * 100 / totalRolls) << " %" <<
			 "\n0: " << (percentages[3] * 100 / totalRolls) << " %" << endl;
	 }


	Dice::~Dice()
	{
	}
