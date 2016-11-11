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
#include "Driver/UserDriver.h"
#include "Driver/Utils.h"
int main()
{
	Utils utils;
	std::cout << "wanna see the basic and performance test? 0 for No, others for Yes" << std::endl;
	int input = 0;
	std::cin >> input;
	if (input != 0)
	{
		SimpleDriver* test = new SimpleDriver;
		std::cout << test->getResult() << std::endl;
		delete test;
		AdvancedDriver* advTest = new AdvancedDriver;
		std::cout << advTest->getResult() << std::endl;
		delete advTest;
	}
	UserDriver* user =  new UserDriver;
	user->start();
	delete user;
	return 0;
}




