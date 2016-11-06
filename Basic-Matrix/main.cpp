/*
 * main.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */
#include <iostream>
#include "./Matrix/Matrix.h"
#include "Driver/SimpleDriver.h"
#include "Driver/AdvancedDriver.h"
int main()
{
	SimpleDriver test;
	std::cout << test.getResult() << std::endl;
	AdvancedDriver advTest;
	std::cout << advTest.getResult();
	return 0;
}




