#include "pch.h"
#include "BinomialCoefficientCalculator.h"
#include <chrono>
#include <iostream>

TEST(BinomialCoefficientCalculation, CorrectCalculation)
{
	BinomialCoefficientCalculator calculator;
	uint64_t n = 10;
	uint64_t k = 5;

	// C(10,5) = 252
	EXPECT_EQ(calculator.GetBinomialCoefficient(n, k), 252);
}

TEST(BinomialCoefficientCalculation, NSmallerThanK)
{
	BinomialCoefficientCalculator calculator;
	uint64_t n = 1;
	uint64_t k = 5;

	// C(1,5) = 0
	EXPECT_EQ(calculator.GetBinomialCoefficient(n, k), 0);
}

TEST(BinomialCoefficientCalculation, NEqualToK)
{
	BinomialCoefficientCalculator calculator;
	uint64_t n = 5;
	uint64_t k = 5;

	// C(5,5) = 1
	EXPECT_EQ(calculator.GetBinomialCoefficient(n, k), 1);
}

TEST(BinomialCoefficientCalculation, KEqualToZero)
{
	BinomialCoefficientCalculator calculator;
	uint64_t n = 10;
	uint64_t k = 0;

	// C(10, 0) = 1
	EXPECT_EQ(calculator.GetBinomialCoefficient(n, k), 1);
}

TEST(BinomialCoefficientCalculationEffectiveness, MapLookupTest)
{
	BinomialCoefficientCalculator calculator;
	uint64_t n = 30;
	uint64_t k = 14;

	// create result
	auto startTimer = std::chrono::high_resolution_clock::now();
	uint64_t result = calculator.GetBinomialCoefficient(n, k);
	auto endTimer = std::chrono::high_resolution_clock::now();
	auto executionTime1 = std::chrono::duration_cast<std::chrono::seconds>(endTimer - startTimer);

	// get value from map
	startTimer = std::chrono::high_resolution_clock::now();
	uint64_t result2 = calculator.GetBinomialCoefficient(n, k); // test if it already exists
	endTimer = std::chrono::high_resolution_clock::now();

	auto executionTime2 = std::chrono::duration_cast<std::chrono::seconds>(endTimer - startTimer);

	EXPECT_GE(executionTime1, executionTime2);
	EXPECT_EQ(result, result2);
}
