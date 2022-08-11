#pragma once

#include "game_state.h"
#include "catchthelion_state.h"
#include "connect4_state.h"
#include "breakthrough_state.h"

namespace Strategy
{

inline int FixedDepth1(const Games::GameState& gameState) { return 1; }
inline int FixedDepth2(const Games::GameState& gameState) { return 2; }
inline int FixedDepth3(const Games::GameState& gameState) { return 3; }
inline int FixedDepth4(const Games::GameState& gameState) { return 4; }
inline int FixedDepth5(const Games::GameState& gameState) { return 5; }
inline int FixedDepth6(const Games::GameState& gameState) { return 6; }
inline int FixedDepth7(const Games::GameState& gameState) { return 7; }
inline int FixedDepth8(const Games::GameState& gameState) { return 8; }
inline int FixedDepth9(const Games::GameState& gameState) { return 9; }
inline int FixedDepth10(const Games::GameState& gameState) { return 10; }

template <typename TState>
int DepthFromTurn(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurn<Connect4::Connect4State>(const Games::GameState& gameState);

template <>
int DepthFromTurn<Breakthrough::BreakthroughState>(const Games::GameState& gameState);

template <>
int DepthFromTurn<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState);


}
