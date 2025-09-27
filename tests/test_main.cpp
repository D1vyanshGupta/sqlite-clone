#include <gtest/gtest.h>

TEST(SampleTest, Addition)
{
    EXPECT_EQ(1 + 1, 2);
}

TEST(SampleTest, BooleanCheck)
{
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
