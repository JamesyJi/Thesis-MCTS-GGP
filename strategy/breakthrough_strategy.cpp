#include "strategy.h"

namespace Strategy
{
const int MAX_BRANCHING = 25; // Maximum gameState.GetTurn() factor we will account for in our calculations
const int TURN_DEPTH_A[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    4,
    4,
    5,
    5,
    6,
    6,
    7,
    7,
    8,
    8,
    7,
    6,
    6,
    5,
    6,
    3,
    1,
    2,
};

template <>
int DepthFromTurnA<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_A[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_B[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    3,
    4,
    4,
    5,
    5,
    6,
    6,
    7,
    7,
    7,
    6,
    6,
    5,
    5,
    5,
    3,
    0,
    1,
};

template <>
int DepthFromTurnB<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_B[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_C[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    3,
    3,
    4,
    4,
    4,
    5,
    5,
    6,
    6,
    6,
    5,
    5,
    4,
    4,
    5,
    3,
    0,
    1,
};

template <>
int DepthFromTurnC<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_C[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_D[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    3,
    3,
    3,
    4,
    4,
    4,
    5,
    5,
    5,
    4,
    4,
    3,
    3,
    4,
    2,
    0,
    1,
};

template <>
int DepthFromTurnD<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_D[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_E[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    3,
    2,
    0,
    1,
};

template <>
int DepthFromTurnE<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_E[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_F[MAX_BRANCHING] = {
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
    2,
    2,
    2,
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
    0,
    1,
};

template <>
int DepthFromTurnF<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_F[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_G[MAX_BRANCHING] = {
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
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    1,
    1,
    2,
    1,
    0,
    0,
};

template <>
int DepthFromTurnG<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_G[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_H[MAX_BRANCHING] = {
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
};

template <>
int DepthFromTurnH<Breakthrough::BreakthroughState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_H[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}
}