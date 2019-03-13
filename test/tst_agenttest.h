#ifndef TST_AGENTTEST_H
#define TST_AGENTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <../static/status.h>
#include <../static/utility.h>
#include <../static/GridBoard.h>
#include <../static/simple_agents.h>
#include <../static/basic_help.h>

using namespace testing;

TEST(AgentTests, GetPosition){
    base::Status<3,3> status("...1...0.");

    ASSERT_EQ(base::Position(1,2), status.GetPosition('0'));
    ASSERT_EQ(base::Position(0,1), status.GetPosition('1'));
}

TEST(AgentTests, SameCommandAgent){
    agents::SameCommandAgent<3,3> a0(base::Action::UP);
    agents::SameCommandAgent<3,3> a1(base::Action::RIGHT);

    base::GridBoard<3,3> board;

    a0.Connect(board.GetConnection0());
    a1.Connect(board.GetConnection1());

    a0.ChooseAction();
    a1.ChooseAction();

    board.SetStartPosition({2,2}, {0,2});

    bool round_done = board.PerformTurn();

    ASSERT_FALSE(round_done);

    base::Status<3,3> expected_status(".....0x1x");
    ASSERT_EQ(expected_status, board.GetStatus()) << expected_status << " != " << board.GetStatus();

    round_done = board.PerformTurn();
    ASSERT_TRUE(round_done);

    ASSERT_TRUE(board.Agent0Alive());
    ASSERT_FALSE(board.Agent1Alive());
}

TEST(AgentTests, SquareSafe){
    base::Status<3,3> status("x..01..x.");

    ASSERT_TRUE(help::PositionSafe(status, {1,0}));
    ASSERT_TRUE(help::PositionSafe(status, {2,0}));
    ASSERT_TRUE(help::PositionSafe(status, {2,1}));
    ASSERT_TRUE(help::PositionSafe(status, {0,2}));
    ASSERT_TRUE(help::PositionSafe(status, {2,2}));

    ASSERT_FALSE(help::PositionSafe(status, {0,0}));
    ASSERT_FALSE(help::PositionSafe(status, {0,1}));
    ASSERT_FALSE(help::PositionSafe(status, {1,1}));
    ASSERT_FALSE(help::PositionSafe(status, {1,2}));

    ASSERT_FALSE(help::PositionSafe(status, {-1,0}));
    ASSERT_FALSE(help::PositionSafe(status, {1,-1}));
    ASSERT_FALSE(help::PositionSafe(status, {5,1}));
    ASSERT_FALSE(help::PositionSafe(status, {2,5}));
}

TEST(AgentTests, PositionInDirection){
    base::Position pos(1,1);

    ASSERT_EQ(base::Position(1,0), base::PositionInDirection(pos, base::Direction::UP));
    ASSERT_EQ(base::Position(1,2), base::PositionInDirection(pos, base::Direction::DOWN));
    ASSERT_EQ(base::Position(0,1), base::PositionInDirection(pos, base::Direction::LEFT));
    ASSERT_EQ(base::Position(2,1), base::PositionInDirection(pos, base::Direction::RIGHT));
}

#endif // TST_AGENTTEST_H
