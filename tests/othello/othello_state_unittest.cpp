#include <gtest/gtest.h>
#include "pieces.h"
#include "othello_state.h"

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)
#define E Common::Piece()

namespace Othello
{


TEST(othello_state_unittest, EvaluateOngoing) {
    const Common::Piece position[Othello::OthelloState::ROWS][Othello::OthelloState::COLS] =
    {
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, X, E, E, E},
        {E, E, E, X, O, E, E, E},
        {E, E, E, O, X, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E}
    };
    auto s = Othello::OthelloState(position);

    EXPECT_EQ(s.EvaluateState(OthelloMove(Common::Player::PLAYER1, 2, 4, Direction::S, 4, 4)), Common::Result::ONGOING);

}

TEST(othello_state_unnitest, MakeMoveFlipsPieces) {
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, X, O, E, E, E},
        {E, E, E, O, X, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E}
    };
    auto s = Othello::OthelloState(position);

    auto newS = s.MakeMove(OthelloMove(Common::Player::PLAYER1, 2, 4, Direction::S, 4, 4));
    const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
    {
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, X, E, E, E},
        {E, E, E, X, X, E, E, E},
        {E, E, E, O, X, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E, E}
    };
    auto expectedS = Othello::OthelloState(position1);

    EXPECT_TRUE(newS == expectedS);

}

}