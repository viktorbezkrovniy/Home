#include "stdafx.h"
#include "CppUnitTest.h"
#include <ESpace/Vector.h>
#include <ESpace/Matrix.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Vector_tests)
	{
	public:
		
		TEST_METHOD(constructor_vecotr)
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

		TEST_METHOD(constructor_copy_vecotr)
		{
			Vector<int> v(1,2,3);
			Vector<int> v1(v);
			Assert::AreEqual(1, v1.x());
			Assert::AreEqual(2, v1.y());
			Assert::AreEqual(3, v1.z());
		}

		TEST_METHOD(vector_appropriation)
		{
			Vector<int> v(3,2,3);
			v(1) = 3;
			Assert::AreEqual(v(1), 3);
		}

		TEST_METHOD(vector_scalar)
		{
			Vector<int> v(3,2,3);
			Vector<int> v1(1,1,1);
			Assert::AreEqual(8, v.scalar(v1));
		}

		TEST_METHOD(vector_equal)
		{
			Vector<int> v(3,2,3), v1;
			v1 = v;
			Assert::AreEqual(v.x(), 3);
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

		TEST_METHOD(vecotr_subtract_equal)
		{
			Vector<int> v(1,2,3);
			Vector<int> v1(1,2,4);
			v1 -= v;
			Assert::AreEqual(v1.x(), 0);
			Assert::AreEqual(v1.y(), 0);
			Assert::AreEqual(v1.z(), 1);
		}

		TEST_METHOD(vecotr_add_equal)
		{
			Vector<int> v(1,2,3);
			Vector<int> v1(1,2,3);
			v1 += v;
			Assert::AreEqual(v1.x(), 2);
			Assert::AreEqual(v1.y(), 4);
			Assert::AreEqual(v1.z(), 6);
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
	};
}