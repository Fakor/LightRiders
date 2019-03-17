#ifndef TST_ENGINETEST_H
#define TST_ENGINETEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../static/standard_definitions.h"
#include "../static/engine.h"
#include "../static/simple_agents.h"
#include "../static/utility.h"

using namespace testing;

TEST(StandardEngineTest, StartPositions){
    standard::SameCommandAgent_S a0(base::Action::UP);
    standard::SameCommandAgent_S a1(base::Action::DOWN);

    standard::Engine engine(&a0, &a1);

    engine.SetLeftSideStartPosition({3,5});

    ASSERT_EQ(base::Position(3,5), a0.GetPosition());
    ASSERT_EQ(base::Position(12,5), a1.GetPosition());
}


#endif // TST_ENGINETEST_H
