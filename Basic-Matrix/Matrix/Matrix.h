/*
 * Matrix.h
 *
 *  Created on: Nov 5, 2016
 *      Author: william
 *      Class: 	cs408
 *      Project:matrix - ver 3
 */

#ifndef MATRIX_MATRIX_H_
#define MATRIX_MATRIX_H_

#include <string>
#include <iostream>
class Matrix
{
private:
	int matrixSize;
	double** matrix;
	bool isDimensionValid(const int i, const int j) const;
	void deAllocate();
	void copyMatrix(double** input);
	template<typename Op> Matrix operate(const Matrix& right) const;
public:
	const std::string TAB = "\t\t";
	const std::string NEXT_LINE = "\n";
	Matrix(const int size);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& right);
	~Matrix();
	int getSize() const;
	double** getMatrix() const;
	void setMatrixCelll(const int i, const int j, const double value);
	std::string str() const;
	Matrix operator+(const Matrix& right) const;
	Matrix operator-(const Matrix& right) const;
	Matrix operator*(const Matrix& right) const;
	//Matrix operate(const Matrix& right, const Operator operator) const;
};

#endif /* MATRIX_MATRIX_H_ */
