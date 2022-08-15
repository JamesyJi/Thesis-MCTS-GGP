#include "strategy.h"

namespace Strategy
{

const int MAX_TURNS = 299; // Maximum number of turns we will account for in our calculations

const int* InitialiseTurnDepths()
{
    static int turnDepths[300];
    turnDepths[0] = -1;
    for (int i = 1; i <= 34; ++i) turnDepths[i] = 0;
    for (int i = 35; i <= 299; ++i) turnDepths[i] = 1;

    return turnDepths;
}

const int* TURN_DEPTH = InitialiseTurnDepths();

template <>
int DepthFromTurn<Othello::OthelloState>(const Games::GameState& gameState) 
{
    return TURN_DEPTH[gameState.GetTurn()];
};

}