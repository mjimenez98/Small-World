#pragma once

class Dice
{
	int percentages [4] = { 0 };
	int totalRolls = 0;
	
public:
	int roll();
	void displayPercentages();
	Dice();
	~Dice();
};


