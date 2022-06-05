#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "connect4_state.h"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    
    using MoveT = Connect4::Connect4Move;
    using StateT = Connect4::Connect4State;
    using GameT = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;
    using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model2T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn<StateT>>;

    auto manager = Main::GameManager<Model1T, Model2T, StateT, MoveT>();
    // auto resource = Common::IterationResource(100000);
    auto resource = Common::TimeResource(0.3);
    manager.StartExperiment(resource, 10);

    return 0;
}