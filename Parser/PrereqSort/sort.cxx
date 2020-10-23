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

// std::vector<Feat> prereqSort(std::vector<Feat> featList)

// std::vector<Feat> prereqDec(std::vector<Feat>);