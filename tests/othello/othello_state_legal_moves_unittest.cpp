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
    auto s = OthelloState(position, 0, 0, 4);
    
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
    auto s = OthelloState(position, 0, 1, 1);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture NW
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 5, 5, {{NW, 3, 3}}));

    // O can can capture SE
    ASSERT_EQ(s.GetLegalMoves(P2, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P2, 2, 2, {{SE, 4, 4}}));

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
    auto s1 = OthelloState(position1, 0, 57, 6);

    // X can capture NE
    ASSERT_EQ(s1.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 7, 0, {{NE, 0, 7}}));

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
    auto s2 = OthelloState(position2, 0, 62, 1);

    // O can capture NE
    ASSERT_EQ(s2.GetLegalMoves(P2, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P2, 5, 1, {{NE, 2, 4}}));    
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
    auto s = OthelloState(position, 0, 4, 7);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture E
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 5, 3, {{E, 5, 6}}));

    // O can capture E
    ASSERT_EQ(s.GetLegalMoves(P2, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P2, 3, 1, {{E, 3, 5}}));
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
    auto s = OthelloState(position, 0, 1, 2);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture SE
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 2, 2, {{SE, 5, 5}}));
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
    auto s = OthelloState(position, 0, 4, 4);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture S
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 2, 4, {{S, 6, 4}}));
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
    auto s = OthelloState(position, 0, 4, 3);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture SW
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 4, 6, {{SW, 7, 3}}));
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
    auto s = OthelloState(position, 0, 2, 3);
    OthelloMove legalMoves[OthelloState::MAX_MOVES];

    // X can capture W
    ASSERT_EQ(s.GetLegalMoves(P1, legalMoves), 1);
    // std::vector<CaptureInfo> captureInfos = {{{W, 4, 0}}};
    ASSERT_EQ(legalMoves[0], OthelloMove(P1, 4, 4, {{W, 4, 0}}));
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
    auto s = OthelloState(position, 0, 20, 15);
    OthelloMove legalMovesP1[OthelloState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 12);

    std::vector<OthelloMove> expectedMovesP1 =
    {
        OthelloMove(P1, 0, 3, {{S, 2, 3}}),
        OthelloMove(P1, 0, 4, {{SW, 2, 2}}),
        OthelloMove(P1, 1, 0, {{SE, 3, 2}}),
        OthelloMove(P1, 1, 1, {{S, 5, 1}}),
        OthelloMove(P1, 2, 0, {{E, 2, 2}, {SE, 5, 3}}),
        OthelloMove(P1, 2, 6, {{SW, 4, 4}}),
        OthelloMove(P1, 3, 0, {{NE, 1, 2}, {E, 3, 2}, {SE, 5, 2}}),
        OthelloMove(P1, 3, 6, {{W, 3, 4}}),
        OthelloMove(P1, 7, 0, {{N, 5, 0}, {NE, 5, 2}}),
        OthelloMove(P1, 7, 1, {{N, 5, 1}}),
        OthelloMove(P1, 7, 2, {{NW, 5, 0}}),
        OthelloMove(P1, 7, 5, {{NW, 5, 3}})
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    OthelloMove legalMovesP2[OthelloState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 19);

    std::vector<OthelloMove> expectedMovesP2 =
    {
        OthelloMove(P2, 0, 2, {{S, 4, 2}}),
        OthelloMove(P2, 0, 3, {{SW, 2, 1}}),
        OthelloMove(P2, 0, 4, {{S, 2, 4}}),
        OthelloMove(P2, 0, 5, {{S, 3, 5}, {SW, 4, 1}}),
        OthelloMove(P2, 0, 6, {{SW, 2, 4}}),
        OthelloMove(P2, 1, 1, {{E, 1, 3}, {SE, 3, 3}}),
        OthelloMove(P2, 1, 6, {{SW, 4, 3}, {W, 1, 3}}),
        OthelloMove(P2, 2, 6, {{W, 2, 4}}),
        OthelloMove(P2, 3, 0, {{S, 6, 0}}),
        OthelloMove(P2, 3, 6, {{SW, 5, 4}}),
        OthelloMove(P2, 4, 6, {{W, 4, 3}}),
        OthelloMove(P2, 4, 7, {{SW, 7, 4}}),
        OthelloMove(P2, 5, 7, {{W, 5, 5}}),
        OthelloMove(P2, 6, 2, {{N, 4, 2}, {NE, 3, 5}, {E, 6, 4}}),
        OthelloMove(P2, 6, 7, {{W, 6, 4}}),
        OthelloMove(P2, 7, 2, {{NE, 5, 4}}),
        OthelloMove(P2, 7, 3, {{N, 4, 3}}),
        OthelloMove(P2, 7, 5, {{N, 5, 5}}),
        OthelloMove(P2, 7, 7, {{NW, 5, 5}})
    };

    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}



}
