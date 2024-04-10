#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project12\1.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 2,11,4,13,5,-2 };
			int b = maxSubSum(a, 0, 5);
			Assert::AreEqual(35, b);
		}
		TEST_METHOD(TestMethod2)
		{
			int a[] = { -2,-11,-4,-13,-5,-2 };
			int b = maxSubSum(a, 0, 5);
			Assert::AreEqual(0, b);
		}
		TEST_METHOD(TestMethod3)
		{
			int a[] = { -2,-11,4,-13,5 };
			int b = maxSubSum(a, 0, 4);
			Assert::AreEqual(5, b);
		}
		TEST_METHOD(TestMethod4)
		{
			int a[] = { -2,4,-13,5 };
			int b = maxSubSum(a, 0, 3);
			Assert::AreEqual(5, b);
		}
		TEST_METHOD(TestMethod5)
		{
			int a[] = { 0,0,0,0,0 };
			int b = maxSubSum(a, 0, 4);
			Assert::AreEqual(0, b);
		}
	};
}
