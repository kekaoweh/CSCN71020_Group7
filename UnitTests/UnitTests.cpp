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

        // Edge case where one side is very small
            TEST_METHOD(SmallSideTest)
        {
            Assert::IsTrue(validTriangle(0.0001, 1000, 1000));
            Assert::IsFalse(validTriangle(0.0001, 1000, 0.0001));
        }

        // Edge case where sides are zero
        TEST_METHOD(ZeroSideTest)
        {
            Assert::IsFalse(validTriangle(0, 4, 5));
            Assert::IsFalse(validTriangle(0, 0, 0));
        }

        // Test for large triangle values
        TEST_METHOD(LargeTriangleTest)
        {
            Assert::IsTrue(validTriangle(1000000, 1000000, 1000000));
            Assert::IsFalse(validTriangle(1000000, 1000000, 2000000));
        }

    };
    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(ValidRectangleTest)
        {
            // Arrange
            double p1 = distance(1, 1, 4, 1);
            double p2 = distance(4, 1, 4, 4);
            double p3 = distance(4, 4, 1, 4);
            double p4 = distance(1, 4, 1, 1);
            double d1 = distance(1, 1, 4, 4);
            double d2 = distance(4, 1, 1, 4);

            int result = is_rectangle(p1, p2, p3, p4, d1, d2);

           
            Assert::AreEqual(1, result);  
        }

        TEST_METHOD(InvalidRectangleTest)
        {
            // Slightly off shape
            double p1 = distance(1, 1, 4, 1);
            double p2 = distance(4, 1, 4.5, 4);
            double p3 = distance(4.5, 4, 1, 4);
            double p4 = distance(1, 4, 1, 1);
            double d1 = distance(1, 1, 4.5, 4);
            double d2 = distance(4, 1, 1, 4);

            int result = is_rectangle(p1, p2, p3, p4, d1, d2);
            Assert::AreEqual(0, result);  
        }
        TEST_METHOD(TestIsStraightLine_Horizontal)
        {
            double x[] = { 1, 2, 3, 4 };
            double y[] = { 5, 5, 5, 5 };
            Assert::AreEqual(1, is_straight_line(x, y));
        }

        TEST_METHOD(TestIsStraightLine_Vertical)
        {
            double x[] = { 2, 2, 2, 2 };
            double y[] = { 1, 2, 3, 4 };
            Assert::AreEqual(1, is_straight_line(x, y));
        }

        TEST_METHOD(TestIsStraightLine_NotLine)
        {
            double x[] = { 1, 2, 2, 1 };
            double y[] = { 1, 1, 2, 2 };
            Assert::AreEqual(0, is_straight_line(x, y));
        }
        TEST_METHOD(TestHasDuplicatePoints_True)
        {
            double x[] = { 1, 2, 2, 1 };
            double y[] = { 1, 2, 2, 1 };  // (2,2) appears twice
            Assert::AreEqual(1, has_duplicate_points(x, y));
        }

        TEST_METHOD(TestHasDuplicatePoints_False)
        {
            double x[] = { 1, 2, 3, 4 };
            double y[] = { 1, 2, 3, 4 };
            Assert::AreEqual(0, has_duplicate_points(x, y));
        }

        TEST_METHOD(TestSortRectanglePoint_Order)
        {
            double x[] = { 4, 1, 1, 4 };
            double y[] = { 1, 1, 4, 4 };

            sortRectangle_point(x, y);

            Assert::AreEqual(1.0, x[0], 0.0001);  // Bottom-left X
            Assert::AreEqual(1.0, y[0], 0.0001);  // Bottom-left Y
            Assert::AreEqual(4.0, x[1], 0.0001);  // Bottom-right X
            Assert::AreEqual(1.0, y[1], 0.0001);  // Bottom-right Y
            Assert::AreEqual(4.0, x[2], 0.0001);  // Top-right X
            Assert::AreEqual(4.0, y[2], 0.0001);  // Top-right Y
            Assert::AreEqual(1.0, x[3], 0.0001);  // Top-left X
            Assert::AreEqual(4.0, y[3], 0.0001);  // Top-left Y
        }
    };
}
