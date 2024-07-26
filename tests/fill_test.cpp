#include <fill/fill.h>
#include <gtest/gtest.h>

TEST(FillIntTest, TestEmptyVector) {
    std::vector<int> a = {};
    fill<int>(a, 0);
    ASSERT_EQ(a.size(), 0);
}

TEST(FillIntTest, TestOneElementVector) {
    std::vector<int> a = {1};
    fill<int>(a, 2);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a[0], 2);
}

TEST(FillIntTest, TestMoreThanOneElementVector) {
    std::vector<int> a = {2, 3, 2};
    fill<int>(a, 3);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(a[0], 3);
    ASSERT_EQ(a[1], 3);
    ASSERT_EQ(a[2], 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}