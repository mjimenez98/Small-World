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
	 int Dice::roll(int number)
	{
		 int * percent = percentages; 

		 if (number < 0 || number>3)
		 {
			 cout << "Invalid number of dice." << endl;
				 return -1; //return -1 if number is invalid.
		 }

		 int finalValue = 0;

		 //each iteration of the loop is a roll of a die.
		 for (int j = 0; j < number; ++j)
		 {
			int tempRoll = 1 + rand() % 6;
			percent[tempRoll-1] += 1;
			totalRolls += 1;
			
			finalValue += tempRoll;
			
		 }

		 return finalValue;

		 percent = NULL;
		 
	}

	 void Dice::displayPercentages()
	 {
		 
		 cout << "1: " << (percentages[0]*100 / totalRolls) << " %" <<
			 "\n2: " << (percentages[1] * 100 / totalRolls) << " %" <<
			 "\n3: " << (percentages[2] * 100 / totalRolls) << " %" <<
			 "\n4: " << (percentages[3] * 100 / totalRolls) << " %" <<
			 "\n5: " << (percentages[4] * 100 / totalRolls) << " %" <<
			 "\n6: " << (percentages[5] * 100 / totalRolls) << " %" << endl;
	 }


	Dice::~Dice()
	{
	}

int main()
{
	Dice d1;
	//cout<< "You rolled a: "<<d1.roll(3)<<"\n "<<endl;

	for (int k = 0; k < 1000; ++k)
		d1.roll(3);

	

	d1.displayPercentages();
	system("pause");
}