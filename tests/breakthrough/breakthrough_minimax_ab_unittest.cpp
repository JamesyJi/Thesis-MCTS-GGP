#include <gtest/gtest.h>
// #include "pieces.h"
// #include "breakthrough_state.h"
// #include "../test_defines.h"
// #include "model.h"

#define P0 Common::Player::PLAYER0
#define P1 Common::Player::PLAYER1
#define P2 Common::Player::PLAYER2
#define P1_WIN Common::Result::PLAYER1_WIN
#define P2_WIN Common::Result::PLAYER2_WIN
#define DRAW Common::Result::DRAW
#define ONGOING Common::Result::ONGOING

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)
#define A Common::Piece()

namespace Breakthrough
{

// class ModelFixture : public ::testing::Test
// {
// protected:
//     using MoveT = Breakthrough::BreakthroughMove;
//     using StateT = Breakthrough::BreakthroughState;
//     using GameT = Models::Traits<Breakthrough::BreakthroughState, Breakthrough::BreakthroughMove>;

//     void SetUp() override
//     {
//         // model = Models::Standard::Standard<GameT>();
//     }

//     // Model<Models::Standard, GameT> model;
// };


// TEST_F(breakthrough_minimax_ab_unittest, StartingPosition_NoTraps)
// {
//     const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
//     {
//         {X, X, X, X, X, X},
//         {X, X, X, X, X, X},
//         {A, A, A, A, A, A},
//         {A, A, A, A, A, A},
//         {O, O, O, O, O, O},
//         {O, O, O, O, O, O}
//     };
//     auto s = BreakthroughState(position, 12, 12);
// }

}