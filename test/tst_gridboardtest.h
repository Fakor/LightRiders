#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../static/GridBoard.h"
#include "../static/Position.h"

using namespace testing;

TEST(GridboardTests, GridBoardConstructor)
{
    base::GridBoard<2,2> board({0,1}, {1,0});

    ASSERT_EQ('.', board.GetSquareValue({0,0}));
    ASSERT_EQ('0', board.GetSquareValue({0,1}));
    ASSERT_EQ('1', board.GetSquareValue({1,0}));
    ASSERT_EQ('.', board.GetSquareValue({1,1}));

    std::string expected_position = ".,0,1,.";
}
