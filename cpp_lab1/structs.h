#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include<iomanip>
#include "input.h"

struct GameField
{
	int gameMod = 0;

	int playgroundSize = 2;

	std::vector<std::vector<int>> matrix;

	int countOFstep = 0;

	int row = 3;
	int col = 3;

	int errorFlag = 0;

	void initPlayground();

	int stepCheck(int dice);

	void gameStatusCheck();

};

std::ostream& operator<<(std::ostream& os, const GameField& gf);

GameField& operator+=(GameField& field,int dice);

struct GameController
{
	int getInt(int mod);

	void savePlaygraund(GameField* game);

	void saveTime(GameField* game);

	void init(GameField *game);

	void mainCycle(GameField* game);

};
