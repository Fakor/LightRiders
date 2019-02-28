#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fstream>

#include "../static/GridBoard.h"
#include "../static/Position.h"
#include "../static/agent.h"

using namespace testing;

TEST(GridboardTests, GridBoardConstructor)
{
    base::Agent<2,2> a1{{0,1}};
    base::Agent<2,2> a2{{1,0}};

    base::GridBoard<2,2> board(a1, a2);

    board.SendStatus();

    char expected_status[] = ".10.";
    const char* board_status = board.GetStatus();
    const char* actual_status_1 = a1.CurrentStatus();
    const char* actual_status_2 = a2.CurrentStatus();

    ASSERT_EQ(strcmp(expected_status, board_status), 0) << expected_status << " != " << board_status;
    ASSERT_EQ(strcmp(expected_status, actual_status_1), 0) << expected_status << " != " << actual_status_1;
    ASSERT_EQ(strcmp(expected_status, actual_status_2), 0) << expected_status << " != " << actual_status_2;
}
