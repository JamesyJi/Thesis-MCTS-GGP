#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "pieces.h"
#include "connect4_state.h"

#include "model.h"
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

    auto expectedMove1 = Connect4::Connect4Move(P2, 5, 2);
    ASSERT_EQ(expectedMove1, m.SimulationPolicy(s, P2));

    // s.SimulateMove(expectedMove1);

    // MoveT expectedMove2 = ???
    // ASSERT_EQ(expectedmove2, m.SimulationPolicy(s, P2));


}

}