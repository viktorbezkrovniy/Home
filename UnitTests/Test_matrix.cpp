#include "stdafx.h"
#include "CppUnitTest.h"
#include <ESpace/Vector.h>
#include <ESpace/Matrix.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Matrix_tests)
	{
	public:
		
		TEST_METHOD(constructor_matrix)
		{
			Matrix<int> v;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					Assert::AreEqual(0, v(i,j));

		}

		TEST_METHOD(matrix_constructor_copy)
		{
			Matrix<int> M;
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Matrix<int> M2(M);

			Assert::AreEqual(0, M(0,0));
			Assert::AreEqual(1, M(0,1));
			Assert::AreEqual(2, M(0,2));
			Assert::AreEqual(3, M(1,0));
			Assert::AreEqual(4, M(1,1));
			Assert::AreEqual(5, M(1,2));
			Assert::AreEqual(6, M(2,0));
			Assert::AreEqual(7, M(2,1));
			Assert::AreEqual(8, M(2,2));
		}

		TEST_METHOD(matrix_equal)
		{
			Matrix<int> M;
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Matrix<int> M2 = M;

			Assert::AreEqual(0, M(0,0));
			Assert::AreEqual(1, M(0,1));
			Assert::AreEqual(2, M(0,2));
			Assert::AreEqual(3, M(1,0));
			Assert::AreEqual(4, M(1,1));
			Assert::AreEqual(5, M(1,2));
			Assert::AreEqual(6, M(2,0));
			Assert::AreEqual(7, M(2,1));
			Assert::AreEqual(8, M(2,2));
		}

		TEST_METHOD(matrix_appropriation)
		{
			Matrix<int> M;
			M(0,1) = 3;
			Assert::AreEqual(M(0,1), 3);
		}

		TEST_METHOD(matrix_multiply_vector)
		{
			Matrix<int> M;
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

		TEST_METHOD(matrix_multiply_matrix)
		{
			Matrix<int> M;
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Matrix<int> M2;
			M2(0,1) = 1;
			M2(0,2) = 2;
			M2(1,0) = 3;
			M2(1,1) = 4;
			M2(1,2) = 5;
			M2(2,0) = 6;
			M2(2,1) = 7;
			M2(2,2) = 8;

			Matrix<int> M3 = M * M2;
			Assert::AreEqual(15,  M3(0,0));
			Assert::AreEqual(18,  M3(0,1));
			Assert::AreEqual(21,  M3(0,2));
			Assert::AreEqual(42,  M3(1,0));
			Assert::AreEqual(54,  M3(1,1));
			Assert::AreEqual(66,  M3(1,2));
			Assert::AreEqual(69,  M3(2,0));
			Assert::AreEqual(90,  M3(2,1));
			Assert::AreEqual(111, M3(2,2));
		}

		TEST_METHOD(matrix_add_matrix)
		{
			Matrix<int> M;
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Matrix<int> M2;
			M2(0,1) = 1;
			M2(0,2) = 2;
			M2(1,0) = 3;
			M2(1,1) = 4;
			M2(1,2) = 5;
			M2(2,0) = 6;
			M2(2,1) = 7;
			M2(2,2) = 8;

			Matrix<int> M3 = M + M2;
			Assert::AreEqual(0,  M3(0,0));
			Assert::AreEqual(2,  M3(0,1));
			Assert::AreEqual(4,  M3(0,2));
			Assert::AreEqual(6,  M3(1,0));
			Assert::AreEqual(8,  M3(1,1));
			Assert::AreEqual(10, M3(1,2));
			Assert::AreEqual(12, M3(2,0));
			Assert::AreEqual(14, M3(2,1));
			Assert::AreEqual(16, M3(2,2));
		}

		TEST_METHOD(matrix_add_equal)
		{
			Matrix<int> M;
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Matrix<int> M2;
			M2(0,1) = 1;
			M2(0,2) = 2;
			M2(1,0) = 3;
			M2(1,1) = 4;
			M2(1,2) = 5;
			M2(2,0) = 6;
			M2(2,1) = 7;
			M2(2,2) = 8;

			M += M2;
			Assert::AreEqual(0,  M(0,0));
			Assert::AreEqual(2,  M(0,1));
			Assert::AreEqual(4,  M(0,2));
			Assert::AreEqual(6,  M(1,0));
			Assert::AreEqual(8,  M(1,1));
			Assert::AreEqual(10, M(1,2));
			Assert::AreEqual(12, M(2,0));
			Assert::AreEqual(14, M(2,1));
			Assert::AreEqual(16, M(2,2));
		}

		TEST_METHOD(matrix_subtract_matrix)
		{
			Matrix<int> M;
			M(0,0) = 1;
			M(0,1) = 2;
			M(0,2) = 3;
			M(1,0) = 4;
			M(1,1) = 5;
			M(1,2) = 6;
			M(2,0) = 7;
			M(2,1) = 8;
			M(2,2) = 9;

			Matrix<int> M2;
			M2(0,1) = 1;
			M2(0,2) = 2;
			M2(1,0) = 3;
			M2(1,1) = 4;
			M2(1,2) = 5;
			M2(2,0) = 6;
			M2(2,1) = 7;
			M2(2,2) = 8;

			Matrix<int> M3 = M - M2;
			Assert::AreEqual(1,  M3(0,0));
			Assert::AreEqual(1,  M3(0,1));
			Assert::AreEqual(1,  M3(0,2));
			Assert::AreEqual(1,  M3(1,0));
			Assert::AreEqual(1,  M3(1,1));
			Assert::AreEqual(1,  M3(1,2));
			Assert::AreEqual(1,  M3(2,0));
			Assert::AreEqual(1,  M3(2,1));
			Assert::AreEqual(1,  M3(2,2));
		}

		TEST_METHOD(matrix_subtract_equal)
		{
			Matrix<int> M;
			M(0,0) = 1;
			M(0,1) = 2;
			M(0,2) = 3;
			M(1,0) = 4;
			M(1,1) = 5;
			M(1,2) = 6;
			M(2,0) = 7;
			M(2,1) = 8;
			M(2,2) = 9;

			Matrix<int> M2;
			M2(0,1) = 1;
			M2(0,2) = 2;
			M2(1,0) = 3;
			M2(1,1) = 4;
			M2(1,2) = 5;
			M2(2,0) = 6;
			M2(2,1) = 7;
			M2(2,2) = 8;

			M -= M2;
			Assert::AreEqual(1,  M(0,0));
			Assert::AreEqual(1,  M(0,1));
			Assert::AreEqual(1,  M(0,2));
			Assert::AreEqual(1,  M(1,0));
			Assert::AreEqual(1,  M(1,1));
			Assert::AreEqual(1,  M(1,2));
			Assert::AreEqual(1,  M(2,0));
			Assert::AreEqual(1,  M(2,1));
			Assert::AreEqual(1,  M(2,2));
		}

		TEST_METHOD(matrix_multiply_equal)
		{
			Matrix<int> M;
			M(0,1) = 1;
			M(0,2) = 2;
			M(1,0) = 3;
			M(1,1) = 4;
			M(1,2) = 5;
			M(2,0) = 6;
			M(2,1) = 7;
			M(2,2) = 8;

			Matrix<int> M2;
			M2(0,1) = 1;
			M2(0,2) = 2;
			M2(1,0) = 3;
			M2(1,1) = 4;
			M2(1,2) = 5;
			M2(2,0) = 6;
			M2(2,1) = 7;
			M2(2,2) = 8;

			M *= M2;

			Assert::AreEqual(15,  M(0,0));
			Assert::AreEqual(18,  M(0,1));
			Assert::AreEqual(21,  M(0,2));
			Assert::AreEqual(42,  M(1,0));
			Assert::AreEqual(54,  M(1,1));
			Assert::AreEqual(66,  M(1,2));
			Assert::AreEqual(69,  M(2,0));
			Assert::AreEqual(90,  M(2,1));
			Assert::AreEqual(111, M(2,2));
		}
	};
}