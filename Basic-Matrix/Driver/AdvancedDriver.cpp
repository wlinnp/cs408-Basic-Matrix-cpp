/*
 * AdvancedDriver.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#include "AdvancedDriver.h"

#include <string>
#include <functional>
#include "../Matrix/Matrix.h"
#include "Utils.h"

AdvancedDriver::AdvancedDriver()
{
	Utils util;
	result << std::fixed << "Performance Test\n";
	for (int i = START; i < END; i += 100)
	{
		result << "for size: " << i << "\n";
		Matrix left(i);
		Matrix right(i);
		setMatrixes(left, right, i, util);
		result << "Addition: " << performAddition<std::plus<Matrix>>(left, right) << "\n";
		result << "Subtraction: " << performAddition<std::minus<Matrix>>(left, right) << "\n";
		result << "Product: " << performAddition<std::multiplies<Matrix>>(left, right) << "\n";
	}
}

std::string AdvancedDriver::getResult()
{
	return result.str();
}

void AdvancedDriver::setMatrixes(Matrix& left, Matrix& right, const int size, Utils& utils)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			left.setMatrixCelll(i, j, utils.getNextDouble(LOWER_BOUND, UPPER_BOUND));
			right.setMatrixCelll(i, j, utils.getNextDouble(LOWER_BOUND, UPPER_BOUND));
		}
	}
}

template<typename Op>
double AdvancedDriver::performAddition(Matrix& left, Matrix& right) const
{
	Op operate;
	clock_t start = clock();
	operate(left, right);
	return (clock() - start) / (CLOCKS_PER_SEC/1000000000.0);
}


