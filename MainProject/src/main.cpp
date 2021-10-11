#include <chrono>
#include <iostream>
#include <map>

/*
        n           n !
    (		) = -------------  or C(n,k) = ...
        k        k! * (n-k)!

*/

using NKPair = std::pair<uint64_t, uint64_t>;
using NKPairMap = std::map<NKPair, uint64_t>;

NKPairMap NKPairs;

uint64_t FactorialNaive(const uint64_t value)
{
    uint64_t result = 1;
    for (int i = 2; i <= value; ++i)
    {
        result *= i;
    }
    return result;
}

uint64_t BinomialCoefficientNaive(const uint64_t& n, const uint64_t& k)
{
    /*
        Not working well because of big numbers
    */
    if (k > n)
    {
        return 0;
    }

    if (n == k || k == 0)
    {
        return 1;
    }

    uint64_t nFact = FactorialNaive(n);
    uint64_t kFact = FactorialNaive(k);
    uint64_t nkFact = FactorialNaive(n - k);

    return nFact / (kFact * nkFact);
}

uint64_t BinomialCoefficientRecursive(const uint64_t n, const uint64_t k)
{
    if (k > n)
    {
        return 0;
    }

    if (n == k || k == 0)
    {
        return 1;
    }

    return BinomialCoefficientRecursive(n - 1, k - 1) + BinomialCoefficientRecursive(n - 1, k);
}

uint64_t GetBinomialCoefficient(const uint64_t n, const uint64_t k)
{
    NKPair nkPair = std::make_pair(n, k);
    if (NKPairs.count(nkPair))
    {
        return NKPairs.at(nkPair);
    }

    uint64_t result = BinomialCoefficientRecursive(n, k);
    NKPairs[nkPair] = result;
    return result;
}

int main()
{
    uint64_t n = 31, k = 14;
    auto startTimer = std::chrono::high_resolution_clock::now();
    GetBinomialCoefficient(n, k);
    auto endTimer = std::chrono::high_resolution_clock::now();
    auto executionTime = std::chrono::duration_cast<std::chrono::seconds>(endTimer - startTimer);
    std::cout << "Operation took " << executionTime.count() << " ms." << std::endl;

    startTimer = std::chrono::high_resolution_clock::now();
    GetBinomialCoefficient(n, k); // test if it already exists
    endTimer = std::chrono::high_resolution_clock::now();

    executionTime = std::chrono::duration_cast<std::chrono::seconds>(endTimer - startTimer);
    std::cout << "Operation took " << executionTime.count() << " ms." << std::endl;

    return 0;
}
