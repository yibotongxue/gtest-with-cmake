#include <count/count.h>
#include <gtest/gtest.h>

TEST(CountIntTests, TestEmptrVector) {
    const auto expected = 0;
    const auto actual = count<int>({}, 0);
    ASSERT_EQ(expected, actual);
}

TEST(CountIntTests, TestOneElemeneVectorHas) {
    const auto expected = 0;
    const auto actual = count<int>({1}, 0);
    ASSERT_EQ(expected, actual);
}

TEST(CountIntTests, TestOneElementVectorNotHas) {
    const auto expected = 1;
    const auto actual = count<int>({-1}, -1);
    ASSERT_EQ(expected, actual);
}

TEST(CountIntTests, TestVectorHasInTheLast) {
    const auto expected = 2;
    const auto actual = count<int>({1, 2, 3, -1, 2}, 2);
    ASSERT_EQ(expected, actual);
}

TEST(CountFloatTests, TestEmptyVector) {
    const auto expected = 0;
    const auto actual = count<float>({}, 0.1);
    ASSERT_EQ(expected, actual);
}

TEST(CountFloatTests, TestOneElementVectorHas) {
    const auto expected = 1;
    const auto actual = count<float>({0.2}, 0.2);
    ASSERT_EQ(expected, actual);
}

TEST(countFLoatTests, TestOneElementVectorNotHas) {
    const auto expected = 0;
    const auto actual = count<float>({0.2}, 0.1);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}