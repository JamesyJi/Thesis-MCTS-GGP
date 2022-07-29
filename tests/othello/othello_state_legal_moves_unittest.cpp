#include <gtest/gtest.h>
#include "pieces.h"
#include "othello_state.h"
#include "test_defines.h"

namespace Othello
{

TEST(othello_legal_moves_unittest, NoLegalMoves)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, O, O, A, A, A},
        {A, A, A, O, O, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
    };
    auto s = OthelloState(position, 0);
    
    auto noMove = OthelloMove();

    OthelloMove legalMoves[OthelloState::MAX_MOVES];
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove());
    ASSERT_EQ(s.GetLegalMoves(P2, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove());
}

TEST(othello_legal_moves_unittest, SingleCaptureDiagonals)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, X, A, A, A, A},
        {A, A, A, A, O, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture NW
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{NW, 3, 3}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 5, 5, captureInfos));

    // O can can capture SE
    ASSERT_EQ(s.GetLegalMoves(P2, legalMoves), 1);
    captureInfos = {{{SE, 4, 4}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P2, 2, 2, captureInfos));

    const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
    {
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, O, X},
        {X, X, X, X, X, O, X, X},
        {X, X, X, X, O, X, X, X},
        {X, X, X, O, X, X, X, X},
        {X, X, O, X, X, X, X, X},
        {X, O, X, X, X, X, X, X},
        {A, X, X, X, X, X, X, X},
    };
    auto s1 = OthelloState(position1, 0);

    // X can capture NE
    ASSERT_EQ(s1.GetLegalMoves(P1, legalMoves), 1);
    captureInfos = {{{NE, 0, 7}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 7, 0, captureInfos));

    const Common::Piece position2[OthelloState::ROWS][OthelloState::COLS] =
    {
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, O, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, A, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
        {X, X, X, X, X, X, X, X},
    };
    auto s2 = OthelloState(position2, 0);

    // O can capture NE
    ASSERT_EQ(s2.GetLegalMoves(P2, legalMoves), 1);
    captureInfos = {{{NE, 2, 4}}};
    ASSERT_EQ(s2.GetLegalMoves(P2, legalMoves), 1);    
}

TEST(othello_legal_moves_unittest, SingleCaptureE)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, X, X, X, O, O, O},
        {A, A, A, A, A, A, A, A},
        {A, A, O, A, O, O, X, O},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture E
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{E, 5, 6}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 5, 3, captureInfos));

    // O can capture E
    ASSERT_EQ(s.GetLegalMoves(P2, legalMoves), 1);
    captureInfos = {{{E, 3, 5}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P2, 3, 1, captureInfos));
}

TEST(othello_legal_moves_unittest, SingleCaptureSE)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, O, A, A, A, A},
        {A, A, A, A, O, A, A, A},
        {A, A, A, A, A, X, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture SE
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{SE, 5, 5}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 2, 2, captureInfos));
}

TEST(othello_legal_moves_unittest, SingleCaptureS)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, X, A, A, A},
        {A, A, A, A, X, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, O, A, A, A},
        {A, A, A, O, O, A, A, A},
        {A, A, A, A, O, A, A, A},
        {A, A, A, A, X, A, A, A},
        {A, A, A, A, X, A, A, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture S
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{S, 6, 4}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 2, 4, captureInfos));
}

TEST(othello_legal_moves_unittest, SingleCaptureSW)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, X},
        {A, A, A, A, A, A, A, X},
        {A, A, A, A, A, A, A, X},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, O, O, A},
        {A, A, A, A, O, A, A, A},
        {A, A, A, X, A, A, A, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture SW
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{SW, 7, 3}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 4, 6, captureInfos));
}

TEST(othello_legal_moves_unittest, SingleCaptureW)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {X, O, O, O, A, X, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
        {A, A, A, A, A, A, A, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture W
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{W, 4, 0}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 4, 4, captureInfos));
}

TEST(othello_legal_moves_unittest, MultipleCaptures1)
{
    const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
    {
        {A, A, A, A, A, A, A, A},
        {A, A, X, O, X, X, A, A},
        {A, O, X, X, O, X, A, A},
        {A, O, X, O, X, O, A, A},
        {X, O, O, O, X, X, A, A},
        {X, X, X, X, O, O, X, A},
        {O, O, A, X, O, X, X, A},
        {A, A, A, A, O, A, X, A},
    };
    auto s = OthelloState(position, 0);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture W
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    std::vector<CaptureInfo> captureInfos = {{{W, 4, 0}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 4, 4, captureInfos));
}



}
