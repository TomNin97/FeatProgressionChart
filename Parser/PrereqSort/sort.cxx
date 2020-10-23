#include <iostream>
#include <vector>
#include <string>

#include "Feats.h"
#include "PrereqSort.h"

int locateFeat(std::vector<Feat> featList, std::string featName)
{
	int cmp = featList[featList.size()/2].name.compare(featName);
	int response;

	if(cmp == 0)
	{
		return featList.size()/2;
	}
	else if(cmp > 0)
	{
		if(featList.size()/2 == 0)
		{
			return -1; // it does not exist in list
		}
		else
		{
			// copy vector for recursive code
			std::vector<Feat> subList;
			for (int i = 0; i < featList.size()/2; i++)
			{
				subList.push_back(featList[i]);
			}

			response = locateFeat(subList, featName);
			if (response == -1)
			{
				return -1;
			}
			else
			{
				return response;
			}
		}
	}
	else
	{
		if(featList.size()/2 == 0)
		{
			return -1;
		}
		else
		{
			std::vector<Feat> subList;
			for (int i = (featList.size()/2); i < featList.size(); i++)
			{
				subList.push_back(featList[i]);
			}

			response = locateFeat(subList, featName);
			if (response == -1)
			{
				return -1;
			}
			else
			{
				return response + (featList.size()/2);
			}
		}
	}
}

std::vector<Feat> prereqSort(std::vector<Feat> featList)
{
	int location;
	std::string wholeFeatName;
	std::string name;
	bool shouldDelete;
	int j;

	for (int i=0; i < featList.size(); i++)
	{
		std::cout << "\nStarting on feat: " << featList[i].name << std::endl;
		if (!featList[i].genPrereq.empty()) // only if contents exist
		{
			for (j=0; j < featList[i].genPrereq.size(); j++)
			{
				wholeFeatName = featList[i].genPrereq[j];

				if(wholeFeatName.find("(") != std::string::npos) // if parenthesis exist
				{
					name = wholeFeatName.substr(0, wholeFeatName.find("(")-1); // copies all except for the space and parenthesis object
					shouldDelete = false; // dont delete prerequisite from original vector as it contains extra info
				}
				else
				{
					name = wholeFeatName; // copies whole string
					shouldDelete = true; // delete from original vector if it is a recognized feat.
				}

				location = locateFeat(featList, name);

				if(location >= 0) // location exists. else move to next genPrerequisite
				{
					featList[i].featPrereq.push_back(featList[i].genPrereq[j]); // Adds to new location
					if(shouldDelete){featList[i].genPrereq.erase(featList[i].genPrereq.begin() + j);} // erases old location
				}
			}
		}
	}
	return featList;
}

// std::vector<Feat> prereqDec(std::vector<Feat>);