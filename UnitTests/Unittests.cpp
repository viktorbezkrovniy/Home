#include "stdafx.h"
#include "CppUnitTest.h"
#include <ESpace/Vector.h>
#include <ESpace/Matrix.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(constructor_vecotr_e)
		{
			Vector<int> v;
			Assert::AreEqual(0, v.x());
			Assert::AreEqual(0, v.y());
			Assert::AreEqual(0, v.z());
		}

		TEST_METHOD(constructor_vecotr_p)
		{
			Vector<int> v(1,2,3);
			Assert::AreEqual(1, v.x());
			Assert::AreEqual(2, v.y());
			Assert::AreEqual(3, v.z());
		}

		TEST_METHOD(constructor_matrix_e)
		{
			Matrix<int> v;
			for(int i = 0; i < v.getSize(); i++)
				for(int j = 0; j < v.getSize(); j++)
					Assert::AreEqual(0, v(i,j));

		}
		TEST_METHOD(matrix_multiply_vector)
		{
			Matrix<int> M(3);
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Vector<int> v(3,2,3);
			Vector<int> v1 = M * v;
			Assert::AreEqual(8, v1.x());
			Assert::AreEqual(32, v1.y());
			Assert::AreEqual(56, v1.z());
				
		}

		TEST_METHOD(vecotr_add)
		{
			Vector<int> v(1,2,3);
			Vector<int> v1(1,2,3);
			Vector<int> v2;
			v2 = v1 + v;
			Assert::AreEqual(v2.x(), 2);
			Assert::AreEqual(v2.y(), 4);
			Assert::AreEqual(v2.z(), 6);
		}
		
		TEST_METHOD(vecotr_subtract)
		{
			Vector<int> v(3,2,3);
			Vector<int> v1(1,1,1), v2;
			v2 = v - v1;
			Assert::AreEqual(v2.x(), 2);
			Assert::AreEqual(v2.y(), 1);
			Assert::AreEqual(v2.z(), 2);
			//Logger::WriteMessage("Test6");
		}

		TEST_METHOD(vector_appropriation)
		{
			Vector<int> v(3,2,3);
			v(1) = 3;
			Assert::AreEqual(v(1), 3);
		}

		TEST_METHOD(vector_equal)
		{
			Vector<int> v(3,2,3), v1;
			v1 = v;
			Assert::AreEqual(v.x(), 3);
			//Assert::IsTrue(1);
		
		}
	};
}