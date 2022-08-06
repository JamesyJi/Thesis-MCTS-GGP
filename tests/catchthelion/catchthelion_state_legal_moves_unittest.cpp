#include <gtest/gtest.h>
#include <algorithm>

#include "pieces.h"
#include "catchthelion_state.h"
#include "test_defines.h"

namespace CatchTheLion
{

TEST(catchthelion_unittest, ChickLegalMovesNoDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, C_O, C_X},
        {C_O, C_X, N_A},
        {C_X, N_A, C_O},
        {C_O, N_A, C_X},
    };
    auto s = CatchTheLionState(position);
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 3);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 0, 2, 1, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 1, 1, 2, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 2, 0, 3, 0, Common::CatchTheLionPieceType::CHICK),
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 3);

    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 1, 0, 0, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 2, 2, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 3, 0, 2, 0, Common::CatchTheLionPieceType::CHICK)
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}

TEST(catchthelion_unittest, ElephantLegalMovesNoDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, E_O, E_X},
        {E_O, E_X, N_A},
        {N_A, E_X, E_O},
        {E_O, N_A, E_X},
    };
    auto s = CatchTheLionState(position);
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 6);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 1, 1, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 1, 1, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 1, 1, 2, 2, Common::CatchTheLionPieceType::ELEPHANT),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 1, 1, 0, Common::CatchTheLionPieceType::ELEPHANT),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 1, 1, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 1, 3, 0, Common::CatchTheLionPieceType::ELEPHANT)
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 5);

    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 0, 1, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 1, 0, 2, 1, Common::CatchTheLionPieceType::ELEPHANT),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 2, 1, 1, Common::CatchTheLionPieceType::ELEPHANT),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 2, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 0, 2, 1, Common::CatchTheLionPieceType::ELEPHANT),
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}

TEST(catchthelion_unittest, GiraffeLegalMovesNoDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, G_X, N_A},
        {G_O, G_O, N_A},
        {G_X, G_O, G_X},
        {G_O, N_A, G_X},
    };
    auto s = CatchTheLionState(position);
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 9);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 0, 1, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 0, 1, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 0, 1, 1, 1, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 0, 1, 0, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 0, 2, 1, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 0, 3, 0, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 2, 1, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 2, 2, 1, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 3, 2, 3, 1)
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 9);

    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 1, 0, 0, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 1, 0, 2, 0, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 1, 1, 0, 1, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 1, 1, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 2, 0, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 2, 2, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 2, 1, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 3, 0, 2, 0, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 3, 0, 3, 1)
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}

TEST(catchthelion_unittest, LionLegalMovesNoDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {L_O, L_X, N_A},
        {N_A, L_O, N_A},
        {L_X, L_O, N_A},
        {N_A, N_A, L_X},
    };
    auto s = CatchTheLionState(position);
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 13);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 0, 0, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 1, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 1, 1, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 1, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 2, 0, 1, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 2, 0, 1, 1, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 2, 0, 2, 1, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 2, 0, 3, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 2, 0, 3, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 3, 2, 2, 1, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 3, 2, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 3, 2, 3, 1)
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 15);

    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 0, 0, 0, 1, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 0, 0, 1, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 1, 1, 0, 1, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 1, 1, 0, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 1, 1, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 1, 1, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 1, 1, 2, 0, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 1, 1, 1, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 1, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 3, 2, Common::CatchTheLionPieceType::LION),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 3, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 2, 1, 2, 0, Common::CatchTheLionPieceType::LION),
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}

TEST(catchthelion_unittest, HenLegalMovesNoDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, H_X, H_O},
        {H_X, N_A, N_A},
        {N_A, H_O, H_O},
        {H_O, N_A, H_X},
    };
    auto s = CatchTheLionState(position);
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 10);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 0, 1, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 0, 1, 0, 2, Common::CatchTheLionPieceType::HEN),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 0, 1, 1, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 0, 1, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 1, 0, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 1, 0, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 1, 0, 2, 1, Common::CatchTheLionPieceType::HEN),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 1, 0, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 3, 2, 2, 2, Common::CatchTheLionPieceType::HEN),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::HEN, 3, 2, 3, 1)
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 12);

    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 0, 2, 0, 1, Common::CatchTheLionPieceType::HEN),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 0, 2, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 1, 1, 0, Common::CatchTheLionPieceType::HEN),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 1, 1, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 1, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 1, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 1, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 2, 1, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 2, 1, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 2, 2, 3, 2, Common::CatchTheLionPieceType::HEN),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 3, 0, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::HEN, 3, 0, 3, 1)
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}

