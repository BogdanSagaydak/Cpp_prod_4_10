#include "menu.h"
#include "game_log.h"
#include "drower.h"
#include "reader.h"

#include <iostream>

void mainMenu()
{
	std::cout << "\nmainMenu ++";

	drow_menu(0);

	gameField();

};
