#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[5] = { 1, -2, 0, 4, -5 };
			int b[5];

			copy(&a[0], &a[5], &b[0]);

			for (int i = 0; i < 5; i++)
			{
				Assert::AreEqual(a[i], b[i], L"Elements should be equal");
			}
		}
	};
}
