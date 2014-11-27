#include"Vector.h"
#include <cassert>

template<class Type>
Vector<Type>::Vector(const Vector& V)
{
	for(int i = 0; i < 3; i++)
		mE[i] = V.mE[i];
		
}
template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

template <class Type>
Vector<Type>& Vector<Type>::operator=(const Vector& V)
{
	for(int i = 0; i < 3; i++)
		mE[i] = V.mE[i];
	return *this;
}
template class Vector<int>;
template class Vector<float>;
template class Vector<double>;


template <class Type>
Type Vector<Type>::scalar(const Vector<Type>& v)
{
	return mE[0] * v.x() + mE[1] * v.y() + mE[2] * v.z();	
};
template class Vector<int>;

template <class Type>
Type& Vector<Type>::operator () (int x)
{
	assert(x >= 0 && x < 3);
	return mE[x];	
}
template class Vector<int>;

template <class Type>
const Type& Vector<Type>::operator () (int x) const
{
	assert(x >= 0 && x < 3);
	return mE[x];	
}
template class Vector<int>;

template <class Type>
Vector<Type> operator - (const Vector<Type>& v, const Vector<Type>& v0)
{
	Vector<Type> res;
	for(int i = 0; i < 3; i++)
			res(i) = v(i) - v0(i);
	return res;
}
template Vector<int> operator - (const Vector<int>& v1,const Vector<int>& v2);

template <class Type>
Vector<Type> operator + (const Vector<Type>& v1,const Vector<Type>& v2)
{
	Vector<Type> res;
	for(int i = 0; i < 3; i++)
			res(i) = v1(i) + v2(i);
	return res;
}
template Vector<int> operator+(const Vector<int>& v1,const Vector<int>& v2);