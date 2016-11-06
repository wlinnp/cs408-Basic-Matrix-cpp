/*
 * SimpleDriver.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#include "SimpleDriver.h"
#include "../Matrix/Matrix.h"

SimpleDriver::SimpleDriver()
{
	Matrix left(size);
	Matrix right(size);
	setMatrixes(left, right);
	result = "left matrix\n"
			+ left.str()
			+ "right matrix\n"
			+ right.str()
			+ "Addition\n"
			+ performAddition(left, right)
			+ "Subtraction\n"
			+ performSubtraction(left, right)
			+ "Product\n"
			+ performMultiplication(left, right);
}

void SimpleDriver::setMatrixes(Matrix& left, Matrix& right)
{
	int counter = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			left.setMatrixCelll(i, j, array1[counter]);
			right.setMatrixCelll(i, j, array2[counter]);
			counter++;
		}
	}
}

std::string SimpleDriver::performAddition(Matrix& left, Matrix& right) const
{
	return (left + right).str();
}

std::string SimpleDriver::performSubtraction(Matrix& left, Matrix& right) const
{
	return (left - right).str();
}

std::string SimpleDriver::performMultiplication(Matrix& left, Matrix& right) const
{
	return (left * right).str();
}

std::string SimpleDriver::getResult()
{
	return result;
}

