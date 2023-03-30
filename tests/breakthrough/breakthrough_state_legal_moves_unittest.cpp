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

TEST(breakthrough_state_legal_moves_unittest, GetLegalMoves_StartingPosition) {
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {X, X, X, X, X, X},
        {X, X, X, X, X, X},
        {A, A, A, A, A, A},
        {A, A, A, A, A, A},
        {O, O, O, O, O, O},
        {O, O, O, O, O, O}
    };
    auto s = BreakthroughState(position, 12, 12);

    // Check player 1 legal moves
    BreakthroughMove legalMovesP1[BreakthroughState::MAX_MOVES];
    ASSERT_EQ(s.GetLegalMoves(P1, legalMovesP1), 16);

    std::vector<BreakthroughMove> expectedMovesP1 =
    {
        BreakthroughMove(P1, 1, 0, 2, 0, false),
        BreakthroughMove(P1, 1, 0, 2, 1, false),
        BreakthroughMove(P1, 1, 1, 2, 0, false),
        BreakthroughMove(P1, 1, 1, 2, 1, false),
        BreakthroughMove(P1, 1, 1, 2, 2, false),
        BreakthroughMove(P1, 1, 2, 2, 1, false),
        BreakthroughMove(P1, 1, 2, 2, 2, false),
        BreakthroughMove(P1, 1, 2, 2, 3, false),
        BreakthroughMove(P1, 1, 3, 2, 2, false),
        BreakthroughMove(P1, 1, 3, 2, 3, false),
        BreakthroughMove(P1, 1, 3, 2, 4, false),
        BreakthroughMove(P1, 1, 4, 2, 3, false),
        BreakthroughMove(P1, 1, 4, 2, 4, false),
        BreakthroughMove(P1, 1, 4, 2, 5, false),
        BreakthroughMove(P1, 1, 5, 2, 4, false),
        BreakthroughMove(P1, 1, 5, 2, 5, false),
    };
    ASSERT_EQ(expectedMovesP1.size(), 16);

    for (auto& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + 16, move) != legalMovesP1 + 16);
    }

    // Check player 2 legal moves
    BreakthroughMove legalMovesP2[BreakthroughState::MAX_MOVES];
    ASSERT_EQ(s.GetLegalMoves(P2, legalMovesP2), 16);

    std::vector<BreakthroughMove> expectedMovesP2 =
    {
        BreakthroughMove(P2, 4, 0, 3, 0, false),
        BreakthroughMove(P2, 4, 0, 3, 1, false),
        BreakthroughMove(P2, 4, 1, 3, 0, false),
        BreakthroughMove(P2, 4, 1, 3, 1, false),
        BreakthroughMove(P2, 4, 1, 3, 2, false),
        BreakthroughMove(P2, 4, 2, 3, 1, false),
        BreakthroughMove(P2, 4, 2, 3, 2, false),
        BreakthroughMove(P2, 4, 2, 3, 3, false),
        BreakthroughMove(P2, 4, 3, 3, 2, false),
        BreakthroughMove(P2, 4, 3, 3, 3, false),
        BreakthroughMove(P2, 4, 3, 3, 4, false),
        BreakthroughMove(P2, 4, 4, 3, 3, false),
        BreakthroughMove(P2, 4, 4, 3, 4, false),
        BreakthroughMove(P2, 4, 4, 3, 5, false),
        BreakthroughMove(P2, 4, 5, 3, 4, false),
        BreakthroughMove(P2, 4, 5, 3, 5, false),
    };
    ASSERT_EQ(expectedMovesP2.size(), 16);

    for (auto& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + 16, move) != legalMovesP2 + 16);
    }
}

TEST(breakthrough_state_legal_moves_unittest, GetLegalMoves_WithCaptures) {
    const Common::Piece position[BreakthroughState::ROWS][BreakthroughState::COLS] =
    {
        {A, X, A, A, A, A},
        {A, A, A, X, X, A},
        {X, A, O, A, O, X},
        {X, A, A, O, A, A},
        {A, O, O, A, O, A},
        {A, A, A, A, A, A}
    };
    auto s = BreakthroughState(position, 6, 6);

    // Check player 1's legal moves
    BreakthroughMove legalMovesP1[BreakthroughState::MAX_MOVES];
    ASSERT_EQ(s.GetLegalMoves(P1, legalMovesP1), 12);

    std::vector<BreakthroughMove> expectedMovesP1 =
    {
        BreakthroughMove(P1, 0, 1, 1, 0, false),
        BreakthroughMove(P1, 0, 1, 1, 1, false),
        BreakthroughMove(P1, 0, 1, 1, 2, false),
        BreakthroughMove(P1, 1, 3, 2, 2, true),
        BreakthroughMove(P1, 1, 3, 2, 3, false),
        BreakthroughMove(P1, 1, 3, 2, 4, true),
        BreakthroughMove(P1, 1, 4, 2, 3, false),
        BreakthroughMove(P1, 2, 0, 3, 1, false),
        BreakthroughMove(P1, 2, 5, 3, 4, false),
        BreakthroughMove(P1, 2, 5, 3, 5, false),
        BreakthroughMove(P1, 3, 0, 4, 0, false),
        BreakthroughMove(P1, 3, 0, 4, 1, true)
    };
    ASSERT_EQ(expectedMovesP1.size(), 12);

    for (auto& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + 12, move) != legalMovesP1 + 12);
    }

    // Check player 2's legal moves
    BreakthroughMove legalMovesP2[BreakthroughState::MAX_MOVES];
    ASSERT_EQ(s.GetLegalMoves(P2, legalMovesP2), 13);

    std::vector<BreakthroughMove> expectedMovesP2 =
    {
        BreakthroughMove(P2, 4, 1, 3, 0, true),
        BreakthroughMove(P2, 4, 1, 3, 1, false),
        BreakthroughMove(P2, 4, 1, 3, 2, false),
        BreakthroughMove(P2, 4, 2, 3, 1, false),
        BreakthroughMove(P2, 4, 2, 3, 2, false),
        BreakthroughMove(P2, 4, 4, 3, 4, false),
        BreakthroughMove(P2, 4, 4, 3, 5, false),
        BreakthroughMove(P2, 3, 3, 2, 3, false),
        BreakthroughMove(P2, 2, 2, 1, 1, false),
        BreakthroughMove(P2, 2, 2, 1, 2, false),
        BreakthroughMove(P2, 2, 2, 1, 3, true),
        BreakthroughMove(P2, 2, 4, 1, 3, true),
        BreakthroughMove(P2, 2, 4, 1, 5, false),
    };
    ASSERT_EQ(expectedMovesP2.size(), 13);

    for (auto& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + 13, move) != legalMovesP2 + 13);
    }
}

}