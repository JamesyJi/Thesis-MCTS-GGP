#include "strategy.h"

namespace Strategy
{

const int MAX_TURNS = 42; // Maximum number of turns we will account for in our calculations

// Map depth of minimax to the turn number
const int TURN_DEPTH[] = {
    -1,
    0,
    0,
    0,
    6,
    6
};

template <>
int DepthFromTurn<Connect4::Connect4State>(const Games::GameState& gameState) 
{
    return 4;
};

}

