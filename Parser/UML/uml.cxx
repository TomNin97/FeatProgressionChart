#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Feats.h"

void umlOut(std::vector<Feat> featList)
{
	std::fstream scribe;
	int i; // iterate feats
	int j; // iterate feats' vectors

	scribe.open("Output/uml.txt", std::ios::out);
	if(!scribe)
	{
		std::cout << "\nFailure to write text document." << std::endl;
		return;
	}

	scribe.clear();
	scribe << "@startuml\n\ntitle Feat Progression Chart\n\n\nskinparam componentStyle uml2"; // Head of file

	for(i=0; i < featList.size(); i++) // iterates through feats
	{
		scribe << "\nclass \"" << featList[i].name << "\" {\n"; // gives feat name
	}

	scribe << "\n@enduml"; // End of file
	scribe.close();

	std::cout << "\nOutput finished." << std::endl;
}
