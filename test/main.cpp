#include "tst_gridboardtest.h"
#include "tst_enginetest.h"
#include "tst_agenttest.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
