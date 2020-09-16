#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

/* Написать реализацию функции, вычисляющую сумму двух чисел (для этой функции также необходимо проверить,
   что сумма не превышает значение int, иначе бросить исключение) */
int sum(int, int);

#pragma region sum tests

TEST(sum, case1) {
    EXPECT_EQ(3, sum(1, 2));
}

TEST(sum, case2) {
    EXPECT_EQ(200, sum(100, 100));
}

TEST(sum, case3) {
    EXPECT_EQ(-15, sum(-5, -10));
}

TEST(sum, case4) {
    EXPECT_EQ(0, sum(1000, -1000));
}

TEST(sum, case5) {
    EXPECT_ANY_THROW(sum(INT32_MAX, 1));
}

TEST(sum, case6) {
    EXPECT_ANY_THROW(sum(INT32_MIN, -1));
}

#pragma endregion

// todo
int sum(int a, int b) {
  // throw std::runtime_error("Not implemented!");
  int sum = a + b;
  if (a > 0 && b > 0 && sum < 0 || a < 0 && b < 0 && sum > 0) // aka if overflow
    throw std::overflow_error("This number is over the INT32 limit.");
  return (int)sum;
}
