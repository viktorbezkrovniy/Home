#pragma once
#include <iostream>
#include "Vector.h"

template<class Type>
class Matrix
{
private:
	int size; 
	Type* DATA;
public:
	Matrix(int s = 3);
		
	Matrix(const Matrix&);
		
	~Matrix();
	
	int getSize() const { return size; }

	Type& operator () (int x, int y);
	const Type& operator () (int x, int y) const;
	Matrix operator + (const Matrix&) const;
	Matrix operator - (const Matrix& m) const;
	Matrix& operator = (const Matrix&);
//	Matrix operator * (const Matrix&) const;
	Matrix& operator*=(const Matrix&);
	template<class T>
	friend Vector<T> operator * (const Matrix<T>& m, const Vector<T>& v);
	template<class T>
	friend Matrix<T> operator * (const Matrix<T>& m1, const Matrix<T>& m2);
};