/*
 * SimpleDriver.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#include "SimpleDriver.h"
#include "../Matrix/Matrix.h"
#include "Utils.h"

SimpleDriver::SimpleDriver()
{
	Utils utils;
	size = 5;
	left = new Matrix(size);
	right = new Matrix(size);
	setMatrixes();
	result << "left matrix" << utils.NEXT_LINE << left->str();
	result << "right matrix" << utils.NEXT_LINE << right->str();
	result << "Addition" << utils.NEXT_LINE << performAddition();
	result << "Subtraction" << utils.NEXT_LINE << performSubtraction();
	result << "Product" << utils.NEXT_LINE << performMultiplication();
}

void SimpleDriver::setMatrixes()
{
	int counter = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			left->setMatrixCell(i, j, array1[counter]);
			right->setMatrixCell(i, j, array2[counter]);
			counter++;
		}
	}
}

std::string SimpleDriver::performAddition() const
{
	return (*left + *right).str();
}

std::string SimpleDriver::performSubtraction() const
{
	return (*left - *right).str();
}

std::string SimpleDriver::performMultiplication() const
{
	return (*left * *right).str();
}

std::string SimpleDriver::getResult()
{
	return result.str();
}


