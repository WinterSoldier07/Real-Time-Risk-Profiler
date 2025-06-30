#include "dea_model.h"
#include <fstream>
#include <sstream>

std::vector<Entity> loadData(const std::string& filename) {
    std::vector<Entity> entities;
    entities.reserve(10000);

    std::ifstream file(filename);
    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Entity e;
        std::string token;

        std::getline(ss, e.name, ',');

        int col = 0;
        while (std::getline(ss, token, ',')) {
            try {
                double val = std::stod(token);
                if (col < 2)
                    e.inputs.push_back(val);
                else
                    e.outputs.push_back(val);
                col++;
            } catch (...) {
                e.inputs.push_back(0.0);
            }
        }

        entities.push_back(e);
    }

    return entities;
}