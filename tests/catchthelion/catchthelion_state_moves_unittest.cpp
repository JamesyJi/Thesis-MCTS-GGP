#include <gtest/gtest.h>

#include "pieces.h"
#include "catchthelion_state.h"
#include "test_defines.h"
#include "catchthelion_defines.h"

namespace CatchTheLion
{

TEST(catchthelion_unittest, SimulateAndUndo_Multiple_Moves_Captures_Drops)
{
    const Common::CatchTheLionPiece position[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {N_A, C_X, N_A},
        {N_A, C_O, N_A},
        {E_O, L_O, G_O}
    };
    auto s = CatchTheLionState(position);

    std::vector<CatchTheLionMove> moveHistory;

    // Turn 1: P1 captures the Chick
    auto move1 = CatchTheLionMove(P1, CHICK, 1, 1, 2, 1, CHICK);
    s.SimulateMove(move1);
    moveHistory.push_back(move1);
    const Common::CatchTheLionPiece position1[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {N_A, N_A, N_A},
        {N_A, C_X, N_A},
        {E_O, L_O, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position1, {1, 0, 0}, {0, 0, 0}, moveHistory));

    // Turn 2: P2 recaptures the Chick with Lion
    auto move2 = CatchTheLionMove(P2, LION, 3, 1, 2, 1, CHICK);
    s.SimulateMove(move2);
    moveHistory.push_back(move2);
    const Common::CatchTheLionPiece position2[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {G_X, L_X, E_X},
        {N_A, N_A, N_A},
        {N_A, L_O, N_A},
        {E_O, N_A, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position2, {1, 0, 0}, {1, 0, 0}, moveHistory));

    // Turn 3: P1 Moves Giraffe up
    auto move3 = CatchTheLionMove(P1, GIRAFFE, 0, 0, 1, 0);
    s.SimulateMove(move3);
    moveHistory.push_back(move3);
    const Common::CatchTheLionPiece position3[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_X, E_X},
        {G_X, N_A, N_A},
        {N_A, L_O, N_A},
        {E_O, N_A, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position3, {1, 0, 0}, {1, 0, 0}, moveHistory));

    // Turn 4: P2 drops Chick to attack elephant
    auto move4 = CatchTheLionMove(P2, CHICK, 1, 2);
    s.SimulateMove(move4);
    moveHistory.push_back(move4);
    const Common::CatchTheLionPiece position4[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_X, E_X},
        {G_X, N_A, C_O},
        {N_A, L_O, N_A},
        {E_O, N_A, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position4, {1, 0, 0}, {0, 0, 0}, moveHistory));

    // Turn 5: P1 moves Giraffe to threaten P2's Lion
    auto move5 = CatchTheLionMove(P1, GIRAFFE, 1, 0, 1, 1);
    s.SimulateMove(move5);
    moveHistory.push_back(move5);
    const Common::CatchTheLionPiece position5[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_X, E_X},
        {N_A, G_X, C_O},
        {N_A, L_O, N_A},
        {E_O, N_A, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position5, {1, 0, 0}, {0, 0, 0}, moveHistory));

    // Turn 6: P2 captures Elephant with Chick (this promotes to a Hen)
    auto move6 = CatchTheLionMove(P2, CHICK, 1, 2, 0, 2, ELEPHANT);
    s.SimulateMove(move6);
    moveHistory.push_back(move6);
    const Common::CatchTheLionPiece position6[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_X, H_O},
        {N_A, G_X, N_A},
        {N_A, L_O, N_A},
        {E_O, N_A, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position6, {1, 0, 0}, {0, 1, 0}, moveHistory));

    // Turn 7: P1 captures Lion with Giraffe
    auto move7 = CatchTheLionMove(P1, GIRAFFE, 1, 1, 2, 1, LION);
    s.SimulateMove(move7);
    moveHistory.push_back(move7);
    const Common::CatchTheLionPiece position7[CatchTheLionState::ROWS][CatchTheLionState::COLS] =
    {
        {N_A, L_X, H_O},
        {N_A, N_A, N_A},
        {N_A, G_X, N_A},
        {E_O, N_A, G_O},
    };
    ASSERT_EQ(s, CatchTheLionState(position7, {1, 0, 0}, {0, 1, 0}, moveHistory));

    // Now undo the entire game back to start
    s.UndoMove(move7);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position6, {1, 0, 0}, {0, 1, 0}, moveHistory));

    s.UndoMove(move6);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position5, {1, 0, 0}, {0, 0, 0}, moveHistory));

    s.UndoMove(move5);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position4, {1, 0, 0}, {0, 0, 0}, moveHistory));

    s.UndoMove(move4);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position3, {1, 0, 0}, {1, 0, 0}, moveHistory));

    s.UndoMove(move3);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position2, {1, 0, 0}, {1, 0, 0}, moveHistory));

    s.UndoMove(move2);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position1, {1, 0, 0}, {0, 0, 0}, moveHistory));

    s.UndoMove(move1);
    moveHistory.pop_back();
    ASSERT_EQ(s, CatchTheLionState(position));
}




}