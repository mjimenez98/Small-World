#pragma once
class Dice
{
	int percentages [6] = { 0 };
	int totalRolls;
	
public:
	int roll(int);
	void displayPercentages();
	Dice();
	~Dice();
};

