#pragma once
#include <iostream>

template <class Type>
class Vector
{
	private:
      Type mE[3];

	public:
		Vector() 
		{	mE[0] = 0;
			mE[1] = 0;
		    mE[2] = 0;
		};
		Vector(Type X, Type Y, Type Z)
		{	mE[0] = X;
			mE[1] = Y;
		    mE[2] = Z;
		};
		Vector(const Vector&); 

		const Type& x() const {return mE[0];}
		const Type& y() const {return mE[1];}
		const Type& z() const {return mE[2];}
		Type& x() {return mE[0];}
		Type& y() {return mE[1];}
		Type& z() {return mE[2];}
		
		Type scalar(const Vector& v); 
		Vector& operator = (const Vector& v);
		Type& operator () (int x);
		const Type& operator () (int x) const;
		template<class T>
		friend Vector<T> operator - (const Vector<T>& v,const Vector<T>& v0);
		template<class T>
		friend Vector<T> operator + (const Vector<T>& v1,const Vector<T>& v2);
};