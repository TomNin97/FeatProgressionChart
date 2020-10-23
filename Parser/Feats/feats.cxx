#include <iostream>
#include <vector>
#include <string>

#include "Feats.h"

void printFeat(Feat output)
{
	std::cout << "\nFeat Name: " << output.name << std::endl;
	std::cout << "Feat Type: " << output.type << std::endl;

	std::cout << "Feat Prerequisites: (";
	for(int i=0; i < output.genPrereq.size(); i++){std::cout << output.genPrereq[i] << ", ";}
	std::cout << ')' << std::endl;

	std::cout << "Feat Benefits: " << output.benefits << std::endl;

	std::cout << "Feat Specials: (";
	for(int i=0; i < output.special.size(); i++){std::cout << output.special[i] << ", ";}
	std::cout << ')' << std::endl;

	std::cout << "Feat Book: (";
	for(int i=0; i < output.sources.size(); i++){std::cout << output.sources[i] << ", ";}
	std::cout << ')' << std::endl;
}

void printList(std::vector<Feat> featList)
{
	std::cout << "\nCURRENT LIST:" << std::endl;
	for (int i = 0; i < featList.size(); i++)
	{
		printFeat(featList[i]);
	}
	std::cout << "DONE! Press Enter to Continue" << std::endl;
}