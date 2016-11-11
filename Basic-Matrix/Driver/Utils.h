/*
 * Utils.h
 *
 *  Created on: Nov 6, 2016
 *      Author: william
 */

#ifndef DRIVER_UTILS_H_
#define DRIVER_UTILS_H_

#include <string>
class Utils {
public:
	const std::string TAB = "\t\t";
	const std::string NEXT_LINE = "\n";
	Utils();
	double getNextDouble(const double lower, const double upper);
	~Utils();
};

#endif /* DRIVER_UTILS_H_ */
