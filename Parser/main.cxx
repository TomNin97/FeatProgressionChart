#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ios>

#include "Feats.h"
#include "UML.h"
#include "CSV.h"
#include "Duplicates.h"
#include "PrereqSort.h"

int main()
{
	std::vector<Feat> featList;
	featList.clear();
	char input;

	std::cout << "FEAT PROGRESSION CHART" << std::endl;
	while(true)
	{
		std::cout << "Enter input (i), Process output (o), Print current (p), or Exit (x):" << std::endl;
		std::cout << "-> ";
		std::cin >> input;

		if (input == 'i')
		{
			featList = csvParser(featList);

			featList = resolveDuplicates(featList);
		}

		else if (input == 'o')
		{
			featList = prereqSort(featList, true);
			featList = prereqDec(featList);
			umlOut(featList);
		}

		else if (input == 'p')
		{
			printList(featList);
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
