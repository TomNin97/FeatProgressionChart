#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <ios>

#include "Feats.h"

std::vector<Feat> csvParser(std::vector<Feat> featList)
{
	std::string fileName;
	Feat inputFeat;
	std::fstream scribe;
	std::string line;

	/* Input file name */
	std::cout << "\n\nPlease enter the file name. Extension is added by default:\n-> ";
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, fileName);
	fileName = "Input/" + fileName + ".csv";

	/* Parse file name */
	std::cout << "attempting to open " << fileName << std::endl;
	scribe.open(fileName, std::ios::in);
	if(!scribe.is_open())
	{
		std::cout << "\nERROR IN OPENING THE FILE" << std::endl;
		return featList;
	}

	while(std::getline(scribe, line))
	{
		std::cout << line << std::endl;
	}
	scribe.close();

	std::cout << "\nYou have selected the file: " << fileName << std::endl;

	return featList;
}