TEST(catchthelion_unittest, LegalMovesDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_O, E_O},
        {C_X, N_A, E_X},
        {N_A, L_X, N_A},
        {N_A, N_A, G_X},
    };
    auto s = CatchTheLionState(position, {1, 2, 3}, {3, 2, 1});
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);

    // Just check number of drops for P1
    int numLegalDropsP1 = std::count_if(
        legalMovesP1, 
        legalMovesP1 + numLegalMovesP1, 
        [](auto &move)
        {
            return move.moveType == MoveType::DROP;
        });

    ASSERT_EQ(numLegalDropsP1, 18);
    
    std::vector<CatchTheLionMove> expectedDropsP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 3, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 3, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 3, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::ELEPHANT, 3, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 3, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 3, 1)
    };
    ASSERT_EQ(expectedDropsP1.size(), numLegalDropsP1);
    for (auto const& move : expectedDropsP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }


    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);

    // Just check number of drops for P2
    int numLegalDropsP2 = std::count_if(
        legalMovesP2, 
        legalMovesP2 + numLegalMovesP2, 
        [](auto &move)
        {
            return move.moveType == MoveType::DROP;
        });

    ASSERT_EQ(numLegalDropsP2, 18);
    
    std::vector<CatchTheLionMove> expectedDropsP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 0, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 1, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 3, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::CHICK, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 0, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 1, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 0, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 1, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 2, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 3, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 3, 1)
    };
    ASSERT_EQ(expectedDropsP2.size(), numLegalDropsP2);
    for (auto const& move : expectedDropsP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }
}

TEST(catchthelion_unittest, ManyLegalMovesAndDrops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_X, N_A},
        {C_X, N_A, G_X},
        {G_O, E_O, N_A},
        {L_O, N_A, N_A},
    };
    auto s = CatchTheLionState(position, {1, 0, 0}, {0, 1, 0});
    CatchTheLionMove legalMovesP1[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP1 = s.GetLegalMoves(P1, legalMovesP1);
    ASSERT_EQ(numLegalMovesP1, 13);
    
    std::vector<CatchTheLionMove> expectedMovesP1 =
    {
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::LION, 0, 1, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 1, 0, 2, 0, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 1, 2, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 1, 2, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::GIRAFFE, 1, 2, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 0, 0),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 0, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 1, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 2, 2),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 3, 1),
        CatchTheLionMove(P1, Common::CatchTheLionPieceType::CHICK, 3, 2)
    };
    ASSERT_EQ(expectedMovesP1.size(), numLegalMovesP1);
    for (auto const& move : expectedMovesP1)
    {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + numLegalMovesP1, move) != legalMovesP1 + numLegalMovesP1);
    }

    // Player 2 moves
    CatchTheLionMove legalMovesP2[CatchTheLionState::MAX_MOVES];
    int numLegalMovesP2 = s.GetLegalMoves(P2, legalMovesP2);
    ASSERT_EQ(numLegalMovesP2, 11);
    
    std::vector<CatchTheLionMove> expectedMovesP2 =
    {
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::GIRAFFE, 2, 0, 1, 0, Common::CatchTheLionPieceType::CHICK),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 1, 1, 0, Common::CatchTheLionPieceType::CHICK),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 1, 1, 2, Common::CatchTheLionPieceType::GIRAFFE),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 1, 3, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::LION, 3, 0, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 0, 0),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 0, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 1, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 2, 2),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 1),
        CatchTheLionMove(P2, Common::CatchTheLionPieceType::ELEPHANT, 3, 2)
    };
    ASSERT_EQ(expectedMovesP2.size(), numLegalMovesP2);
    for (auto const& move : expectedMovesP2)
    {
        ASSERT_TRUE(std::find(legalMovesP2, legalMovesP2 + numLegalMovesP2, move) != legalMovesP2 + numLegalMovesP2);
    }

}

}