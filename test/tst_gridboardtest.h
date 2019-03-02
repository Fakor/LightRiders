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
    base::Agent<2,2> a0{{0,1}, '0'};
    base::Agent<2,2> a1{{1,0}, '1'};

    base::GridBoard<2,2> board(a0, a1);

    board.SendStatus();

    char expected_status[] = ".10.";
    const char* board_status = board.GetStatus();
    const char* actual_status_1 = a0.CurrentStatus();
    const char* actual_status_2 = a1.CurrentStatus();

    ASSERT_EQ(strcmp(expected_status, board_status), 0) << expected_status << " != " << board_status;
    ASSERT_EQ(strcmp(expected_status, actual_status_1), 0) << expected_status << " != " << actual_status_1;
    ASSERT_EQ(strcmp(expected_status, actual_status_2), 0) << expected_status << " != " << actual_status_2;
}

TEST(GridboardTests, AgentSetDirection){
    base::Agent<3,3> a0{{1,1}, '0'};
    base::Agent<3,3> a1{{0,0}, '1'};

    base::GridBoard<3,3> board(a0, a1);

    a0.SetDesiredDirection(base::Direction::UP);
    a1.SetDesiredDirection(base::Direction::DOWN);

    char expected_status_1[] = "1...0....";
    const char* board_status = board.GetStatus();
    ASSERT_EQ(strcmp(expected_status_1, board_status), 0) << expected_status_1 << " != " << board_status;

    board.PerformTurn();

    char expected_status_2[] = "x0.1x....";
    board_status = board.GetStatus();
    ASSERT_EQ(strcmp(expected_status_2, board_status), 0) << expected_status_2 << " != " << board_status;

    a0.SetDesiredDirection(base::Direction::RIGHT);
    a1.SetDesiredDirection(base::Direction::UP);

    board.PerformTurn();

    char expected_status_3[] = "xx0xx.1..";
    board_status = board.GetStatus();
    ASSERT_EQ(strcmp(expected_status_3, board_status), 0) << expected_status_3 << " != " << board_status;
}
