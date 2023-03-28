#pragma once

#include "game_state.h"
#include "connect4_state.h"
#include "breakthrough_state.h"
#include "othello_state.h"
#include "catchthelion_state.h"

namespace Strategy
{

inline int FixedDepth1(const Games::GameState&) { return 1; }
inline int FixedDepth2(const Games::GameState&) { return 2; }
inline int FixedDepth3(const Games::GameState&) { return 3; }
inline int FixedDepth4(const Games::GameState&) { return 4; }
inline int FixedDepth5(const Games::GameState&) { return 5; }
inline int FixedDepth6(const Games::GameState&) { return 6; }
inline int FixedDepth7(const Games::GameState&) { return 7; }
inline int FixedDepth8(const Games::GameState&) { return 8; }
inline int FixedDepth9(const Games::GameState&) { return 9; }
inline int FixedDepth10(const Games::GameState&) { return 10; }

template <typename TState>
int DepthFromTurnA(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnA<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnA<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnA<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnB(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnB<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnB<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnB<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnB<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnC(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnC<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnC<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnC<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnC<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnD(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnD<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnD<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnD<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnD<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnE(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnE<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnE<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnE<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnE<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnF(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnF<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnF<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnF<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnF<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnG(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnG<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnG<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnG<Othello::OthelloState>(const Games::GameState& gameState);

template <>
int DepthFromTurnG<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnH(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnH<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurnH<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurnH<Othello::OthelloState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnI(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnI<Othello::OthelloState>(const Games::GameState& gameState);

template <typename TState>
int DepthFromTurnJ(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurnJ<Othello::OthelloState>(const Games::GameState& gameState);

}
