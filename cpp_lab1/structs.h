#pragma once
#include <vector>
#include <iostream>

struct GameField
{
	int playgroundSize = 2;

	std::vector<std::vector<int>> matrix;

	int countOFstep = 0;

	int row = 3;
	int col = 3;

	void initPlayground();

	//void drowPlayground();

	//void step(int dice);

	int stepCheck(int dice);

	void gameStatusCheck();

};

std::ostream& operator<<(std::ostream& os, const GameField& gf);

GameField& operator+=(GameField& field,int dice);
