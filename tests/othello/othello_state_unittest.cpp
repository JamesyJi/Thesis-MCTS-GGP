#include <gtest/gtest.h>
#include "pieces.h"
#include "othello_state.h"
#include "othello_state_gen.h"

#include <algorithm>

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)
#define A Common::Piece()

namespace Othello
{

// class TestFixture : public ::testing::TestWithParam<OthelloState>{
// protected:
//     OthelloState othelloState;
// };

// TEST_P(TestFixture, EvaluateOngoing) {
//     OthelloState state = GetParam();
// }

// auto func = StateGenerator(10);

// INSTANTIATE_TEST_SUITE_P(
//     othello_state_unittest,
//     TestFixture,
//     testing::ValuesIn(
//         generate_begin<Othello::OthelloState>(func),
//         generate_end<Othello::OthelloState>(func)
//     )
// );


// TEST(othello_state_unittest, EvaluateOngoing) {
//     const Common::Piece position[OthelloState::ROWS][Othello::OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, X, A, A, A},
//         {A, A, A, X, X, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = Othello::OthelloState(position);

//     EXPECT_EQ(s.EvaluateState(OthelloMove(Common::Player::PLAYER1, 2, 4, {Direction::S})), Common::Result::ONGOING);
// }

// TEST(othello_state_unitest, MakeMoveFlipsPieces) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, X, O, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = OthelloState(position);

//     auto newS = s.MakeMove(OthelloMove(Common::Player::PLAYER1, 2, 4, {Direction::S}));
//     const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, X, A, A, A},
//         {A, A, A, X, X, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto expectedS = Othello::OthelloState(position1);

//     EXPECT_TRUE(newS == expectedS);
// }

// TEST(othello_state_unitest, MakeMoveNeedsAdjacentOpponentPiece) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, X, A, A},
//         {A, A, X, A, A, X, A, A},
//         {A, A, A, X, X, X, O, O},
//         {A, A, O, O, O, X, A, A},
//         {A, A, A, O, X, X, X, A},
//         {A, A, A, X, O, O, A, A},
//         {A, A, A, A, A, O, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = OthelloState(position);

//     auto newS = s.MakeMove(OthelloMove(Common::Player::PLAYER1, 0, 2, {Direction::S}));
//     const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, X, A, A},
//         {A, A, X, A, A, X, A, A},
//         {A, A, A, X, X, X, O, O},
//         {A, A, O, O, O, X, A, A},
//         {A, A, A, O, X, X, X, A},
//         {A, A, A, X, O, O, A, A},
//         {A, A, A, A, A, O, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
// }


// TEST(OthelloStateSimulateMoveUnitTest, SimulateMoveFlipsPiecesS) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, X, O, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = OthelloState(position);
//     s.SimulateMove(OthelloMove(Common::Player::PLAYER1, 2, 4, {Direction::S}));
    
//     const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, X, A, A, A},
//         {A, A, A, X, X, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto expectedS = Othello::OthelloState(position1);

//     EXPECT_TRUE(s == expectedS);
// }

// TEST(OthelloStateSimulateMoveUnitTest, SimulateMoveFlipsPiecesNW) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {O, X, X, X, X, O, O, O},
//         {O, X, X, X, X, O, O, O},
//         {O, X, O, O, X, O, O, O},
//         {O, X, O, O, X, X, O, O},
//         {O, X, O, O, X, X, O, O},
//         {O, O, O, O, X, O, O, O},
//         {O, O, O, O, X, X, O, X},
//         {X, O, O, O, O, O, O, A}
//     };
//     auto s = OthelloState(position);
//     s.SimulateMove(OthelloMove(Common::Player::PLAYER1, 7, 7, {Direction::NW, Direction::W}));
    
//     const Common::Piece position1[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {O, X, X, X, X, O, O, O},
//         {O, X, X, X, X, O, O, O},
//         {O, X, O, O, X, O, O, O},
//         {O, X, O, O, X, X, O, O},
//         {O, X, O, O, X, X, O, O},
//         {O, O, O, O, X, X, O, O},
//         {O, O, O, O, X, X, X, X},
//         {X, X, X, X, X, X, X, X}
//     };
//     auto expectedS = Othello::OthelloState(position1);

//     EXPECT_TRUE(s == expectedS);
// }


// TEST(othello_state_unittest, GetLegalMoves) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, X, O, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = OthelloState(position);
//     OthelloMove legalMoves[OthelloState::MAX_MOVES];
//     ASSERT_EQ(s.GetLegalMoves(Common::Player::PLAYER1, legalMoves), 4);
//     std::vector<OthelloMove> expectedMoves = {
//         OthelloMove(Common::Player::PLAYER1, 2, 4, {Direction::S}),
//         OthelloMove(Common::Player::PLAYER1, 3, 5, {Direction::W}),
//         OthelloMove(Common::Player::PLAYER1, 5, 3, {Direction::N}),
//         OthelloMove(Common::Player::PLAYER1, 4, 2, {Direction::E}),
//     };
//     for (int i = 0; i < 4; ++i) {
//         std::cout << legalMoves[i];
//         ASSERT_TRUE(std::find(expectedMoves.begin(), expectedMoves.end(), legalMoves[i]) != expectedMoves.end());
//     }
// }

// TEST(othello_state_unittest, GetLegalMoves) {

// }

// TEST(othello_state_unittest, GetLegalMoves) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, X, O, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = OthelloState(position);
//     OthelloMove legalMoves[OthelloState::MAX_MOVES];
// }

// TEST(othello_state_unittest, FindUpdateCaptureDirections) {
//     const Common::Piece position[OthelloState::ROWS][OthelloState::COLS] =
//     {
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, X, O, A, A, A},
//         {A, A, A, O, X, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A},
//         {A, A, A, A, A, A, A, A}
//     };
//     auto s = OthelloState(position);
// }

}