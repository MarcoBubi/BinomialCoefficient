#include "pch.h"
#include "BinomialCoefficientCalculator.h"

uint64_t BinomialCoefficientCalculator::GetBinomialCoefficient(const uint64_t& n, const uint64_t& k)
{
	NKPair nkPair = std::make_pair(n, k);
	if (_NKPairs.count(nkPair))
	{
		return _NKPairs.at(nkPair);
	}

	uint64_t result = GetBinomialCoefficientRecursive(n, k);
	_NKPairs[nkPair] = result;

	return result;
}

uint64_t BinomialCoefficientCalculator::GetFactorialNaive(const uint64_t& value)
{
	uint64_t result = 1;
	for (uint64_t i = 2; i <= value; ++i)
	{
		result *= i;
	}
	return result;
}

uint64_t BinomialCoefficientCalculator::GetBinomialCoefficientNaive(const uint64_t& n, const uint64_t& k)
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

    uint64_t nFact = GetFactorialNaive(n);
    uint64_t kFact = GetFactorialNaive(k);
    uint64_t nkFact = GetFactorialNaive(n - k);

    return nFact / (kFact * nkFact);
}

uint64_t BinomialCoefficientCalculator::GetBinomialCoefficientRecursive(const uint64_t& n, const uint64_t& k)
{
	if (k > n)
	{
		return 0;
	}

	if (n == k || k == 0)
	{
		return 1;
	}

	return GetBinomialCoefficientRecursive(n - 1, k - 1) + GetBinomialCoefficientRecursive(n - 1, k);
}
