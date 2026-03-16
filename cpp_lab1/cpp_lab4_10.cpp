#include <vector>
#include <iostream>
#include "structs.h"


int main()
{
	GameField game;
	game.initPlayground();
	game.drowPlayground();

	std::cout << std::endl;

	game.step(2);

	game.drowPlayground();

	std::cout << std::endl;

	game.step(1);

	game.drowPlayground();

	std::cout << std::endl;

	game.step(3);

	game.drowPlayground();

	std::cout << std::endl;

	game.step(1);

	game.drowPlayground();

	std::cout << std::endl;

	game.step(2);

	game.drowPlayground();

	return 0;
};

