#include <vector>
#include <string>
#include "Feats.h"

int locateFeat(std::vector<Feat>, std::string, bool feed=false);
bool featChain(std::vector<Feat>, int, std::string, bool feed=false);
std::vector<Feat> prereqSort(std::vector<Feat>, bool feed=false);
std::vector<Feat> prereqDec(std::vector<Feat>, bool feed=false);