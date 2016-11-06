/*
 * Matrix.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: william
 */

#include <string>
#include <sstream>
#include <functional>
#include "Matrix.h"

Matrix::Matrix(const int size) : matrixSize(size)
{
	matrix = new double*[matrixSize];
	for (int i = 0; i < matrixSize; ++i)
	{
		matrix[i] = new double[matrixSize];
	}

}

Matrix::Matrix(const Matrix& other)
{
	if (this == &other)
	{
		return;
	}
	matrixSize = other.getSize();
	copyMatrix(other.getMatrix());
}

Matrix& Matrix::operator=(const Matrix& right)
{
	if (this == &right)
	{
		return *this;
	}
	if (matrixSize == right.getSize())
	{
		for (int i = 0; i < matrixSize; ++i)
		{
			for (int j = 0; j < matrixSize; ++j)
			{
				matrix[i][j] = right.getMatrix()[i][j];
			}
		}
	} else
	{
		deAllocate();
		matrixSize = right.getSize();
		copyMatrix(right.getMatrix());

	}
	return *this;
}

Matrix::~Matrix()
{
	deAllocate();
	matrix = nullptr;
	matrixSize = 0;
}

void Matrix::deAllocate()
{
	for (int i = 0; i < matrixSize; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::copyMatrix(double** input)
{
	matrix = new double*[matrixSize];
	for (int i = 0; i < matrixSize; ++i)
	{
		matrix[i] = new double[matrixSize];
		for (int j = 0; j < matrixSize; ++j)
		{
			matrix[i][j] = input[i][j];
		}
	}
}

int Matrix::getSize() const
{
	return matrixSize;
}

double** Matrix::getMatrix() const
{
	return matrix;
}

bool Matrix::isDimensionValid(const int i, const int j) const
{
	return i > -1 && i < matrixSize && j > -1 && j < matrixSize;
}

void Matrix::setMatrixCelll(const int i, const int j, const double value)
{
	if (isDimensionValid(i, j))
	{
		matrix[i][j] = value;
	}
}

std::string Matrix::str() const
{
	std::stringstream sout;
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			sout << matrix[i][j] << TAB;
		}
		sout << NEXT_LINE;
	}
	sout << NEXT_LINE;
	return sout.str();
}

Matrix Matrix::operator+(const Matrix& right) const
{
	return operate<std::plus<double>>(right);
}

Matrix Matrix::operator-(const Matrix& right) const
{
	return operate<std::minus<double>>(right);
}

template<typename Op>
Matrix Matrix::operate(const Matrix& right) const
{
	if (right.getSize() != matrixSize)
	{
		return NULL;
	}
	Op o;
	Matrix result(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
             result.setMatrixCelll(i, j, o(matrix[i][j], right.getMatrix()[i][j]));
        }
    }
	return result;
}

Matrix Matrix::operator*(const Matrix& right) const
{
    if (right.getSize() != matrixSize)
    {
        return NULL;
    }
	Matrix result(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            double cellResult = 0;
            for (int k = 0; k < matrixSize; k++) {
                cellResult += matrix[i][k] * right.getMatrix()[j][k];
            }
            result.setMatrixCelll(i, j, cellResult);
        }
    }
	return result;
}
