
#include <cassert>
#include"Matrix.h"

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template<class Type>
Matrix<Type>::Matrix(int n)
	: size(n)
	, DATA(0)
{
	DATA = new Type[size * size];

	for(int i = 0; i < size * size; i++)
		DATA[i] = 0;
};
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template<class Type>
Matrix<Type>::~Matrix()
{ 
	delete [] DATA; 
}
template class Matrix<int>;

template<class Type>
Matrix<Type>::Matrix(const Matrix& Mat)
	: size(Mat.size)
	, DATA(0)
{ 
	DATA = new Type[size * size];
	/*for(int i = 0; i < size * size; i++)
		*(DATA + i) = *(Mat.DATA + i);*/
	memcpy(DATA, Mat.DATA, size * size * sizeof(Type));
}
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template <class Type>
Matrix<Type>& Matrix<Type>::operator=(const Matrix& Mat)
{
	if (&Mat != this)
	{
		delete[] DATA; 
		size = Mat.size;
		DATA = new Type[size * size];
		memcpy(DATA, Mat.DATA, size * size * sizeof(Type));
		//for(int i = 0; i < size * size; i++)
		//	DATA[i] = Mat.DATA[i];   //*copy function for arrays
	}
	return *this;
}
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template <class Type>
Matrix<Type> Matrix<Type>::operator+(const Matrix& m) const
{
	Matrix<Type> c(m.size);
	for( int i = 0; i < m.getSize(); i++) 
	{
		for(int l = 0; l < m.getSize(); l++) 
		{
			c(i,l) = (*this)(i,l) + m(i,l);
		}
	}
	return c;
}
template class Matrix<int>;

template <class Type>
Matrix<Type> Matrix<Type>::operator-(const Matrix& m) const
{
	Matrix<Type> c(m.size);
	for( int i = 0; i < m.getSize(); i++) 
	{
		for(int l = 0; l < m.getSize(); l++) 
		{
			c(i,l) = (*this)(i,l) - m(i,l);
		}
	}
	return c;
}
template class Matrix<int>;

/*template <class Type>
Matrix<Type> Matrix<Type>::operator*(const Matrix& m) const
{
	Matrix<Type> c(m.size);
	for(int i = 0; i < m.size; i++) 
	{
		for(int l = 0; l < m.size; l++) 
		{
			Type s = 0;
			for(int j = 0; j < m.size; j++) 
			{
				s += (*this)(i,j) * m(j,l); 
			}
			c(i,l) = s;
		}
	}
	return c;
}
template class Matrix<int>;
*/
template <class Type>
Matrix<Type>& Matrix<Type>::operator *= (const Matrix& m)
{
	*this = *this * m; 
	return *this;
}
template class Matrix<int>;

template <class Type>
Type& Matrix<Type>::operator () (int y, int x)
{
	assert(x >= 0 && x < size);
	assert(y >= 0 && y < size);
	return DATA[y * size + x];		
}
template class Matrix<int>;

template <class Type>
const Type& Matrix<Type>::operator () (int y, int x) const
{
	assert(x >= 0 && x < size);
	assert(y >= 0 && y < size);
	return DATA[y * size + x];		
}
template class Matrix<int>;

template <class Type>
Vector<Type> operator * (const Matrix<Type>& m, const Vector<Type>& v)
{
	Vector<Type> res;
	for(int i = 0; i < m.getSize(); i++)
		for(int j = 0; j < m.getSize(); j++)
			res(i) += m(i,j) * v(j);
	return res;
}
template Vector<int> operator * (const Matrix<int>& m, const Vector<int>& v);

template <class Type>
Matrix<Type> operator * (const Matrix<Type>& m1, const Matrix<Type>& m2)
{
	Matrix<Type> c(m1.getSize());
	for(int i = 0; i < m1.getSize(); i++) 
	{
		for(int l = 0; l < m1.getSize(); l++) 
		{
			Type s = 0;
			for(int j = 0; j < m1.getSize(); j++) 
			{
				s += m1(i,j) * m2(j,l);
			}
			c(i,l) = s;
		}
	}
	return c;
}
template class Matrix<int>;
template Matrix<int> operator * (const Matrix<int>& m1, const Matrix<int>& m2);