#include <gtest/gtest.h>

using namespace std;

// (*) Написать реализацию функции быстрого возведения числа в степень
long long binaryPower(int, int);

#pragma region binaryPower tests

TEST(binaryPower, case1) {
    EXPECT_EQ(8, binaryPower(2, 3));
}

TEST(binaryPower, case2) {
    EXPECT_EQ(1, binaryPower(3, 0));
}

TEST(binaryPower, case3) {
    EXPECT_EQ(1125899906842624, binaryPower(2, 50));
}

TEST(binaryPower, case4) {
    EXPECT_EQ(-125, binaryPower(-5, 3));
}

TEST(binaryPower, case5) {
    EXPECT_EQ(81, binaryPower(-3, 4));
}

#pragma endregion

long long binaryPower(long long num, int pow) {
    if (pow == 0) return 1;
    if (pow == 1) return num;

    long long res = binaryPower(num, pow / 2);

    res *= res;

    if (pow % 2 != 0)
        res *= num;

    return res;
}

long long binaryPower(int num, int pow) {
    return binaryPower((long long)num, pow);
}