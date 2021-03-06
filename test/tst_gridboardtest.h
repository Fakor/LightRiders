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
    base::Agent<2,2> a0{};
    base::Agent<2,2> a1{};

    base::GridBoard<2,2> board;

    a0.Connect(board.GetConnection0());
    a1.Connect(board.GetConnection1());

    board.Reset({0,1}, {1,0});

    base::Status<2,2> expected_status(".10.");

    auto board_status = board.GetStatus();

    ASSERT_EQ(expected_status, board_status) << expected_status << " != " << board_status;
    ASSERT_EQ(expected_status, a0.CurrentStatus()) << expected_status << " != " << a0.CurrentStatus();
    ASSERT_EQ(expected_status, a1.CurrentStatus()) << expected_status << " != " << a1.CurrentStatus();
}

TEST(GridboardTests, AgentSetDirection){
    base::Agent<3,3> a0;
    base::Agent<3,3> a1;

    base::GridBoard<3,3> board{};

    a0.Connect(board.GetConnection0());
    a1.Connect(board.GetConnection1());

    board.Reset({1,1}, {0,0});

    a0.SetAction(base::Action::UP);
    a1.SetAction(base::Action::DOWN);

    base::Status<3,3> expected_status_1("1...0....");
    auto board_status = board.GetStatus();
    ASSERT_EQ(expected_status_1, board_status) << expected_status_1 << " != " << board_status;

    bool round_done = board.PerformTurn();

    ASSERT_FALSE(round_done);

    base::Status<3,3> expected_status_2("x0.1x....");
    board_status = board.GetStatus();
    ASSERT_EQ(expected_status_2, board_status) << expected_status_2 << " != " << board_status;

    a0.SetAction(base::Action::RIGHT);
    a1.SetAction(base::Action::UP);

    round_done = board.PerformTurn();

    ASSERT_FALSE(round_done);

    base::Status<3,3> expected_status_3("xx0xx.1..");
    board_status = board.GetStatus();
    ASSERT_EQ(expected_status_3, board_status) << expected_status_3 << " != " << board_status;

    a1.SetAction(base::Action::RIGHT);

    round_done = board.PerformTurn();

    ASSERT_TRUE(round_done);

    ASSERT_FALSE(board.Agent0Alive());
    ASSERT_TRUE(board.Agent1Alive());
}

TEST(GridboardTests, BlockedSquare){
    base::Agent<3,3> a0;
    base::Agent<3,3> a1;

    base::GridBoard<3,3> board{};

    a0.Connect(board.GetConnection0());
    a1.Connect(board.GetConnection1());

    board.Reset({1,1}, {0,0});

    a0.SetAction(base::Action::LEFT);
    a1.SetAction(base::Action::RIGHT);

    bool round_done = board.PerformTurn();
    ASSERT_FALSE(round_done);

    a0.SetAction(base::Action::DOWN);
    a1.SetAction(base::Action::DOWN);

    round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);
    ASSERT_TRUE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}

TEST(GridboardTests, AgentCrashing){
    base::Agent<3,3> a0;
    base::Agent<3,3> a1;

    base::GridBoard<3,3> board{};

    a0.Connect(board.GetConnection0());
    a1.Connect(board.GetConnection1());

    board.Reset({1,1}, {0,1});

    a0.SetAction(base::Action::LEFT);
    a1.SetAction(base::Action::RIGHT);

    bool round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);
    ASSERT_FALSE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}

TEST(GridboardTests, AgentCrashing2){
    base::Agent<3,3> a0;
    base::Agent<3,3> a1;

    base::GridBoard<3,3> board{};

    a0.Connect(board.GetConnection0());
    a1.Connect(board.GetConnection1());

    board.Reset({2,1}, {0,1});

    a0.SetAction(base::Action::LEFT);
    a1.SetAction(base::Action::RIGHT);

    bool round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);
    ASSERT_FALSE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}
