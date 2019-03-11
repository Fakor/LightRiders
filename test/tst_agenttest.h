#ifndef TST_AGENTTEST_H
#define TST_AGENTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <../static/status.h>
#include <../static/utility.h>

using namespace testing;

TEST(AgentTests, GetPosition){
    base::Status<3,3> status("...1...0.");

    ASSERT_EQ(base::Position(1,2), status.GetPosition('0'));
    ASSERT_EQ(base::Position(0,1), status.GetPosition('1'));
}

#endif // TST_AGENTTEST_H
