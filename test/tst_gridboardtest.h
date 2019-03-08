#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fstream>

#include "../static/GridBoard.h"
#include "../static/utility.h"
#include "../static/agent.h"
#include "../static/connection.h"

using namespace testing;

TEST(GridboardTests, GridBoardConstructor)
{
    base::Connection<4> a0;
    base::Connection<4> a1;

    base::GridBoard<2,2> board(a0, a1);

    board.SetStartPosition({0,1}, {1,0});

    board.UpdateStatus();

    base::Status<4> expected_status(".10.");

    auto board_status = board.GetStatus();

    ASSERT_EQ(expected_status, board_status) << expected_status << " != " << board_status;
    ASSERT_EQ(expected_status, a0.ReceiveStatus()) << expected_status << " != " << a0.ReceiveStatus();
    ASSERT_EQ(expected_status, a1.ReceiveStatus()) << expected_status << " != " << a1.ReceiveStatus();
}

TEST(GridboardTests, AgentSetDirection){
    base::Connection<9> a0;
    base::Connection<9> a1;

    base::GridBoard<3,3> board(a0, a1);

    board.SetStartPosition({1,1}, {0,0});

    a0.SendAction(base::Action::UP);
    a1.SendAction(base::Action::DOWN);

    base::Status<9> expected_status_1("1...0....");
    auto board_status = board.GetStatus();
    ASSERT_EQ(expected_status_1, board_status) << expected_status_1 << " != " << board_status;

    bool round_done = board.PerformTurn();

    ASSERT_FALSE(round_done);

    base::Status<9> expected_status_2("x0.1x....");
    board_status = board.GetStatus();
    ASSERT_EQ(expected_status_2, board_status) << expected_status_2 << " != " << board_status;

    a0.SendAction(base::Action::RIGHT);
    a1.SendAction(base::Action::UP);

    round_done = board.PerformTurn();

    ASSERT_FALSE(round_done);

    base::Status<9> expected_status_3("xx0xx.1..");
    board_status = board.GetStatus();
    ASSERT_EQ(expected_status_3, board_status) << expected_status_3 << " != " << board_status;

    a1.SendAction(base::Action::RIGHT);

    round_done = board.PerformTurn();

    ASSERT_TRUE(round_done);

    ASSERT_FALSE(board.Agent0Alive());
    ASSERT_TRUE(board.Agent1Alive());
}

TEST(GridboardTests, BlockedSquare){
    base::Connection<9> a0;
    base::Connection<9> a1;

    base::GridBoard<3,3> board(a0, a1);

    board.SetStartPosition({1,1}, {0,0});

    a0.SendAction(base::Action::LEFT);
    a1.SendAction(base::Action::RIGHT);

    bool round_done = board.PerformTurn();
    ASSERT_FALSE(round_done);

    a0.SendAction(base::Action::DOWN);
    a1.SendAction(base::Action::DOWN);

    round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);
    ASSERT_TRUE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}

TEST(GridBoardTests, AgentCrashing){
    base::Connection<9> a0;
    base::Connection<9> a1;

    base::GridBoard<3,3> board(a0, a1);

    board.SetStartPosition({1,1}, {0,1});

    a0.SendAction(base::Action::LEFT);
    a1.SendAction(base::Action::RIGHT);

    bool round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);
    ASSERT_FALSE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}

TEST(GridBoardTests, AgentCrashing2){
    base::Connection<9> a0;
    base::Connection<9> a1;

    base::GridBoard<3,3> board(a0, a1);

    board.SetStartPosition({2,1}, {0,1});

    a0.SendAction(base::Action::LEFT);
    a1.SendAction(base::Action::RIGHT);

    bool round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);
    ASSERT_FALSE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}

