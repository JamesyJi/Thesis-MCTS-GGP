#include "strategy.h"
namespace Strategy
{
const int MAX_BRANCHING = 22;

const int TURN_DEPTH_A[MAX_BRANCHING] = {
    -1,
    1,
    3,
    4,
    6,
    7,
    9,
    10,
    7,
    5,
    2,
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
int DepthFromTurnA<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    3,
    4,
    5,
    6,
    8,
    9,
    6,
    5,
    2,
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
int DepthFromTurnB<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    2,
    3,
    5,
    6,
    7,
    8,
    5,
    4,
    2,
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
int DepthFromTurnC<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    5,
    4,
    2,
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
int DepthFromTurnD<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    2,
    3,
    3,
    4,
    5,
    6,
    4,
    3,
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
};

template <>
int DepthFromTurnE<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    1,
    2,
    3,
    4,
    4,
    5,
    3,
    3,
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
};

template <>
int DepthFromTurnF<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    1,
    2,
    2,
    3,
    3,
    4,
    3,
    2,
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
};

template <>
int DepthFromTurnG<Othello::OthelloState>(const Games::GameState& gameState)
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
    1,
    1,
    2,
    2,
    3,
    3,
    2,
    2,
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
};

template <>
int DepthFromTurnH<Othello::OthelloState>(const Games::GameState& gameState)
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

const int TURN_DEPTH_I[MAX_BRANCHING] = {
    -1,
    0,
    1,
    1,
    1,
    1,
    2,
    2,
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
int DepthFromTurnI<Othello::OthelloState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_I[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_J[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
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
int DepthFromTurnJ<Othello::OthelloState>(const Games::GameState& gameState)
{
    if (gameState.GetTurn() < MAX_BRANCHING)
    {
        return TURN_DEPTH_J[gameState.GetTurn()];
    }
    else
    {
        return 0;
    }
}

}