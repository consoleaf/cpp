#include <gtest/gtest.h>

using namespace std;

// Написать реализацию функции получения N-го числа Фибоначчи
long long fibonacci(int);

#pragma region fibonacci tests

TEST(fibonacci, case1) {
    EXPECT_EQ(8, fibonacci(6));
}

TEST(fibonacci, case2) {
    EXPECT_EQ(1, fibonacci(2));
}

TEST(fibonacci, case3) {
    EXPECT_EQ(2, fibonacci(3));
}

TEST(fibonacci, case4) {
    EXPECT_EQ(55, fibonacci(10));
}

TEST(fibonacci, case5) {
    EXPECT_EQ(12586269025, fibonacci(50));
}

#pragma endregion

long long fibonacci(int x) {
    if (x < 3) return 1;

    long long a = 1;
    long long b = 1;
    long long res;

    for (int i = 2; i < x; i++) {
        res = a + b;
        a = b;
        b = res;
    }

    return res;
}