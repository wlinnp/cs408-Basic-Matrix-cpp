/*
 * Driver.cpp
 *
 *  Created on: Nov 11, 2016
 *      Author: william
 */

#include "Driver.h"
#include <iostream>

Driver::~Driver() {
	delete left;
	delete right;
}

