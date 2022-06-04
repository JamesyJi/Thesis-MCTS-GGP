#pragma once

#include "game_state.h"
#include "connect4_state.h"

namespace Strategy
{

template <typename TState>
int DepthFromTurn(const Games::GameState& gameState) = delete;

template <>
int DepthFromTurn<Connect4::Connect4State>(const Games::GameState& gameState);

}
