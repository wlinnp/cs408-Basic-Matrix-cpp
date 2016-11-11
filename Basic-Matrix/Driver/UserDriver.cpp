/*
 * UserDriver.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: william
 */

#include "UserDriver.h"
#include <iostream>

void UserDriver::start()
{
	showMainMenu();
}

void UserDriver::showMainMenu()
{
	bool repeat = true;
	while (repeat)
	{
		std::cout << "Welcome to basic Matrix Operations" << std::endl;
		std::cout << "Enter 0 to quit or other integer as matrix size" << std::endl;
		int input = 0;
		std::cin >> input;
		switch (input)
		{
		case 0:
			repeat = false;
			break;
		default:
			size = input;
			fillMatrices();
			operationMenu();
		}
	}
}
void UserDriver::fillMatrices()
{
	if (size < 1)
	{
		throw "Invalid matrix size";
	}
	left = new Matrix(size);
	right = new Matrix(size);
	std::cout << "For first matrix" << std::endl;
	fillSingleMatrix(left);
	std::cout << "For second matrix" << std::endl;
	fillSingleMatrix(right);

}
void UserDriver::fillSingleMatrix(Matrix* matrix)
{
	int matrixSize = size * size;
	while (matrixSize > 0)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				std::cout << "Enter value for cell [" << i << "][" << j << "]: ";
				double input = -1;
				std::cin >> input;
				matrix->setMatrixCell(i, j, input);
				matrixSize--;
			}
		}
	}
}
void UserDriver::operationMenu()
{
	bool repeat = true;
	while (repeat)
	{
		std::cout << "Enter 1 to add those 2 matrices" << std::endl;
		std::cout << "Enter 2 to subtract those 2 matrices" << std::endl;
		std::cout << "Enter 3 to multiply those 2 matrices" << std::endl;
		std::cout << "Enter 0 to go back to main menu" << std::endl;
		int input = -1;
		std::cin >> input;
		switch (input)
		{
		case 0:
			repeat = false;
			break;
		case 1:
			std::cout << (*left + *right).str() << std::endl;
			break;
		case 2:
			std::cout << (*left - *right).str() << std::endl;
			break;
		case 3:
			std::cout << (*left * *right).str() << std::endl;
			break;
		default:
			std::cout << "invalid choice" << std::endl;
			break;
		}
	}
}

