#include <gtest/gtest.h>
#include <algorithm>

#include "pieces.h"
#include "catchthelion_state.h"
#include "test_defines.h"

namespace CatchTheLion
{

TEST(catchthelion_unittest, RealScenario1_ReasonUnknown_LikelyNoLegalMoves)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, N_A, N_A},
        {N_A, C_O, L_X},
        {N_A, G_X, N_A},
        {N_A, N_A, L_O},
    };
    auto s = CatchTheLionState(position, {0, 1, 0}, {1, 1, 0});
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 17);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 0, 0, 0, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 0, 0, 1, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 1, 2, 0, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 1, 2, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 1, 2, 1, 1, Common::CatchTheLionPieceType::CHICK),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 1, 2, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 1, 1, Common::CatchTheLionPieceType::CHICK),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 3, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 0, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 1, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 3, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 3, 1)
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 18);

    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 1, 1, 0, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 3, 2, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 3, 2, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 3, 2, 2, 1, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 0, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 0, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 1, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 3, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 0, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 0, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 1, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 1)
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }

    // Lets simulate some moves to determine that capturing the lion is a win
    auto move1 = CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 1, 2, 1, 1, Common::CatchTheLionPieceType::CHICK);
    s.SimulateMove(move1);
    ASSERT_EQ(s.EvaluateState(move1), ONGOING);

    // P2 Lion Captures Giraffe
    auto move2 = CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 3, 2, 2, 1, Common::CatchTheLionPieceType::GIRAFFE);
    s.SimulateMove(move2);
    ASSERT_EQ(s.EvaluateState(move2), ONGOING);

    // Now P1 can capture P2's lion
    auto move3 = CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 1, 1, 2, 1, Common::CatchTheLionPieceType::LION);
    s.SimulateMove(move3);
    ASSERT_EQ(s.EvaluateState(move3), P1_WIN);
}

}