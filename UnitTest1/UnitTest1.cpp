#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2(it)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 3;
            const int Low = 1;
            const int High = 9;

            int** matrix = new int* [n];
            for (int i = 0; i < n; i++)
                matrix[i] = new int[n];

            CreateIterative(matrix, n, Low, High);
            Assert::AreEqual(1, matrix[2][1]);

            for (int i = 0; i < n; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
	};
}
