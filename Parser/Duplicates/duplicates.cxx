#include <iostream>
#include <string>
#include <vector>

#include "Duplicates.h"
#include "Feats.h"

std::vector<Feat> resolveDuplicates(std::vector<Feat> featList)
{
	int cursor = 0;

	while(cursor < featList.size())
	{
		if(featList[cursor].name.compare(featList[cursor+1].name) == 0)
		{
			std::cout << "\nDUPLICATES SPOTTED. CHOOSE WHICH DESCRIPTION (1/2) TO USE:\n" << std::endl;
			printFeat(featList[cursor]);
			printFeat(featList[cursor+1]);

			cursor++;
		}
		else {cursor++;}
	}
}