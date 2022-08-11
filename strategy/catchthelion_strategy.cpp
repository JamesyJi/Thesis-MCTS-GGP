#include "strategy.h"

namespace Strategy
{

const int MAX_TURNS = 299; // Maximum number of turns we will account for in our calculations

const int* InitialiseTurnDepths()
{
    static int turnDepths[300];
    turnDepths[0] = -1;
    for (int i = 1; i <= 11; ++i) turnDepths[i] = 1;
    for (int i = 12; i <= 30; ++i) turnDepths[i] = 4;

    // for (int i = 31; i <= 299; ++i) turnDepths[i] = 6;

    // for (int i = 27; i <= 54; ++i) turnDepths[i] = 8;

    // for (int i = 55; i <= 299; ++i) turnDepths[i] = 8;
    return turnDepths;
}

const int* TURN_DEPTH = InitialiseTurnDepths();

template <>
int DepthFromTurn<CatchTheLion::CatchTheLionState>(const Games::GameState& gameState) 
{
    return TURN_DEPTH[gameState.GetTurn()];
};

}