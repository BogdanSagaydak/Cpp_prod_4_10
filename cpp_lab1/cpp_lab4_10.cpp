#include <vector>
#include <iostream>
#include "structs.h"


int main()
{
	GameField game;
	GameController controller;

	controller.init(&game);

	return 0;
};

