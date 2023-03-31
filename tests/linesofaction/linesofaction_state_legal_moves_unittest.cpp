#include <gtest/gtest.h>
#include "pieces.h"
#include "linesofaction_state.hpp"

#define P1 Common::Player::PLAYER1
#define P2 Common::Player::PLAYER2
#define P1_WIN Common::Result::PLAYER1_WIN
#define P2_WIN Common::Result::PLAYER2_WIN
#define DRAW Common::Result::DRAW
#define ONGOING Common::Result::ONGOING

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)

namespace LinesOfAction {

TEST(linesofaction_state_legal_moves_unittest, GetLegalMoves_StartingPosition) {
    auto const s = LinesOfActionState();

    // Check Player 1's legal moves
    LinesOfActionMove legalMovesP1[LinesOfActionState::MAX_MOVES];

    ASSERT_EQ(s.GetLegalMoves(P1, legalMovesP1), 36);

    std::vector<LinesOfActionMove> expectedMovesP1 = {
        LinesOfActionMove(P1, 1, 0, 3, 0, false),
        LinesOfActionMove(P1, 1, 0, 7, 0, false),
        LinesOfActionMove(P1, 1, 0, 3, 3, false),
        // TODO
    };

    for (auto& move : expectedMovesP1) {
        ASSERT_TRUE(std::find(legalMovesP1, legalMovesP1 + 36, move) != legalMovesP1 + 36);
    };
}
}