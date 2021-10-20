#include "BinomialCoefficientCalculator.h"
#include <chrono>
#include <iostream>

int main()
{
    BinomialCoefficientCalculator calculator;
    uint64_t n = 35, k = 14;

    auto startTimer = std::chrono::high_resolution_clock::now();
    uint64_t result = calculator.GetBinomialCoefficient(n, k);
    auto endTimer = std::chrono::high_resolution_clock::now();
    auto executionTime = std::chrono::duration_cast<std::chrono::seconds>(endTimer - startTimer);
    std::cout << "Operation took " << executionTime.count() << " ms." << std::endl;
    std::cout << result << std::endl;

    startTimer = std::chrono::high_resolution_clock::now();
    uint64_t result2 = calculator.GetBinomialCoefficient(n, k); // test if it already exists
    endTimer = std::chrono::high_resolution_clock::now();
    std::cout << result2 << std::endl;

    executionTime = std::chrono::duration_cast<std::chrono::seconds>(endTimer - startTimer);
    std::cout << "Operation took " << executionTime.count() << " ms." << std::endl;

    return 0;
}
