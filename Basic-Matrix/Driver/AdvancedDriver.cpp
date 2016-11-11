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
	result << std::fixed << "Performance Test" <<  util.NEXT_LINE;
	for (int i = START; i < END; i += 100)
	{
		result << "for size: " << i << util.NEXT_LINE;
		left = new Matrix(i);
		right = new Matrix(i);
		setMatrixes(i, util);
		result << "Addition: " << performOperation<std::plus<Matrix>>() << util.NEXT_LINE;
		result << "Subtraction: " << performOperation<std::minus<Matrix>>() << util.NEXT_LINE;
		result << "Product: " << performOperation<std::multiplies<Matrix>>() << util.NEXT_LINE;
	}
}

std::string AdvancedDriver::getResult()
{
	return result.str();
}

void AdvancedDriver::setMatrixes(const int size, Utils& utils)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			left->setMatrixCell(i, j, utils.getNextDouble(LOWER_BOUND, UPPER_BOUND));
			right->setMatrixCell(i, j, utils.getNextDouble(LOWER_BOUND, UPPER_BOUND));
		}
	}
}

template<typename Op>
double AdvancedDriver::performOperation() const
{
	Op operate;
	clock_t start = clock();
	operate(*left, *right);
	return (clock() - start) / (CLOCKS_PER_SEC/1000000000.0);
}


