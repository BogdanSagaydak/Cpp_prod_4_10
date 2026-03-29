#include <vector>
#include <iostream>
#include "structs.h"


int main()
{
	GameField game;
	GameController controller;

	controller.init(&game);

	//game += 2;
	//std::cout << game;

	return 0;
};

