#include "menu.h"
#include "game_log.h"
#include "drower.h"
#include "reader.h"

#include <iostream>

void gameField()
{
	std::cout << "\ngameField ++";

	replacement();

	//drow_menu(0);
	drow_playground();
};

void replacement()
{
	std::cout << "\nreplacement ++";

	read();
};