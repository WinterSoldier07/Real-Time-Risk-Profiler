#pragma once
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

struct Entity {
    std::string name;
    std::vector<double> inputs;
    std::vector<double> outputs;
    double efficiencyScore = 0.0;
};

class DEA {
public:
    void computeEfficiency(std::vector<Entity>& entities);
};

std::vector<Entity> loadData(const std::string& filename);
void saveResults(const std::string& filename, const std::vector<Entity>& entities);