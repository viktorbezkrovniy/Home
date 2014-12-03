#include<stdio.h>
#include<iostream>
#include <ESpace/Matrix.h>
#include <ESpace/Vector.h>

int main()
{
	/*Matrix<int> M(3);
	M(0,1) = 1;
	M(0,2) = 2;
	M(1,0) = 3;
	M(1,1) = 4;
	M(1,2) = 5;
	M(2,0) = 6;
	M(2,1) = 7;
	M(2,2) = 8;
	for( int i = 0; i < M.getSize(); i++) 
	{
		for(int l = 0; l < M.getSize(); l++) 
		{
			std::cout<<M(i,l)<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	
	Matrix<int> M1 = M;
	M1(0,1) = 2;
	M1(1,0) = 1;
	M1(1,1) = 3;

	for( int i = 0; i < M1.getSize(); i++) 
	{
		for(int l = 0; l < M1.getSize(); l++) 
		{
			std::cout<<M1(i,l)<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	Matrix<int> M3;
	
	M3 = M + M1;

	for( int i = 0; i < M.getSize(); i++) 
	{
		for(int l = 0; l < M.getSize(); l++) 
		{
			std::cout<<M3(i,l)<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	*/


	Vector<int> v(3,2,3);
	Vector<int> v1(v);

	//std::cout<<v.scalar(v1)<<std::endl;

	//v2 = v + v1;
	for(int l = 0; l < 3; l++) 
	{
		std::cout<<v(l)<<std::endl;
	}

	return 0;
}