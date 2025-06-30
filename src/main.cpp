#include "dea_model.h"
#include "random_data.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Select mode:\n"
              << "1) Load from CSV\n"
              << "2) Generate random data\n"
              << "Choice (1 or 2): ";
    int mode; std::cin >> mode;

    std::vector<Entity> entities;
    if (mode == 1) {
        entities = loadData("data/sample_financial_data.csv");
    } else {
        int n, ni, no;
        double minV, maxV;
        std::cout << "Enter #entities, #inputs, #outputs: ";
        std::cin >> n >> ni >> no;
        std::cout << "Enter min and max value for metrics: ";
        std::cin >> minV >> maxV;

        entities = generateRandomData(n, ni, no, minV, maxV);
    }

    DEA dea;
    dea.computeEfficiency(entities);
    saveResults("results/risk_scores.csv", entities);

    std::cout << "Computed " << entities.size()
              << " efficiency scores. Results in results/risk_scores.csv\n";
    return 0;
}