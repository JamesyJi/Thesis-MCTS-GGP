#include <gtest/gtest.h>

#include "pieces.h"
#include "catchthelion_state.h"
#include "test_defines.h"
#include "catchthelion_defines.h"

namespace CatchTheLion
{

TEST(catchthelion_unittest, CaptureLion_IsPlayer1Win)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {N_A, C_X, N_A},
        {N_A, L_O, N_A},
        {N_A, N_A, N_A}
    };
    auto s = CatchTheLionState(position);

    auto move = CatchTheLionMove(P1, CHICK, 1, 1, 2, 1, LION);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), P1_WIN);
}

TEST(catchthelion_unittest, CaptureLion_IsPlayer2Win)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, N_A, E_X},
        {N_A, L_X, N_A},
        {N_A, L_O, N_A},
        {N_A, N_A, N_A}
    };
    auto s = CatchTheLionState(position);

    auto move = CatchTheLionMove(P2, LION, 2, 1, 1, 1, LION);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), P2_WIN);
}

// Lion to backrank in Check is Not a win
TEST(catchthelion_unittest, BackRankLion_CheckedByElephant_IsOngoing)
{
    // // Checked by an ELEPHANT
    // const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    // {
    //     {N_A, N_A, N_A},
    //     {E_O, L_O, E_X},
    //     {N_A, E_O, N_A},
    //     {N_A, N_A, L_X}
    // };
    // auto s = CatchTheLionState(position);
    
    // auto move = CatchTheLionMove(P1, LION, 2, 2, 3, 2);
    // ASSERT_EQ(s.EvaluateState(move), ONGOING);

    // const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    // {
    //     {N_A, N_A, N_A},
    //     {E_O, L_O, E_X},
    //     {N_A, N_A, E_O},
    //     {N_A, L_X, N_A}
    // };
    // auto s = CatchTheLionState(position);


    // auto move1 = CatchTheLionMove(P2, LION, 1, 1, 0, 1);
    // ASSERT_EQ(s.EvaluateState(move1), ONGOING);
}

// Lion to backrank not in check is a win
TEST(catchthelion_unittest, BackRankLion_NotInCheck_IsWon)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {E_X, N_A, C_X},
        {N_A, L_O, N_A},
        {N_A, H_O, L_X},
        {N_A, N_A, N_A}
    };
    auto s = CatchTheLionState(position);

    auto move = CatchTheLionMove(P1, LION, 2, 2, 3, 2);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), P1_WIN);

    auto move1 = CatchTheLionMove(P2, LION, 1, 1, 0, 1);
    s.SimulateMove(move1);
    ASSERT_EQ(s.EvaluateState(move1), P2_WIN);
}

TEST(catchthelion_unittest, NormalMove_IsOngoing)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, N_A, E_X},
        {N_A, L_X, N_A},
        {N_A, L_O, N_A},
        {N_A, N_A, N_A}
    };
    auto s = CatchTheLionState(position);

    auto move = CatchTheLionMove(P1, LION, 1, 1, 1, 2);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), ONGOING);
}

TEST(catchthelion_unittest, CaptureNonLion_IsOngoing)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, N_A, E_X},
        {N_A, L_X, N_A},
        {N_A, L_O, C_X},
        {N_A, N_A, N_A}
    };
    auto s = CatchTheLionState(position);

    auto move = CatchTheLionMove(P2, LION, 2, 1, 2, 2, CHICK);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), ONGOING);
}

TEST(catchthelion_unittest, Drop_IsOngoing)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, N_A, E_X},
        {N_A, L_X, N_A},
        {N_A, L_O, N_A},
        {N_A, N_A, N_A}
    };
    auto s = CatchTheLionState(position);

    auto move = CatchTheLionMove(P1, CHICK, 3, 0);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), ONGOING);
}

TEST(catchthelion_unittest, RepeatedMoves_3Times_IncludeCapture_IsOngoing)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {C_O, C_X, N_A},
        {N_A, C_O, N_A},
        {E_O, L_O, G_O}
    };

    std::vector<CatchTheLionMove> moveHistory =
    {
        CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0, CHICK),
        CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2),
        CatchTheLionMove(P1, GIRAFFE, 1, 0, 0, 0),
        CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2),

        CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0),
        CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2),
        CatchTheLionMove(P1, GIRAFFE, 1, 0, 0, 0),
        CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2),
        
        CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0),
        CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2),
        CatchTheLionMove(P1, GIRAFFE, 1, 0, 0, 0),
    };

    auto move = CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2);
    moveHistory.push_back(move);
    
    auto s = CatchTheLionState(position, moveHistory);
    ASSERT_EQ(s.EvaluateState(move), ONGOING);    
}

TEST(catchthelion_unittest, RepeatedMoves_Not3Times_IsOngoing)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {N_A, C_X, N_A},
        {N_A, C_O, N_A},
        {E_O, L_O, G_O}
    };

    std::vector<CatchTheLionMove> moveHistory =
    {
        CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0),
        CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2),
        CatchTheLionMove(P1, GIRAFFE, 1, 0, 0, 0),
        CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2),

        CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0),
        CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2),
        CatchTheLionMove(P1, GIRAFFE, 1, 0, 0, 0),
        CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2),
    };

    auto move = CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2);
    moveHistory.push_back(move);

    // Repeating twice is not enough
    auto s = CatchTheLionState(position, moveHistory);
    ASSERT_EQ(s.EvaluateState(move), ONGOING);

    // Moving another piece resets the streak
    auto moveDifferent = CatchTheLionMove(P1, LION, 0, 1, 1, 2);
    moveHistory.push_back(moveDifferent);
    moveHistory.emplace_back(CatchTheLionMove(P2, GIRAFFE, 3, 2, 2, 2));
    moveHistory.emplace_back(CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0));
    moveHistory.emplace_back(CatchTheLionMove(P2, GIRAFFE, 2, 2, 3, 2));
    auto move2 = CatchTheLionMove(P1, GIRAFFE, 1, 0, 0, 0);
    moveHistory.push_back(move2);
    ASSERT_EQ(s.EvaluateState(move2), ONGOING);
}

TEST(catchthelion_unittest, RepeatedMoves_IsDraw)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, N_A, E_X},
        {N_A, L_X, N_A},
        {N_A, L_O, N_A},
        {N_A, N_A, N_A}
    };

    std::vector<CatchTheLionMove> moveHistory =
    {
        CatchTheLionMove(P1, LION, 1, 1, 1, 2),
        CatchTheLionMove(P2, LION, 2, 1, 2, 2),
        CatchTheLionMove(P1, LION, 1, 2, 1, 1),
        CatchTheLionMove(P2, LION, 2, 2, 2, 1),
        CatchTheLionMove(P1, LION, 1, 1, 1, 2),
        CatchTheLionMove(P2, LION, 2, 1, 2, 2),
        CatchTheLionMove(P1, LION, 1, 2, 1, 1),
        CatchTheLionMove(P2, LION, 2, 2, 2, 1),
        CatchTheLionMove(P1, LION, 1, 1, 1, 2),
        CatchTheLionMove(P2, LION, 2, 1, 2, 2),
        CatchTheLionMove(P1, LION, 1, 2, 1, 1)
    };
    auto s = CatchTheLionState(position, moveHistory);

    auto move = CatchTheLionMove(P2, LION, 2, 2, 2, 1);
    s.SimulateMove(move);
    ASSERT_EQ(s.EvaluateState(move), DRAW);
}




}