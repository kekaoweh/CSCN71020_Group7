#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../CSCN71020_P1-main/source.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleRectangleTests
{
    TEST_CLASS(TriangleTests)
    {
    public:

        // Test for a valid triangle
        TEST_METHOD(ValidTriangleTest)
        {
            Assert::IsTrue(validTriangle(3, 4, 5));
            Assert::IsTrue(validTriangle(5, 12, 13));
            Assert::IsTrue(validTriangle(7, 24, 25));
        }

        // Test for invalid triangles where sum of two sides is less than or equal to the third side
        TEST_METHOD(InvalidTriangleTest)
        {
            Assert::IsFalse(validTriangle(1, 2, 5));
            Assert::IsFalse(validTriangle(1, 2, 3));
            Assert::IsFalse(validTriangle(2, 2, 5));
        }

        // Test where the sides are the same, but not a valid triangle
        TEST_METHOD(EquilateralTest)
        {
            Assert::IsTrue(validTriangle(5, 5, 5));
            Assert::IsFalse(validTriangle(0, 0, 0));  // all sides are 0
        }

    };

}
