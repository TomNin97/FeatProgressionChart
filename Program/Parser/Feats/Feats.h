#include <string>
#include <vector>

/* The standard structure for Feats the vector would hold */
struct Feat
	{
		std::string name;  // Feat Name
		std::string type;  // Feat types
		std::vector<std::string> genPrereq;  // Prerequisites for Feat to be mentioned in UML
		std::vector<std::string> featPrereq;  // List of Prerequisites which are also other Feats
		std::string benefits;  // Description of benefits
		std::vector<std::string> special;  // Special notes on feats
		std::vector<std::string> sources;  // Source Books
	};
