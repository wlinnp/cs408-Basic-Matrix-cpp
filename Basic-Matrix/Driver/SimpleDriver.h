/*
 * SimpleDriver.h
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#ifndef DRIVER_SIMPLEDRIVER_H_
#define DRIVER_SIMPLEDRIVER_H_

#include <string>
#include "../Matrix/Matrix.h"

class SimpleDriver
{
private:
	double array1[25] = {1.0, 2.0, 3.0, 4.0, 5.0,2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 1.0, 1.0, 1.0, 3.0,0.0, 0.0, 2.0, 3.0, -2.0, 4.0, 4.0, -4.0, 0.0, 0.0};
	double array2[25] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 1.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, -2.0, 2.0, 2.0};
	const int size = 5;
	void setMatrixes(Matrix& left, Matrix& right);
	std::string result;
	std::string performAddition(Matrix& left, Matrix& right) const;
	std::string performSubtraction(Matrix& left, Matrix& right) const;
	std::string performMultiplication(Matrix& left, Matrix& right) const;
public:
	std::string getResult();
	SimpleDriver();
};


#endif /* DRIVER_SIMPLEDRIVER_H_ */
