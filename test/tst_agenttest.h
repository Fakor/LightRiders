#ifndef TST_AGENTTEST_H
#define TST_AGENTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <../static/status.h>
#include <../static/utility.h>
#include <../static/GridBoard.h>
#include <../static/simple_agents.h>

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

#endif // TST_AGENTTEST_H
