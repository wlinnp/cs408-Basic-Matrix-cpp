/*
 * UserDriver.h
 *
 *  Created on: Nov 10, 2016
 *      Author: william
 */

#ifndef DRIVER_USERDRIVER_H_
#define DRIVER_USERDRIVER_H_

#include "../Matrix/Matrix.h"
#include "Driver.h"

class UserDriver : public Driver {
private:
	void showMainMenu();
	void fillMatrices();
	void fillSingleMatrix(Matrix* matrix);
	void operationMenu();
public:
	void start();
};

#endif /* DRIVER_USERDRIVER_H_ */
