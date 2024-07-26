#include <inner_product/inner_product.h>
#include <gtest/gtest.h>

TEST(InnerProductIntTest, TestTwoEmptyVector) {
    const std::vector<int> a = {}, b = {};
    const auto expected = 0;
    const auto actual = inner_product<int>(a, b);
    ASSERT_EQ(expected, actual);
}

TEST(InnerProductIntTest, TestTwoOneElementVector) {
    const std::vector<int> a= {1}, b = {-1};
    const auto expected = -1;
    const auto actual = inner_product<int>(a, b);
    ASSERT_EQ(expected, actual);
}

TEST(InnerProductIntTest, TestMoreThanOneElementVector) {
    const std::vector<int> a = {1, 3}, b = {2, 1};
    const auto expected = 5;
    const auto actual = inner_product<int>(a, b);
    ASSERT_EQ(expected, actual);
}

TEST(InnerProductIntTest, TestNotEqualLengthVector) {
    const std::vector<int> a = {1, 2}, b = {3};
    ASSERT_THROW(inner_product<int>(a, b), std::runtime_error);
    try {
        const auto result = inner_product<int>(a, b);
        FAIL() << "Exception not thrown";
    }
    catch(const std::runtime_error& e) {
        EXPECT_STREQ("The two vectors are not equal length.", e.what());
    }
    catch(...) {
        FAIL() << "Unexpected exception type.";
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}