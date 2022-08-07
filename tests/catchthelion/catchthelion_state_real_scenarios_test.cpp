#include <gtest/gtest.h>
#include <algorithm>

#include "pieces.h"
#include "catchthelion_state.h"
#include "test_defines.h"
#include "catchthelion_defines.h"

namespace CatchTheLion
{

TEST(catchthelion_real_scenarios_test, RealScenario1_ReasonUnknown_LikelyNoLegalMoves)
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
        CatchTheLionMove(P1, GIRAFFE, 0, 0, 0, 1),
        CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0),
        CatchTheLionMove(P1, LION, 1, 2, 0, 1),
        CatchTheLionMove(P1, LION, 1, 2, 0, 2),
        CatchTheLionMove(P1, LION, 1, 2, 1, 1, CHICK),
        CatchTheLionMove(P1, LION, 1, 2, 2, 2),
        CatchTheLionMove(P1, GIRAFFE, 2, 1, 1, 1, CHICK),
        CatchTheLionMove(P1, GIRAFFE, 2, 1, 2, 0),
        CatchTheLionMove(P1, GIRAFFE, 2, 1, 3, 1),
        CatchTheLionMove(P1, GIRAFFE, 2, 1, 2, 2),
        CatchTheLionMove(P1, ELEPHANT, 0, 1),
        CatchTheLionMove(P1, ELEPHANT, 0, 2),
        CatchTheLionMove(P1, ELEPHANT, 1, 0),
        CatchTheLionMove(P1, ELEPHANT, 2, 0),
        CatchTheLionMove(P1, ELEPHANT, 2, 2),
        CatchTheLionMove(P1, ELEPHANT, 3, 0),
        CatchTheLionMove(P1, ELEPHANT, 3, 1)
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
        CatchTheLionMove(P2, CHICK, 1, 1, 0, 1),
        CatchTheLionMove(P2, LION, 3, 2, 3, 1),
        CatchTheLionMove(P2, LION, 3, 2, 2, 2),
        CatchTheLionMove(P2, LION, 3, 2, 2, 1, GIRAFFE),
        CatchTheLionMove(P2, CHICK, 0, 1),
        CatchTheLionMove(P2, CHICK, 0, 2),
        CatchTheLionMove(P2, CHICK, 1, 0),
        CatchTheLionMove(P2, CHICK, 2, 0),
        CatchTheLionMove(P2, CHICK, 2, 2),
        CatchTheLionMove(P2, CHICK, 3, 0),
        CatchTheLionMove(P2, CHICK, 3, 1),
        CatchTheLionMove(P2, ELEPHANT, 0, 1),
        CatchTheLionMove(P2, ELEPHANT, 0, 2),
        CatchTheLionMove(P2, ELEPHANT, 1, 0),
        CatchTheLionMove(P2, ELEPHANT, 2, 0),
        CatchTheLionMove(P2, ELEPHANT, 2, 2),
        CatchTheLionMove(P2, ELEPHANT, 3, 0),
        CatchTheLionMove(P2, ELEPHANT, 3, 1)
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }

    // Lets simulate some moves to determine that capturing the lion is a win
    auto move1 = CatchTheLionMove(P1, LION, 1, 2, 1, 1, CHICK);
    s.SimulateMove(move1);
    ASSERT_EQ(s.EvaluateState(move1), ONGOING);

    // P2 Lion Captures Giraffe
    auto move2 = CatchTheLionMove(P2, LION, 3, 2, 2, 1, GIRAFFE);
    s.SimulateMove(move2);
    ASSERT_EQ(s.EvaluateState(move2), ONGOING);

    // Now P1 can capture P2's lion
    auto move3 = CatchTheLionMove(P1, LION, 1, 1, 2, 1, LION);
    s.SimulateMove(move3);
    ASSERT_EQ(s.EvaluateState(move3), P1_WIN);
}

