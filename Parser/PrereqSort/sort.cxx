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

bool featChain(std::vector<Feat> featList, int featOrigin, std::string featPrereq)
{
	int i;
	int loc;

	if(featList[featOrigin].featPrereq.empty())
	{
		std::cout << "--- This feat (" << featList[featOrigin].name << ") empty, YEET!" << std::endl;
		return false;
	}

	for(i=0; i < featList[featOrigin].featPrereq.size(); i++)
	{
		if(featList[featOrigin].featPrereq[i].compare(featPrereq) == 0) // discovered prerequisite in current feat
		{
			std::cout << "--- The prerequisite (" << featPrereq << ") was found in " << featList[featOrigin].name << std::endl;
			return true;
		}
		loc = locateFeat(featList, featList[featOrigin].featPrereq[i]);

		if(featChain(featList, loc, featPrereq)) // discovered prerequisite in prerequisite feat
		{
			std::cout << "--- ^The prerequisite was (" << featPrereq << ") was found down the chain." << std::endl;
			return true;
		}
	}

	std::cout << "Lots of searching with nothing of note." << std::endl;
	return false; // thoroughly searched with no result
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
	return featList;
}

std::vector<Feat> prereqDec(std::vector<Feat> featList)
{
	std::cout << "\nWe then decimate redundant feats!" << std::endl;
	int i; // iterate through the list of feats
	int j; // iterate through preRequisites' prerequisites to compare
	int k; // iterate what prerequisites are compared
	int prereqX;

	for(i=0; i < featList.size(); i++)
	{
		std::cout << "\nStarting on feat: " << featList[i].name << std::endl;

		if(featList[i].featPrereq.size() > 1) // useless to go through with only 1 feat
		{
			for (j=0; j < featList[i].featPrereq.size(); j++)
			{
				std::cout << "Looking into prerequisite: " << featList[i].featPrereq[j] << std::endl;
				for (k=0; k < featList[i].featPrereq.size(); k++)
				{
					if(k != j)
					{
						std::cout << "Comparing: " << featList[i].featPrereq[k] << std::endl;
						if(featChain(featList, locateFeat(featList, featList[i].featPrereq[j]), featList[i].featPrereq[k])) // if k (as a prerequisite) is identified down the chain
						{
							std::cout << "Duplicate feat found! Removing from top-level prerequisites!" << std::endl;
							featList[i].featPrereq.erase(featList[i].featPrereq.begin()+k); // removes that prerequisite
						}
					}
				}
			}
		}
		else
		{
			std::cout << "Not enough feats!" << std::endl;
		}
	}

	return featList;
}