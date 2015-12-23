#include "Vector.h"
#include <cassert>
//test git commit
//2
template<class Type>
Vector<Type>::Vector(const Vector& V)
{
	mE[0] = V.mE[0];
	mE[1] = V.mE[1];
	mE[2] = V.mE[2];
}

template <class Type>
Vector<Type>& Vector<Type>::operator=(const Vector& V)
{
	if(&V != this)
	{
		mE[0] = V.mE[0];
		mE[1] = V.mE[1];
		mE[2] = V.mE[2];
	}
	return *this;
}

template <class Type>
Type Vector<Type>::scalar(const Vector<Type>& v)
{
	return mE[0] * v.x() + mE[1] * v.y() + mE[2] * v.z();	
}

template <class Type>
Type& Vector<Type>::operator () (int x)
{
	assert(x >= 0 && x < 3);
	if (x >= 0 && x < 3)
		return mE[x];	
	static Type val = 0;
	return val;
}

template <class Type>
const Type& Vector<Type>::operator () (int x) const
{
	assert(x >= 0 && x < 3);
	if (x >= 0 && x < 3)
		return mE[x];	
	static Type val = 0;
	return val;	
}

template <class Type>
Vector<Type> operator - (const Vector<Type>& v1, const Vector<Type>& v2)
{
	Vector<Type> res;
	res.mE[0] = v1.mE[0] - v2.mE[0];
	res.mE[1] = v1.mE[1] - v2.mE[1];
	res.mE[2] = v1.mE[2] - v2.mE[2];
	return res;
}
template Vector<int> operator - (const Vector<int>& v1, const Vector<int>& v2);

template <class Type>
Vector<Type> operator + (const Vector<Type>& v1, const Vector<Type>& v2)
{
	Vector<Type> res;
	res.mE[0] = v1.mE[0] + v2.mE[0];
	res.mE[1] = v1.mE[1] + v2.mE[1];
	res.mE[2] = v1.mE[2] + v2.mE[2];
	return res;
}
template Vector<int> operator + (const Vector<int>& v1,const Vector<int>& v2);

template <class Type>
Vector<Type>& Vector<Type>::operator += (const Vector& v)
{
	*this = *this + v;
	return *this;
}

template <class Type>
Vector<Type>& Vector<Type>::operator -= (const Vector& v)
{
	*this = *this - v;
	return *this;
}

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;
