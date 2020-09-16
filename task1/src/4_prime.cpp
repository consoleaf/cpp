#include <gtest/gtest.h>

using namespace std;

// Написать реализацию функции проверки числа на простоту
bool isPrime(int);

#pragma region isPrime tests

TEST(isPrime, case1) {
    EXPECT_FALSE(isPrime(1));
}

TEST(isPrime, case2) {
    EXPECT_TRUE(isPrime(2));
}

TEST(isPrime, case3) {
    EXPECT_TRUE(isPrime(3));
}

TEST(isPrime, case4) {
    EXPECT_FALSE(isPrime(25));
}

TEST(isPrime, case5) {
    EXPECT_TRUE(isPrime(197));
}

#pragma endregion

// todo
bool isPrime(int a) {
    if (a < 0) return true;
    if (a == 0 || a == 1) return false;
    for (int i = 2; i < a; i++) if (a % i == 0) return false;
    return true;
}