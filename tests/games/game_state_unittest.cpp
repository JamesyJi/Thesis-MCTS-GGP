#include <gtest/gtest.h>
#include "game_state.h"

TEST(game_state_unittest, GameStateUpdatesBranchingFactorsCorrectly)
{
    auto s = Games::GameState();

    s.UpdateAvgBranchingFactor(5);
    s.UpdateAvgBranchingFactor(10);

    s.NextTurn();
    s.UpdateAvgBranchingFactor(10);
    s.UpdateAvgBranchingFactor(15);

    s.NextTurn();
    s.UpdateAvgBranchingFactor(12);
    s.UpdateAvgBranchingFactor(13);
    s.UpdateAvgBranchingFactor(14);

    EXPECT_EQ(s.GetAvgBranchingFactorAtTurn(1), 7.5);
    EXPECT_EQ(s.GetAvgBranchingFactorAtTurn(2), 12.5);
    EXPECT_EQ(s.GetAvgBranchingFactorAtTurn(3), 13);
}