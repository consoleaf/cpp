#include <gtest/gtest.h>
#include <cmath>

using namespace std;

/* (**) Написать реализацию функции вычисления корня из числа без использования встроенной функции корня
 *      с точностью до 6 знаков после запятой */
double mySqrt(double);

#pragma region mySqrt tests

const static double ABS_ERROR = 1e-6;

TEST(mySqrt, case1) {
    const auto x = 2;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case2) {
    const auto x = 9;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case3) {
    const auto x = 100;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case4) {
    const auto x = 12345678;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

TEST(mySqrt, case5) {
    const auto x = 1000000007;
    EXPECT_NEAR(sqrt(x), mySqrt(x), ABS_ERROR);
}

#pragma endregion

// todo
double mySqrt(double n) {
    double x = 1;
    for (;;) {
        double nx = (x + n / x) / 2;
        if (abs(x - nx) < ABS_ERROR) break;
        x = nx;
    }
    return x;
}