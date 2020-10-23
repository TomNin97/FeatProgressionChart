#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <ios>
#include <cstdio>

#include "Feats.h"

int alphaOrder(std::vector<Feat> featList, std::string featName)
{
	int cmp = featList[featList.size()/2].name.compare(featName);
	if(cmp == 0)
	{
		return featList.size()/2;
	}
	else if(cmp > 0)
	{
		if(featList.size()/2 == 0)
		{
			return 0;
		}
		else
		{
			// copy vector for recursive code
			std::vector<Feat> subList;
			for (int i = 0; i < featList.size()/2; i++)
			{
				subList.push_back(featList[i]);
			}

			return alphaOrder(subList, featName);
		}
	}
	else
	{
		if(featList.size()/2 == 0)
		{
			return 1;
		}
		else
		{
			std::vector<Feat> subList;
			for (int i = (featList.size()/2); i < featList.size(); i++)
			{
				subList.push_back(featList[i]);
			}

			return alphaOrder(subList, featName) + (featList.size()/2);
		}
	}
}

std::vector<Feat> csvParser(std::vector<Feat> featList)
{
	std::string fileName;
	Feat inputFeat;
	std::fstream scribe;
	std::string line;
	std::string readChar;
	int cursor;
	bool inQuotes;
	int placing;

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
		while(line[cursor] != ',' || inQuotes)
		{
			if(line[cursor] == '"'){inQuotes = !inQuotes;}
			else
			{
				readChar += line[cursor];
			}
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

		/* Locate position in vector */
		if(featList.empty())
		{
			featList.push_back(inputFeat);
		}
		else
		{
			placing = alphaOrder(featList, inputFeat.name);

			if(placing == featList.size())
			{
				featList.push_back(inputFeat);
			}
			else
			{
				featList.insert(featList.begin() + placing, inputFeat);
			}
		}
	}

	std::cout << "\nClosing File" << std::endl;
	scribe.close();

	std::cout << "\nYou have selected the file: " << fileName << "\nEnter to Continue" << std::endl;

	return featList;
}

