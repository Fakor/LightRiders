#ifndef TST_ENGINETEST_H
#define TST_ENGINETEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <stdexcept>

#include "../static/standard_definitions.h"
#include "../static/engine.h"
#include "../static/simple_agents.h"
#include "../static/utility.h"

using namespace testing;

TEST(StandardEngineTest, StartPositions){
    standard::SameCommandAgent_S a0(base::Action::UP);
    standard::SameCommandAgent_S a1(base::Action::DOWN);

    standard::Engine engine(&a0, &a1);

    engine.Reset({3,5});

    ASSERT_EQ(base::Position(3,5), a0.GetPosition());
    ASSERT_EQ(base::Position(12,5), a1.GetPosition());
}

TEST(StandardEngineTest, BadStartPositions){
    standard::SameCommandAgent_S a0(base::Action::UP);
    standard::SameCommandAgent_S a1(base::Action::DOWN);

    standard::Engine engine(&a0, &a1);

    ASSERT_THROW(engine.Reset({0,5}), std::invalid_argument);
    ASSERT_THROW(engine.Reset({7,5}), std::invalid_argument);
    ASSERT_THROW(engine.Reset({6,0}), std::invalid_argument);
    ASSERT_THROW(engine.Reset({6,15}), std::invalid_argument);
}

TEST(StandardEngineTest, PerformTurn){
    standard::SameCommandAgent_S a0(base::Action::UP);
    standard::SameCommandAgent_S a1(base::Action::DOWN);

    standard::Engine engine(&a0, &a1);

    engine.Reset({3,5});

    engine.PerformTurn();

    ASSERT_EQ(base::Position(3,4), a0.GetPosition());
    ASSERT_EQ(base::Position(12,6), a1.GetPosition());
}

TEST(StandardEngineTest, PerformRound){
    standard::SameCommandAgent_S a0(base::Action::LEFT);
    standard::SafeClockwiseBias_S a1(base::Action::DOWN);

    standard::Engine engine(&a0, &a1);

    engine.Reset({3,5});

    int turns = engine.PerformRound();

    ASSERT_EQ(4, turns);
    ASSERT_EQ(engine.A0Wins(), 0);
    ASSERT_EQ(engine.A1Wins(), 1);

    engine.Reset({2,3});

    standard::Status_S expected_status;

    expected_status.SetPosition({2,3}, '0');
    expected_status.SetPosition({13,3}, '1');

    ASSERT_EQ(expected_status, engine.GetStatus());
}


#endif // TST_ENGINETEST_H
