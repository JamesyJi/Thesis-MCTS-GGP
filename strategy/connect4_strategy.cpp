#include "strategy.h"

namespace Strategy
{

    const int MAX_TURNS = 42; // Maximum number of turns we will account for in our calculations

    // Map depth of minimax to the turn number
    const int TURN_DEPTH_E[] = {
        -1,
        0,
        0,
        0,
        1,
        0,
        2,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        2,
        1,
        3,
        1,
        3,
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
    int DepthFromTurnE<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_E[gameState.GetTurn()];
    };

    const int TURN_DEPTH_F[] = {
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
        1,
        0,
        2,
        1,
        2,
        1,
        3,
        2,
        3,
        2,
        3,
        4,
        5,
        6,
        7,
        9,
        9,
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
    int DepthFromTurnF<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_F[gameState.GetTurn()];
    };
    const int TURN_DEPTH_G[] = {
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
        8,
        9,
        10,
        8,
        8,
        6,
        5,
        3,
        2,
        1,
        1,
        0,
        0};

    template <>
    int DepthFromTurnG<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_G[gameState.GetTurn()];
    };
    const int TURN_DEPTH_H[] = {
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
        1,
        0,
        1,
        1,
        2,
        1,
        2,
        2,
        2,
        3,
        4,
        5,
        7,
        8,
        9,
        10,
        9,
        8,
        6,
        5,
        3,
        3,
        1,
        1,
        1,
        0};

    template <>
    int DepthFromTurnH<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_H[gameState.GetTurn()];
    };


    const int TURN_DEPTH_I[] = {
            -1,
            2,
            2,
            2,
            2,
            2,
            2,
            2,
            2,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            10,
            9,
            9,
            8,
            7,
            6,
            5,
            5,
            5,
            5,
            5};

    template <>
    int DepthFromTurnI<Connect4::Connect4State>(const Games::GameState &gameState)
    {
        return TURN_DEPTH_I[gameState.GetTurn()];
    };

}
