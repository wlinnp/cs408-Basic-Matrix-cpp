/*
 * Utils.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#include <time.h>
#include <stdlib.h>
#include "Utils.h"

Utils::Utils() {
	srand (time(NULL));
}

Utils::~Utils() {
	// TODO Auto-generated destructor stub
}

double Utils::getNextDouble(const double lower, const double upper)
{
	double f = (double)rand() / RAND_MAX;
	return lower + f * (upper - lower);
}

