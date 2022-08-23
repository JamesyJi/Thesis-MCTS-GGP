#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "pieces.h"
#include "connect4_state.h"

#include "minimax/minimax_rollout.h"
#include "strategy.h"

#include "test_defines.h"

// Call SimulationPolicy on a state and check the returned move
// Can mock the actual state passed in to constructor

// TODO: Mock GameState

// TODO Why do we need to #include test_defines.h at the end?

namespace
{

using Connect4GameT = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;

class MinimaxRolloutSimulationPolicyUnitTest : public ::testing::Test
{
protected:
    Connect4::Connect4State mState;
    Games::GameState mGameState;
};

TEST_F(MinimaxRolloutSimulationPolicyUnitTest, AvoidsLosingMove_Depth2)
{
    auto m = Models::Minimax::MinimaxRollout<Connect4GameT, Strategy::FixedDepth2>(mState, mGameState);

    const Common::Piece position[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] = 
    {
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, O, A, A},
        {A, A, A, X, X, X, O}
    };
    auto s = Connect4::Connect4State(position);

    auto expectedMove = Connect4::Connect4Move(P2, 5, 2);
    for (int i = 0; i < 20; ++i) ASSERT_EQ(expectedMove, m.SimulationPolicy(s, P2));    
}

TEST_F(MinimaxRolloutSimulationPolicyUnitTest, SelectsWinningSequence_Depth4)
{
    auto m = Models::Minimax::MinimaxRollout<Connect4GameT, Strategy::FixedDepth4>(mState, mGameState);

    const Common::Piece position[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] = 
    {
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, O, O, A},
        {A, A, A, A, X, X, A}
    };
    auto s = Connect4::Connect4State(position);

    auto expectedMove1 = Connect4::Connect4Move(P1, 5, 3);
    for (int i = 0; i < 20; ++i) ASSERT_EQ(expectedMove1, m.SimulationPolicy(s, P1));

    s.SimulateMove(expectedMove1);
    s.SimulateMove(Connect4::Connect4Move(P2, 5, 2));

    auto expectedMove2 = Connect4::Connect4Move(P1, 5, 6);
    for (int i = 0; i < 20; ++i) ASSERT_EQ(expectedMove2, m.SimulationPolicy(s, P1));
}

TEST_F(MinimaxRolloutSimulationPolicyUnitTest, DoesNotAvoidLosingMove_Depth3)
{
    auto m = Models::Minimax::MinimaxRollout<Connect4GameT, Strategy::FixedDepth2>(mState, mGameState);

    const Common::Piece position[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] = 
    {
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, A, A, O, A, A},
        {A, A, A, A, X, X, A}
    };
    auto s = Connect4::Connect4State(position);

    auto correctMove = Connect4::Connect4Move(P2, 5, 3);
    int correctMoveCount = 0;
    for (int i = 0; i < 50; ++i)
    {
        if (correctMove == m.SimulationPolicy(s, P2)) correctMoveCount++;
    }
    ASSERT_TRUE(correctMoveCount < 50);
}

}