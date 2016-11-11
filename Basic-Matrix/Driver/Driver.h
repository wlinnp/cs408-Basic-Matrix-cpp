/*
 * Driver.h
 *
 *  Created on: Nov 11, 2016
 *      Author: william
 */

#ifndef DRIVER_DRIVER_H_
#define DRIVER_DRIVER_H_

#include "../Matrix/Matrix.h"

class Driver {
protected:
	int size;
	Matrix* left;
	Matrix* right;
public:
	~Driver();
};

#endif /* DRIVER_DRIVER_H_ */
