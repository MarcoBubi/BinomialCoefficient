#pragma once
#include <map>

using NKPair = std::pair<uint64_t, uint64_t>;
using NKPairMap = std::map<NKPair, uint64_t>;

class BinomialCoefficientCalculator
{
public:
	BinomialCoefficientCalculator() = default;
	BinomialCoefficientCalculator(const BinomialCoefficientCalculator& other) = delete;
	BinomialCoefficientCalculator(BinomialCoefficientCalculator&& other) = delete;
	~BinomialCoefficientCalculator() = default;

	BinomialCoefficientCalculator& operator=(const BinomialCoefficientCalculator& other) = delete;
	BinomialCoefficientCalculator& operator=(BinomialCoefficientCalculator&& other) = delete;

	uint64_t GetBinomialCoefficient(const uint64_t& n, const uint64_t& k);

private:
	uint64_t GetFactorialNaive(const uint64_t& value);
	uint64_t GetBinomialCoefficientNaive(const uint64_t& n, const uint64_t& k);
	uint64_t GetBinomialCoefficientRecursive(const uint64_t& n, const uint64_t& k);

	NKPairMap _NKPairs;
};
