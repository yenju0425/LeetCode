#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gmock_verbose = "error";
    return RUN_ALL_TESTS();
}
