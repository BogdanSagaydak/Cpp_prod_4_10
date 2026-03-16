#include <vector>
#include "menu.h"
#include <iostream>

struct status
{
	int screenStatus = 0;
	int menuStatus = 0;
	int playgroundSize = 4;

	std::vector<std::vector<int>> matrix;

	int countOFstep = 0;

	struct zeroPointStatus
	{
		int row = 3;
		int col = 3;
	};

	void initPlayground(int n)
	{

	};

	int stepCheck()
	{
	
	};

	void gameStatusCheck()
	{
	
	};

	void drowPlayground()
	{
	
	};

};

int main()
{
	status gameStatus;
	std::cout << "\nmain ++";
	mainMenu();

	std::cout << "\nFinished succsesfull!";
	return 0;
};

