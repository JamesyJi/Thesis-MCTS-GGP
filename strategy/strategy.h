#pragma once

#include "game_state.h"
#include "connect4_state.h"

namespace Strategy
{

    inline int FixedDepth1(const Games::GameState &) { return 1; }
    inline int FixedDepth2(const Games::GameState &) { return 2; }
    inline int FixedDepth3(const Games::GameState &) { return 3; }
    inline int FixedDepth4(const Games::GameState &) { return 4; }
    inline int FixedDepth5(const Games::GameState &) { return 5; }
    inline int FixedDepth6(const Games::GameState &) { return 6; }
    inline int FixedDepth7(const Games::GameState &) { return 7; }
    inline int FixedDepth8(const Games::GameState &) { return 8; }
    inline int FixedDepth9(const Games::GameState &) { return 9; }
    inline int FixedDepth10(const Games::GameState &) { return 10; }

    template <typename TState>
    int DepthFromTurnA(const Games::GameState &gameState) = delete;

    // Connect4
    template <>
    int DepthFromTurnA<Connect4::Connect4State>(const Games::GameState &gameState);

    template <typename TState>
    int DepthFromTurnB(const Games::GameState &gameState) = delete;

    template <>
    int DepthFromTurnB<Connect4::Connect4State>(const Games::GameState &gameState);

    template <typename TState>
    int DepthFromTurnC(const Games::GameState &gameState) = delete;

    template <>
    int DepthFromTurnC<Connect4::Connect4State>(const Games::GameState &gameState);

    template <typename TState>
    int DepthFromTurnD(const Games::GameState &gameState) = delete;

    template <>
    int DepthFromTurnD<Connect4::Connect4State>(const Games::GameState &gameState);
}
