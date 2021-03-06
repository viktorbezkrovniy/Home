
#include <cassert>
#include "Matrix.h"

template<class Type>
Matrix<Type>::Matrix()
	: mData(0)
{
	mData = new Type[9];
	memset(mData, 0, 9 * sizeof(Type));
};

template<class Type>
Matrix<Type>::~Matrix()
{ 
	delete [] mData; 
}

template<class Type>
Matrix<Type>::Matrix(const Matrix& Mat)
	: mData(0)
{ 
	mData = new Type[9];
	memcpy(mData, Mat.mData, 9 * sizeof(Type));
}

template <class Type>
Matrix<Type>& Matrix<Type>::operator = (const Matrix& Mat)
{
	if (&Mat != this)
	{
		delete[] mData; 
		mData = new Type[9];
		memcpy(mData, Mat.mData, 9 * sizeof(Type));
	}
	return *this;
}

template <class Type>
Matrix<Type> Matrix<Type>::operator + (const Matrix& m) const
{
	Matrix<Type> c;
	for(int i = 0; i < 3; i++) 
	{
		for(int l = 0; l < 3; l++) 
		{
			c(i,l) = (*this)(i,l) + m(i,l);
		}
	}
	return c;
}


template <class Type>
Matrix<Type> Matrix<Type>::operator - (const Matrix& m) const
{
	Matrix<Type> c;
	for( int i = 0; i < 3; i++) 
	{
		for(int l = 0; l < 3; l++) 
		{
			c(i,l) = (*this)(i,l) - m(i,l);
		}
	}
	return c;
}

template <class Type>
Matrix<Type>& Matrix<Type>::operator *= (const Matrix& m)
{
	*this = *this * m; 
	return *this;
}

template <class Type>
Matrix<Type>& Matrix<Type>::operator += (const Matrix& m)
{
	*this = *this + m; 
	return *this;
}

template <class Type>
Matrix<Type>& Matrix<Type>::operator -= (const Matrix& m)
{
	*this = *this - m; 
	return *this;
}

template <class Type>
Type& Matrix<Type>::operator () (int y, int x)
{
	assert(x >= 0 && x < 3);
	assert(y >= 0 && y < 3);
	if ( (x >= 0 && x < 3) && (y >= 0 && y < 3) )
		return mData[y * 3 + x];
	static Type val = 0;
	return val;	
}

template <class Type>
const Type& Matrix<Type>::operator () (int y, int x) const
{
	assert(x >= 0 && x < 3);
	assert(y >= 0 && y < 3);
	if ( (x >= 0 && x < 3) && (y >= 0 && y < 3) )
			return mData[y * 3 + x];
	static Type val = 0;
	return val;
}

template <class Type>
Vector<Type> operator * (const Matrix<Type>& m, const Vector<Type>& v)
{
	Vector<Type> res;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			res(i) += m(i,j) * v(j);
	return res;
}
template Vector<int> operator * (const Matrix<int>& m, const Vector<int>& v);

template <class Type>
Matrix<Type> operator * (const Matrix<Type>& m1, const Matrix<Type>& m2)
{
	Matrix<Type> c;
	for(int i = 0; i < 3; i++) 
	{
		for(int l = 0; l < 3; l++) 
		{
			Type s = 0;
			for(int j = 0; j < 3; j++) 
			{
				s += m1(i,j) * m2(j,l);
			}
			c(i,l) = s;
		}
	}
	return c;
}
template Matrix<int> operator * (const Matrix<int>& m1, const Matrix<int>& m2);
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;