#include "strategy.h"

namespace Strategy
{

    const int MAX_TURNS = 42; // Maximum number of turns we will account for in our calculations

    // Map depth of minimax to the turn number
    const int TURN_DEPTH_8[] = {
        -1,
        0,
        0,
        0,
        1,
        0,
        4,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        2,
        0,
        1,
        0,
        2,
        0,
        2,
        1,
        1,
        1,
        4,
        4,
        4,
        8,
        8,
        4,
        4,
        2,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurn8<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_8[gameState.GetTurn()];
    };

    const int TURN_DEPTH_9[] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        3,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        0,
        0,
        2,
        3,
        4,
        5,
        5,
        5,
        2,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0};
    template <>
    int DepthFromTurn9<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_9[gameState.GetTurn()];
    };

    const int TURN_DEPTH_10[] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        10,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
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
        0,
        0};

    template <>
    int DepthFromTurn10<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_10[gameState.GetTurn()];
    };

    const int TURN_DEPTH_11[] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        10,
        10,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurn11<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_11[gameState.GetTurn()];
    };

}
