#include "strategy.h"

namespace Strategy
{

// const int MAX_TURNS = 42; // Maximum number of turns we will account for in our calculations

// Map depth of minimax to the turn number
const int TURN_DEPTH[] = {
    -1,
    0,
    0,
    6,
    6,
    6,
    6,
    0,
    0,
    0,
    4,
    4,
    4,
    5,
    6,
    6,
    7,
    7,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    12,
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
    10,
    10,
    10,
    10,
};

template <>
int DepthFromTurn<Connect4::Connect4State>(const Games::GameState& gameState) 
{
    return TURN_DEPTH[gameState.GetTurn()];
};

}

