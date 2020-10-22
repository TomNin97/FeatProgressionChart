#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ios>

#include "Feats.h"

int main()
{
	std::vector<Feat> featList;
	char input;

	std::cout << "FEAT PROGRESSION CHART" << std::endl;
	while(true)
	{
		std::cout << "Enter input (i), Process output (o), or Exit (x):" << std::endl;
		std::cout << "-> ";
		std::cin >> input;

		if (input == 'i')
		{
			std::cout << "\nYou've selected input!" << std::endl;
		}

		else if (input == 'o')
		{
			std::cout << "\nYou've selected output!" << std::endl;
		}
		
		else if (input == 'x')
		{
			break;
		}

		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return 0;
}
