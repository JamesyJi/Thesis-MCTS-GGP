#include <gtest/gtest.h>
#include "pieces.h"
#include "othello_state.h"
#include "test_defines.h"

namespace Othello
{

TEST(othello_evaluate_state_unittest, StartingPosition_IsOngoing)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, X, O, A, A, A},
        {A, A, A, O, X, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
    };
    auto s = OthelloState(position, 0, 2, 2);
    
    auto noMove = OthelloMove();
    ASSERT_EQ(s.EvaluateState(noMove), ONGOING);
}

TEST(othello_evaluate_state_unittest, UnfinishedGame_IsOngoing)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, O, A, A, A, A},
        {A, A, X, O, X, O, A, A},
        {A, A, A, O, O, O, A, A},
        {A, A, X, O, X, X, X, A},
        {A, A, X, X, O, X, X, A},
        {A, A, X, O, O, O, A, A},
        {A, A, A, A, O, A, A, A},
    };
    auto s = OthelloState(position, 0, 11, 12);

    auto lastMove = OthelloMove(P1, 6, 2, {{NW, 4, 4}});
    ASSERT_EQ(s.EvaluateState(lastMove), ONGOING);

    const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
    {
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {O, O, O, O, O, O, O, A},
    };
    auto s1 = OthelloState(position, 0, 56, 7);

    std::vector<CaptureInfo> captureInfos = {{{W, 7, 0}}};
    auto lastMove1 = OthelloMove(P2, 7, 6, captureInfos);
    ASSERT_EQ(s.EvaluateState(lastMove1), ONGOING);
}

TEST(othello_evaluate_state_unittest, SingleSkippedTurn_IsOngoing)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, O, A, A, A, A},
        {A, A, O, X, X, O, A, A},
        {A, O, A, O, O, X, X, A},
        {A, X, O, O, O, O, X, A},
        {A, A, O, X, O, X, X, A},
        {A, A, X, O, O, O, A, A},
        {A, A, A, A, O, A, A, A},
    };
    auto s = OthelloState(position, 1, 10, 16);
    auto noMove = OthelloMove();
    ASSERT_EQ(s.EvaluateState(noMove), ONGOING);
}

TEST(othello_evaluate_state_unittest, DoubleSkippedTurn_CountWinner)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, O, A, A, A, A},
        {A, A, O, X, X, O, A, A},
        {A, O, A, O, O, X, X, A},
        {A, X, O, O, O, O, X, A},
        {A, A, O, X, O, X, X, A},
        {A, A, X, O, O, O, A, A},
        {A, A, A, A, O, A, A, A},
    };
    auto s = OthelloState(position, 2, 10, 16);
    auto noMove = OthelloMove();
    ASSERT_EQ(s.EvaluateState(noMove), P2_WIN);
}

TEST(othello_evaluate_state_unittest, FinishedGame_CountWinner_Draw)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {X, O, O, O, O, O, O, O},
        {X, X, X, O, X, X, X, X},
        {X, O, O, X, X, O, O, O},
        {X, O, O, O, O, X, X, X},
        {O, X, O, O, O, O, X, X},
        {X, X, O, X, O, X, X, X},
        {O, O, X, O, O, O, X, X},
        {X, X, X, X, X, X, X, X},
    };
    auto s = OthelloState(position, 0, 32, 32);
    std::vector<CaptureInfo> captureInfos = {{{W, 7, 0}, {NW, 5, 5}, {N, 5, 7}}};
    auto lastMove = OthelloMove(P1, 7, 7, captureInfos);
    ASSERT_EQ(s.EvaluateState(lastMove), DRAW);
}

}
