/*
 * SimpleDriver.h
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#ifndef DRIVER_SIMPLEDRIVER_H_
#define DRIVER_SIMPLEDRIVER_H_

#include <string>
#include <sstream>
#include "../Matrix/Matrix.h"
#include "Driver.h"

class SimpleDriver: public Driver
{
private:
	double array1[25] = {1.0, 2.0, 3.0, 4.0, 5.0,2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 1.0, 1.0, 1.0, 3.0,0.0, 0.0, 2.0, 3.0, -2.0, 4.0, 4.0, -4.0, 0.0, 0.0};
	double array2[25] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 1.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, -2.0, 2.0, 2.0};
	void setMatrixes();
	std::stringstream result;
	std::string performAddition() const;
	std::string performSubtraction() const;
	std::string performMultiplication() const;
public:
	std::string getResult();
	SimpleDriver();
};


#endif /* DRIVER_SIMPLEDRIVER_H_ */
