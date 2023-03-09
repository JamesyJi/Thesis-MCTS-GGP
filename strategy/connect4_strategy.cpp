#include "strategy.h"

namespace Strategy
{

    const int MAX_TURNS = 42; // Maximum number of turns we will account for in our calculations

    // Map depth of minimax to the turn number
    const int TURN_DEPTH_A[] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        2,
        1,
        2,
        1,
        2,
        2,
        3,
        2,
        4,
        3,
        4,
        4,
        6,
        7,
        8,
        10,
        10,
        10,
        8,
        7,
        5,
        4,
        2,
        2,
        1,
        1,
        0,
        0};

    template <>
    int DepthFromTurnA<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_A[gameState.GetTurn()];
    };

    const int TURN_DEPTH_B[] = {
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
        1,
        0,
        1,
        0,
        1,
        1,
        2,
        1,
        2,
        2,
        3,
        3,
        5,
        6,
        7,
        9,
        9,
        10,
        8,
        8,
        5,
        5,
        3,
        2,
        1,
        1,
        0,
        0};
    template <>
    int DepthFromTurnB<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_B[gameState.GetTurn()];
    };
    const int TURN_DEPTH_C[] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        2,
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
        1,
        0,
        1,
        1,
        2,
        1,
        2,
        1,
        2,
        2,
        5,
        5,
        7,
        10,
        9,
        9,
        6,
        4,
        2,
        1,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurnC<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_C[gameState.GetTurn()];
    };
    const int TURN_DEPTH_D[] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        1,
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
        1,
        0,
        1,
        0,
        1,
        1,
        3,
        4,
        6,
        10,
        9,
        9,
        5,
        3,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0};

    template <>
    int DepthFromTurnD<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_D[gameState.GetTurn()];
    };

}
