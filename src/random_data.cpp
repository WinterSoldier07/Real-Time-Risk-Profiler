#include "random_data.h"
#include <random>
#include <sstream>

std::vector<Entity> generateRandomData(int n,
                                       int numInputs,
                                       int numOutputs,
                                       double minVal,
                                       double maxVal) {
    std::vector<Entity> entities;
    entities.reserve(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(minVal, maxVal);

    for (int i = 0; i < n; ++i) {
        Entity e;
        std::ostringstream name;
        name << "Bank_" << (i + 1);
        e.name = name.str();

        for (int j = 0; j < numInputs; ++j)
            e.inputs.push_back(dist(gen));

        for (int j = 0; j < numOutputs; ++j)
            e.outputs.push_back(dist(gen));

        entities.push_back(std::move(e));
    }

    return entities;
}