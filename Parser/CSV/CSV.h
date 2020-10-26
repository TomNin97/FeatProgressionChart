#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>
#include "Feats.h"

int alphaOrder(std::vector<Feat>, std::string);
std::vector<Feat> csvParser(std::vector<Feat>);

#endif