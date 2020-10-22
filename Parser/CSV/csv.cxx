#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <ios>
#include <cstdio>

#include "Feats.h"

std::vector<Feat> csvParser(std::vector<Feat> featList)
{
	std::string fileName;
	Feat inputFeat;
	std::fstream scribe;
	std::string line;
	std::string readChar;
	int cursor;
	bool inQuotes;

	/* Input file name */
	std::cout << "\n\nPlease enter the file name. Extension is added by default:\n-> ";
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, fileName);
	inputFeat.type = fileName; // Get the filename as feat type before we Frankenstein fileName
	fileName = "Input/" + fileName + ".csv";

	/* Parse file name */
	std::cout << "attempting to open " << fileName << std::endl;
	scribe.open(fileName, std::ios::in);
	if(!scribe.is_open())
	{
		std::cout << "\nERROR IN OPENING THE FILE" << std::endl;
		return featList;
	}
	std::getline(scribe, line); // skip the header line

	while(std::getline(scribe, line))
	{
		/* Read line into Feat struct */
		cursor = 0;
		inQuotes = false;
		readChar.clear();
		inputFeat.genPrereq.clear();
		inputFeat.special.clear();
		inputFeat.sources.clear();

		// Name
		while(line[cursor] != ',')
		{
			readChar += line[cursor];
			cursor++;
		}
		inputFeat.name = readChar;
		readChar.clear();
		cursor++;

		// Prerequisites
		if(line[cursor] == '-'){cursor += 2;} // No prerequisites: skip nexxt loop
		else
		{
			while(line[cursor] != ',' || inQuotes)
			{
				if(line[cursor] == '"'){inQuotes = !inQuotes;} // Flags within quotes (implying commas separate multiple prerequisites)
				else if(line[cursor] == ',') // ends one prerequisite
				{
					inputFeat.genPrereq.push_back(readChar); // adds prerequisite
					readChar.clear(); // Resets reader
					cursor++; // Skips space after comma
				}
				else{readChar += line[cursor];}
				cursor++;
			}
			inputFeat.genPrereq.push_back(readChar); // Last prerequisite
			readChar.clear();
			cursor++;
		}

		// Benefits
		if(line[cursor] == ','){cursor++;} // Skips if no recorded benefits
		else
		{
			while(line[cursor] != ',' || inQuotes)
			{
				if(line[cursor] == '"'){inQuotes = !inQuotes;}
				else
				{
					readChar += line[cursor];
				}
				cursor++;
			}
			inputFeat.benefits = readChar;
			readChar.clear();
			cursor++;
		}
		std::cout << "\nNext feat started" << std::endl;

		// Special
		if(line[cursor] == ','){cursor++;} // Skips if no recorded special notes
		else
		{
			while(line[cursor] != ',' || inQuotes)
			{
				if(line[cursor] == '"'){inQuotes = !inQuotes;}
				else if(line[cursor] == ',')
				{
					inputFeat.special.push_back(readChar); // adds special note
					readChar.clear(); // resets reader
					cursor++; // skips space
				}
				else{readChar += line[cursor];}
				cursor++;
			}
			inputFeat.special.push_back(readChar);
			readChar.clear();
			cursor++;
		}

		// Source Book
		while(line[cursor] != ',')
		{
			readChar += line[cursor];
			cursor++;
		}
		inputFeat.sources.push_back(readChar);
		readChar.clear();
		cursor++;

		printFeat(inputFeat);

		/* Locate position in vector */
	}

	std::cout << "\nClosing File" << std::endl;
	scribe.close();

	std::cout << "\nYou have selected the file: " << fileName << "\nEnter to Continue" << std::endl;

	return featList;
}