/*
 * AdvancedDriver.h
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#ifndef DRIVER_ADVANCEDDRIVER_H_
#define DRIVER_ADVANCEDDRIVER_H_

#include <string>
#include <sstream>
#include "Utils.h"
#include "../Matrix/Matrix.h"

class AdvancedDriver {
private:
	static const int START = 1000;
	static const int END = 2001;
	static const int LOWER_BOUND = -10;
	static const int UPPER_BOUND = 10;
	std::stringstream result;
	void setMatrixes(Matrix& left, Matrix& right, const int size, Utils& utils);
	template<typename Op> double performAddition(Matrix& left, Matrix& right) const;
public:
	AdvancedDriver();
	std::string getResult();
};

#endif /* DRIVER_ADVANCEDDRIVER_H_ */
