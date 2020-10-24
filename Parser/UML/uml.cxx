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
		scribe << "  .. " << featList[i].type << " ..\n"; // gives feat type

		scribe << "\n  .. " << "Prerequisites" << " ..\n"; // headlines feat prerequisites
		for(j=0; j<featList[i].genPrereq.size(); j++)
		{
			scribe << "-" << featList[i].genPrereq[j] << "\n";
		}

		scribe << "\n  .. " << "Benefits" << " ..\n"; // headlines feat Benefits
		scribe << "+" << featList[i].benefits << "\n";

		scribe << "\n  .. " << "Special" << " ..\n"; // headlines feat Specials
		for(j=0; j<featList[i].special.size(); j++)
		{
			scribe << "#" << featList[i].special[j] << "\n";
		}

		scribe << "\n  .. " << "Source Books" << " ..\n"; // headlines source books
		for(j=0; j<featList[i].sources.size(); j++)
		{
			scribe << "~" << featList[i].sources[j] << "\n";
		}

		scribe << "}\n"; // closes out class

		/* Class Relations */
		for(j=0; j<featList[i].featPrereq.size(); j++)
		{
			scribe << "\"" << featList[i].name << "\" --> \"" << featList[i].featPrereq[j] << "\"\n";
		}
	}

	scribe << "\n@enduml"; // End of file
	scribe.close();

	std::cout << "\nOutput finished." << std::endl;
}
