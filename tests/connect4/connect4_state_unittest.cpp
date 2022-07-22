#include <gtest/gtest.h>
#include "pieces.h"
#include "connect4_state.h"

#include "test_game_defines.h"

TEST(state_unittest, EvaluateRowWin) {
    const Common::Piece position[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] =
    {
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, O, A, A, A, A},
        {A, A, X, A, A, X, A},
        {A, A, X, O, X, X, A},
        {A, A, X, O, O, O, O},
    };

    auto s = Connect4::Connect4State(position);

    EXPECT_EQ(s.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 5, 6)), Common::Result::PLAYER2_WIN);
}

TEST(state_unittest, EvaluateBottomRightTopLeftDiagonalWin) {
    const Common::Piece position1[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] =
    {
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, A, X, A, A, A, A},
        {A, A, O, X, X, A, A},
        {A, O, O, O, X, A, A},
        {A, X, O, X, O, X, A},
    };
    auto s1 = Connect4::Connect4State(position1);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 5, 5)), Common::Result::PLAYER1_WIN);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 4, 4)), Common::Result::PLAYER1_WIN);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 3, 3)), Common::Result::PLAYER1_WIN);
    EXPECT_EQ(s1.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER1, 2, 2)), Common::Result::PLAYER1_WIN);

    const Common::Piece position2[Connect4::Connect4State::ROWS][Connect4::Connect4State::COLS] =
    {
        {A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A},
        {A, O, A, A, A, A, A},
        {A, X, O, X, O, X, A},
        {A, O, O, O, X, X, A},
        {A, X, X, O, O, X, X},
    };
    
    auto s2 = Connect4::Connect4State(position2);    
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 2, 1)), Common::Result::PLAYER2_WIN);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 3, 2)), Common::Result::PLAYER2_WIN);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 4, 3)), Common::Result::PLAYER2_WIN);
    EXPECT_EQ(s2.EvaluateState(Connect4::Connect4Move(Common::Player::PLAYER2, 5, 4)), Common::Result::PLAYER2_WIN);

}