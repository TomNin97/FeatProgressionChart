#include <iostream>
#include <string>
#include <vector>

#include "Duplicates.h"
#include "Feats.h"

std::vector<Feat> resolveDuplicates(std::vector<Feat> featList)
{
	int cursor = 0;
	std::string decision;

	while(cursor < featList.size())
	{
		if(featList[cursor].name.compare(featList[cursor+1].name) == 0)
		{
			while(true)
			{
				std::cout << "\nDUPLICATES SPOTTED. CHOOSE WHICH DESCRIPTION (1/2) TO USE:\n" << std::endl;
				printFeat(featList[cursor]);
				std::cout << "(1)" << std::endl;
				printFeat(featList[cursor+1]);
				std::cout << "(2)\n-> "; 
				std::cin >> decision;

				if(decision == "1")
				{
					for(int i = 0; i < featList[cursor+1].sources.size(); i++) // moves all sources from copy feat to chosen feat
					{
						featList[cursor].sources.push_back(featList[cursor+1].sources[i]);
					}
					featList.erase(featList.begin() + cursor + 1); // erases copy feat

					break;
				}
				else if(decision == "2")
				{
					for(int i = 0; i < featList[cursor].sources.size(); i++) // moves all sources
					{
						featList[cursor+1].sources.push_back(featList[cursor].sources[i]);
					}
					featList.erase(featList.begin() + cursor); // erases copy feat

					break;
				}
			}
		}
		else {cursor++;}
	}

	return featList;
}