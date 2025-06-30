#include "dea_model.h"

void DEA::computeEfficiency(std::vector<Entity>& entities) {
    double maxScore = 0.0;

    for (auto& e : entities) {
        double inputSum = std::accumulate(e.inputs.begin(), e.inputs.end(), 0.0);
        double outputSum = std::accumulate(e.outputs.begin(), e.outputs.end(), 0.0);

        if (inputSum == 0.0) {
            e.efficiencyScore = 0.0;
            continue;
        }

        e.efficiencyScore = outputSum / inputSum;
        maxScore = std::max(maxScore, e.efficiencyScore);
    }

    if (maxScore > 0.0) {
        for (auto& e : entities) {
            e.efficiencyScore /= maxScore;
        }
    }
}