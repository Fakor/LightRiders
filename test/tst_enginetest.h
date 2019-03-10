#ifndef TST_ENGINETEST_H
#define TST_ENGINETEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../static/agent.h"

#include "../static/standard_definitions.h"

using namespace testing;

TEST(EngineTests, StandardBoardSize){
    standard::GridBoard board;

    ASSERT_EQ(board.GetWidth(), 16);
    ASSERT_EQ(board.GetHeight(), 16);
}

#endif // TST_ENGINETEST_H
