﻿#include<stdio.h>
#include<iostream>
#include <ESpace/Matrix.h>
#include <ESpace/Vector.h>
#include <boost/shared_ptr.hpp>
#include <boost/regex.hpp>
#include <boost\thread.hpp>


struct Hello
{
	Hello()
	{
		std::cout << "Hello constructor\n";
	}

	~Hello()
	{
		std::cout << "Hello destructor\nS";
		//std::cin.get();
	}
};

int main(int argc, char**argv)
{
	
	boost::regex regex("^(Hello|Bye) Boost$");
	boost::cmatch helloMatches;
	boost::regex_search("Hello boost", helloMatches, regex);
	std::cout << "The world between () is: "  << helloMatches[1] << std::endl;

	boost::shared_ptr<Hello> sharedHello(new Hello);
	std::cout<<boost::thread::hardware_concurrency(); //оптимальное число потоков системи 


	/*Matrix<int> M;
	M(0,1) = 1;
	M(0,2) = 2;
	M(1,0) = 3;
	M(1,1) = 4;
	M(1,2) = 5;
	M(2,0) = 6;
	M(2,1) = 7;
	M(2,2) = 8;
	for( int i = 0; i < 3; i++) 
	{
		for(int l = 0; l < 3; l++) 
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

	for( int i = 0; i < 3; i++) 
	{
		for(int l = 0; l < 3; l++) 
		{
			std::cout<<M1(i,l)<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	Matrix<int> M3;
	
	M1 += M;

	for( int i = 0; i < 3; i++) 
	{
		for(int l = 0; l < 3; l++) 
		{
			std::cout<<M1(i,l)<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;*/
	


	//Vector<int> v(3,2,3);
	//Vector<int> v1;
	//v1 += v;

	////std::cout<<v.scalar(v1)<<std::endl;

	////v2 = v + v1;
	//for(int l = 0; l < 3; l++) 
	//{
	//	std::cout<<v(l)<<std::endl;
	//}

	return 0;
}