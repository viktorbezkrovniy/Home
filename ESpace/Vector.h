#pragma once
#include <iostream>

template <class Type>
class Vector
{
	private:
		Type mE[3];

	public:
		Vector() 
		{
			mE[0] = 0;
			mE[1] = 0;
		    mE[2] = 0;
		}
		Vector(Type X, Type Y, Type Z)
		{
			mE[0] = X;
			mE[1] = Y;
		    mE[2] = Z;
		}
		Vector(const Vector&); 

		inline const Type& x() const {return mE[0];}
		inline const Type& y() const {return mE[1];}
		inline const Type& z() const {return mE[2];}
		inline Type& x() {return mE[0];}
		inline Type& y() {return mE[1];}
		inline Type& z() {return mE[2];}
		
		Type scalar(const Vector& v); 
		Vector& operator = (const Vector& v);
		Vector& operator += (const Vector& v);
		Vector& operator -= (const Vector& v);
		Type& operator () (int x);
		const Type& operator () (int x) const;
		template<class T>
		friend Vector<T> operator - (const Vector<T>& v1, const Vector<T>& v2);
		template<class T>
		friend Vector<T> operator + (const Vector<T>& v1, const Vector<T>& v2);
};