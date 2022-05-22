#include <gtest/gtest.h>
#include "pieces.h"
#include "connect4_state.h"
#include "connect4_move.h"

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)
#define E Common::Piece()

TEST(state_unittest, EvaluateRowWin) {
    const Common::Piece position[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] =
    {
        {E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E},
        {E, E, O, E, E, E, E},
        {E, E, X, E, E, X, E},
        {E, E, X, O, X, X, E},
        {E, E, X, O, O, O, O},
    };

    auto s = Connect4::Connect4State(position);

    EXPECT_EQ(s.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 5, 6)), Common::Result::PLAYER2_WIN);
}

TEST(state_unittest, EvaluateBottomRightTopLeftDiagonalWin) {
    const Common::Piece position1[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] =
    {
        {E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E},
        {E, E, X, E, E, E, E},
        {E, E, O, X, X, E, E},
        {E, O, O, O, X, E, E},
        {E, X, O, X, O, X, E},
    };
    auto s1 = Connect4::Connect4State(position1);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 5, 5)), Common::Result::PLAYER1_WIN);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 4, 4)), Common::Result::PLAYER1_WIN);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 3, 3)), Common::Result::PLAYER1_WIN);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 2, 2)), Common::Result::PLAYER1_WIN);

    const Common::Piece position2[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] =
    {
        {E, E, E, E, E, E, E},
        {E, E, E, E, E, E, E},
        {E, O, E, E, E, E, E},
        {E, X, O, X, O, X, E},
        {E, O, O, O, X, X, E},
        {E, X, X, O, O, X, X},
    };
    auto s2 = Connect4::Connect4State(position1);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 1, 2)), Common::Result::PLAYER2_WIN);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 2, 3)), Common::Result::PLAYER2_WIN);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 3, 4)), Common::Result::PLAYER2_WIN);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 4, 5)), Common::Result::PLAYER2_WIN);

}