#include <gtest/gtest.h>

// main may or may not be defined, as linking to gtest_main defines it already
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
