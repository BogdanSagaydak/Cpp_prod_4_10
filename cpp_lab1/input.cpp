#include "input.h"

int getInt(int mod) {
	std::string input;
	int value;
	while (true) {
		try {
			if (mod == 0) 
			{
				std::cout << "Enter gamefield size: ";
			}
			else
			{
				std::cout << "Enter num of dice: ";
			}
			std::cin >> input;
			size_t pos;
			value = std::stoi(input, &pos);
			if (pos != input.length()) {
				if (mod == 0) {
					std::cout << "\nIncorrect Argument!";
					continue;
				}
				else
				{
					return -1;
				}
			}
			if (mod == 0) 
			{
				if (value < 2)
				{
					std::cout << "\nSize should be 2 or bigger! Enter correct size: ";
					continue;
				}
			}
			else
			{
				if (value < 1) {
					return -1;
				}
			}

			while (std::isspace(std::cin.peek()) &&
				std::cin.peek() != '\n') {
				std::cin.ignore();
			}
			if (std::cin.peek() != '\n') {
				std::cout << "Entered extra arguments! Will be used only first one(" << value << ")." << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			return value;

		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (mod == 0) {
				std::cout << "Incorrect Argument!";
			}
			else
			{
				return -1;
			}
		}
	}
}

