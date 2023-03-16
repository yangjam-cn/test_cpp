/**
 * @author yangjian 1171267147@qq.com
 * @brief 交换两个变量的值
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 */
#include <gtest/gtest.h>

#include <iostream>

using namespace std;

auto swap_func = [](int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = b ^ a;
};

TEST(test_swap, case1)
{
    int a = 12, b = 24;
    swap_func(a, b);
    EXPECT_EQ(a, 24);
    EXPECT_EQ(b, 12);
}

TEST(test_swap, case2)
{
    int a = -12, b = 24;
    swap_func(a, b);
    EXPECT_EQ(a, 24);
    EXPECT_EQ(b, -12);
}

TEST(test_swap, case3)
{
    int a = -12, b = -24;
    swap_func(a, b);
    EXPECT_EQ(a, -24);
    EXPECT_EQ(b, -12);
}

TEST(test_swap, case4)
{
    int a = 0, b = 24;
    swap_func(a, b);
    EXPECT_EQ(a, 24);
    EXPECT_EQ(b, 0);
}

TEST(test_swap, case5)
{
    int a = 12, b = 12;
    swap_func(a, b);
    EXPECT_EQ(a, 12);
    EXPECT_EQ(b, 12);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}