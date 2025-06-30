#ifndef RANDOM_DATA_H
#define RANDOM_DATA_H

#include "dea_model.h"
#include <vector>

std::vector<Entity> generateRandomData(int n,
                                       int numInputs,
                                       int numOutputs,
                                       double minVal,
                                       double maxVal);

#endif