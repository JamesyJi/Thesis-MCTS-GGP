#include "strategy.h"

namespace Strategy
{

    const int MAX_TURNS = 42; // Maximum number of turns we will account for in our calculations

    // Map depth of minimax to the turn number
    const int TURN_DEPTH_4[] = {
        -1,
        0,
        0,
        0,
        5,
        0,
        7,
        0,
        0,
        1,
        1,
        0,
        3,
        1,
        5,
        1,
        5,
        1,
        5,
        3,
        5,
        3,
        5,
        4,
        5,
        5,
        7,
        7,
        8,
        9,
        9,
        8,
        7,
        6,
        4,
        3,
        2,
        2,
        2,
        1,
        1,
        1,
        1};

    template <>
    int DepthFromTurn4<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_4[gameState.GetTurn()];
    };

    const int TURN_DEPTH_5[MAX_TURNS + 1] = {
        -1,
        0,
        0,
        0,
        5,
        0,
        7,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        5,
        0,
        5,
        0,
        5,
        0,
        5,
        0,
        5,
        0,
        5,
        5,
        7,
        7,
        8,
        9,
        9,
        8,
        7,
        6,
        5,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurn5<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_5[gameState.GetTurn()];
    };

    const int TURN_DEPTH_6[MAX_TURNS + 1] = {
        -1,
        0,
        0,
        0,
        10,
        0,
        10,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        10,
        0,
        10,
        0,
        10,
        0,
        10,
        0,
        10,
        0,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurn6<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_6[gameState.GetTurn()];
    };

    const int TURN_DEPTH_7[MAX_TURNS + 1] = {
        -1,
        0,
        0,
        0,
        5,
        0,
        9,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        5,
        0,
        0,
        7,
        0,
        5,
        5,
        5,
        5,
        7,
        5,
        5,
        7,
        9,
        9,
        9,
        10,
        10,
        10,
        9,
        7,
        5,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurn7<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_7[gameState.GetTurn()];
    };

}