TEST(catchthelion_real_scenarios_test, RealScenario2_LionBackRank_DidNotEndGame)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {N_A, C_X, N_A},
        {N_A, C_O, N_A},
        {E_O, L_O, G_O},
    };
    auto s = CatchTheLionState(position);
    
    auto move1 = CatchTheLionMove(P1, CHICK, 1, 1, 2, 1, CHICK);
    s.SimulateMove(move1);

    auto move2 = CatchTheLionMove(P2, ELEPHANT, 3, 0, 2, 1, CHICK);
    s.SimulateMove(move2);

    auto move3 = CatchTheLionMove(P1, CHICK, 1, 1);
    s.SimulateMove(move3);

    auto move4 = CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2);
    s.SimulateMove(move4);

    auto move5 = CatchTheLionMove(P1, CHICK, 1, 1, 2, 1, ELEPHANT);
    s.SimulateMove(move5);

    auto move6 = CatchTheLionMove(P2, GIRAFFE, 2, 2, 2, 1, CHICK);
    s.SimulateMove(move6);

    auto move7 = CatchTheLionMove(P1, ELEPHANT, 1, 2);
    s.SimulateMove(move7);

    auto move8 = CatchTheLionMove(P2, CHICK, 1, 1);
    s.SimulateMove(move8);

    auto move9 = CatchTheLionMove(P1, ELEPHANT, 0, 2, 1, 1, CHICK);
    s.SimulateMove(move9);

    auto move10 = CatchTheLionMove(P2, GIRAFFE, 2, 1, 1, 1, ELEPHANT);
    s.SimulateMove(move10);

    auto move11 = CatchTheLionMove(P1, LION, 0, 1, 1, 1, GIRAFFE);
    s.SimulateMove(move11);

    auto move12 = CatchTheLionMove(P2, CHICK, 2, 1);
    s.SimulateMove(move12);

    auto move13 = CatchTheLionMove(P1, LION, 1, 1, 1, 0);
    s.SimulateMove(move13);

    auto move14 = CatchTheLionMove(P2, ELEPHANT, 0, 1);
    s.SimulateMove(move14);

    auto move15 = CatchTheLionMove(P1, GIRAFFE, 0, 0, 0, 1, ELEPHANT);
    s.SimulateMove(move15);

    auto move16 = CatchTheLionMove(P2, LION, 3, 1, 2, 2);
    s.SimulateMove(move16);

    auto move17 = CatchTheLionMove(P1, LION, 1, 0, 2, 0);
    s.SimulateMove(move17);

    auto move18 = CatchTheLionMove(P2, CHICK, 2, 1, 1, 1);
    s.SimulateMove(move18);

    auto move19 = CatchTheLionMove(P1, CHICK, 1, 0);
    s.SimulateMove(move19);

    auto move20 = CatchTheLionMove(P2, LION, 2, 2, 2, 1);
    s.SimulateMove(move20);

    auto move21 = CatchTheLionMove(P1, ELEPHANT, 0, 0);
    s.SimulateMove(move21);

    auto move22 = CatchTheLionMove(P2, LION, 2, 1, 3, 1);
    s.SimulateMove(move22);

    auto move23 = CatchTheLionMove(P1, GIRAFFE, 0, 2);
    s.SimulateMove(move23);

    auto move24 = CatchTheLionMove(P2, LION, 3, 1, 3, 2);
    s.SimulateMove(move24);

    auto move25 = CatchTheLionMove(P1, ELEPHANT, 1, 2, 2, 1);
    s.SimulateMove(move25);

    auto move26 = CatchTheLionMove(P2, LION, 3, 2, 3, 1);
    s.SimulateMove(move26);

    auto move27 = CatchTheLionMove(P1, LION, 2, 0, 1, 1, CHICK);
    s.SimulateMove(move27);

    auto move28 = CatchTheLionMove(P2, LION, 3, 1, 2, 1, ELEPHANT);
    s.SimulateMove(move28);

    auto move29 = CatchTheLionMove(P1, LION, 1, 1, 2, 0);
    s.SimulateMove(move29);

    auto move30 = CatchTheLionMove(P2, ELEPHANT, 1, 2);
    s.SimulateMove(move30);

    auto move31 = CatchTheLionMove(P1, LION, 2, 0, 3, 0);
    s.SimulateMove(move31);

    // AT THIS POINT, PLAYER 1 SHOULD LOSE SINCE LION TO BACK RANK IN CHECK is a loss
    // Previous, we regarded it as ONGOING so if the opponent did not capture the lion,
    // it is possible for Player 1 to stalemate itself (illegal state in catch the lion)
    ASSERT_EQ(s.EvaluateState(move31), P2_WIN);

    // auto move32 = CatchTheLionMove(P2, LION, 2, 1, 2, 2);
    // s.SimulateMove(move32);

    // auto move33 = CatchTheLionMove(P1, GIRAFFE, 0, 2, 1, 2, ELEPHANT);
    // s.SimulateMove(move33);

    // auto move34 = CatchTheLionMove(P2, LION, 2, 2, 1, 1);
    // s.SimulateMove(move34);

    // auto move35 = CatchTheLionMove(P1, ELEPHANT, 3, 2);
    // s.SimulateMove(move35);

    // auto move36 = CatchTheLionMove(P2, LION, 1, 1, 2, 1);
    // s.SimulateMove(move36);

    // auto move37 = CatchTheLionMove(P1, GIRAFFE, 0, 1, 0, 2);
    // s.SimulateMove(move37);

    // auto move38 = CatchTheLionMove(P2, LION, 2, 1, 1, 1);
    // s.SimulateMove(move38);

    // auto move39 = CatchTheLionMove(P1, GIRAFFE, 0, 2, 0, 1);
    // s.SimulateMove(move39);

    // auto move40 = CatchTheLionMove(P2, LION, 1, 1, 2, 1);
    // s.SimulateMove(move40);

    // auto move41 = CatchTheLionMove(P1, GIRAFFE, 0, 1, 1, 1);
    // s.SimulateMove(move41);

    // auto move42 = CatchTheLionMove(P2, LION, 2, 1, 2, 2);
    // s.SimulateMove(move42);
}
}