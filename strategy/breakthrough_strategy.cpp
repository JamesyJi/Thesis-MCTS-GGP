#include "strategy.h"

namespace Strategy
{
    const int MAX_TURNS = 45; // Maximum number of turns we will account for in our calculations
    const int TURN_DEPTH_A[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        3,
        2,
        3,
        4,
        6,
        6,
        6,
        7,
        7,
        8,
        7,
        7,
        7,
        6,
        6,
        6,
        6,
        5,
        5,
        4,
        4,
        3,
        3,
        3,
        2,
        2,
        2,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
    };

    template <>
    int DepthFromTurnA<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_A[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_B[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        2,
        2,
        3,
        4,
        5,
        5,
        5,
        6,
        6,
        7,
        7,
        6,
        6,
        6,
        5,
        5,
        5,
        4,
        5,
        4,
        4,
        3,
        3,
        2,
        2,
        2,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };

    template <>
    int DepthFromTurnB<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_B[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_C[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        2,
        2,
        3,
        3,
        4,
        5,
        5,
        5,
        5,
        6,
        6,
        5,
        5,
        5,
        5,
        4,
        4,
        4,
        4,
        3,
        3,
        3,
        2,
        2,
        2,
        1,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };

    template <>
    int DepthFromTurnC<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_C[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_D[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        2,
        1,
        2,
        3,
        3,
        4,
        4,
        4,
        4,
        5,
        5,
        5,
        4,
        4,
        4,
        4,
        4,
        3,
        3,
        3,
        3,
        2,
        2,
        2,
        2,
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };

    template <>
    int DepthFromTurnD<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_D[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_E[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        2,
        2,
        3,
        3,
        3,
        4,
        4,
        4,
        4,
        4,
        3,
        3,
        3,
        3,
        3,
        3,
        3,
        2,
        2,
        2,
        2,
        1,
        1,
        1,
        1,
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
    };

    template <>
    int DepthFromTurnE<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_E[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_F[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        2,
        2,
        2,
        2,
        3,
        3,
        3,
        3,
        3,
        3,
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
    };

    template <>
    int DepthFromTurnF<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_F[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_G[MAX_TURNS] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
        1,
        2,
        2,
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
    };

    template <>
    int DepthFromTurnG<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_G[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }

    const int TURN_DEPTH_H[MAX_TURNS] = {
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
    };

    template <>
    int DepthFromTurnH<Breakthrough::BreakthroughState>(const Games::GameState &gameState)
    {
        if (gameState.GetTurn() < MAX_TURNS)
        {
            return TURN_DEPTH_H[gameState.GetTurn()];
        }
        else
        {
            return 0;
        }
    }
}