#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fstream>

#include "../static/GridBoard.h"
#include "../static/utility.h"
#include "../static/agent.h"

using namespace testing;

TEST(GridboardTests, GridBoardConstructor)
{
    base::Agent<2,2> a1{{0,1}, '0'};
    base::Agent<2,2> a2{{1,0}, '1'};

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

TEST(GridboardTests, AgentSetDirection){
    base::Agent<3,3> a1{{1,1}, '0'};
    base::Agent<3,3> a2{{0,0}, '1'};

    base::GridBoard<3,3> board(a1, a2);

    a1.SetDesiredDirection(base::Direction::UP);
    a2.SetDesiredDirection(base::Direction::DOWN);

    char expected_status[] = "1...0....";
    const char* board_status = board.GetStatus();
    ASSERT_EQ(strcmp(expected_status, board_status), 0) << expected_status << " != " << board_status;

    board.PerformTurn();

    char expected_status_after[] = "x0.1x....";
    board_status = board.GetStatus();
    ASSERT_EQ(strcmp(expected_status_after, board_status), 0) << expected_status_after << " != " << board_status;
}
