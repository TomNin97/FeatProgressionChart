#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ios>

#include "Feats.h"
#include "UML.h"
#include "CSV.h"
#include "Duplicates.h"

int main()
{
	std::vector<Feat> featList;
	featList.clear();
	char input;

	std::cout << "FEAT PROGRESSION CHART" << std::endl;
	while(true)
	{
		std::cout << "Enter input (i), Process output (o), or Exit (x):" << std::endl;
		std::cout << "-> ";
		std::cin >> input;

		if (input == 'i')
		{
			featList = csvParser(featList);

			featList = resolveDuplicates(featList);

			printList(featList);
		}

		else if (input == 'o')
		{
			umlTest();
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
