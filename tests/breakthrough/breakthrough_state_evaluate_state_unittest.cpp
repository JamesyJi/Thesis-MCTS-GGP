#include <gtest/gtest.h>
#include "pieces.h"
#include "breakthrough_state.h"
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

TEST(breakthrough_evaluate_state_unittest, Player1LastRowWin)
{
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {X, X, X, X, X, X},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {O, O, O, X, O, O},
    };
    auto s = BreakthroughState(position, 7, 5);

    auto lastMoveNoCapture = BreakthroughMove(P1, 4, 3, 5, 3, false);
    ASSERT_EQ(s.EvaluateState(lastMoveNoCapture), P1_WIN);

    auto lastMoveCapture = BreakthroughMove(P1, 4, 3, 5, 3, true);
    ASSERT_EQ(s.EvaluateState(lastMoveCapture), P1_WIN);
}

TEST(breakthrough_evaluate_state_unittest, Player2LastRowWin)
{
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {X, X, X, X, X, O},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {O, O, O, O, O, O},
    };
    auto s = BreakthroughState(position, 5, 7);

    auto lastMoveNoCapture = BreakthroughMove(P2, 1, 5, 0, 5, false);
    ASSERT_EQ(s.EvaluateState(lastMoveNoCapture), P2_WIN);

    auto lastMoveCapture = BreakthroughMove(P2, 1, 5, 0, 5, true);
    ASSERT_EQ(s.EvaluateState(lastMoveCapture), P2_WIN);
}

TEST(breakthrough_evaluate_state_unittest, Player1CaptureWin)
{
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {X, X, X, X, X, X},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {A, A, A, X, A, A},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
    };
    auto s = BreakthroughState(position, 7, 0);

    auto lastMove = BreakthroughMove(P1, 2, 4, 3, 3, true);
    ASSERT_EQ(s.EvaluateState(lastMove), P1_WIN);
}

TEST(breakthrough_evaluate_state_unittest, Player2CaptureWin)
{
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {A, A, A, A, A, A},
        {A, A, O, A, A, A},
        {A, A, A, A, A, A},
        {A, A, A, O, A, A},
        {A, A, O, A, A, A},
        {A, O, A, A, A, A},
    };
    auto s = BreakthroughState(position, 0, 4);

    auto lastMove = BreakthroughMove(P2, 2, 3, 1, 2, true);
    ASSERT_EQ(s.EvaluateState(lastMove), P2_WIN);
}

TEST(breakthrough_evaluate_state_unittest, OnGoing)
{
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {A, A, A, A, A, A},
        {A, O, A, A, O, A},
        {A, O, A, X, A, A},
        {A, A, A, X, A, A},
        {A, X, A, A, O, A},
        {A, A, A, A, A, A},
    };
    auto s = BreakthroughState(position, 3, 4);

    auto lastMoveNonCapture = BreakthroughMove(P1, 1, 3, 2, 3, false);
    ASSERT_EQ(s.EvaluateState(lastMoveNonCapture), ONGOING);

    auto lastMoveCapture = BreakthroughMove(P1, 1, 3, 2, 3, true);
    ASSERT_EQ(s.EvaluateState(lastMoveCapture), ONGOING);

    const Common::Piece position1[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {A, A, A, A, A, X},
        {A, A, A, X, X, X},
        {X, X, A, A, O, A},
        {A, A, O, O, A, A},
        {O, A, A, A, A, A},
        {A, A, A, A, A, A},
    };
    auto s1 = BreakthroughState(position1, 6, 4);
    auto lastMoveNonCapture1 = BreakthroughMove(P2, 3, 5, 2, 4, false);
    ASSERT_EQ(s.EvaluateState(lastMoveNonCapture1), ONGOING);

    auto lastMoveCapture1 = BreakthroughMove(P2, 3, 5, 2, 4, true);
    ASSERT_EQ(s.EvaluateState(lastMoveCapture1), ONGOING);
}

}