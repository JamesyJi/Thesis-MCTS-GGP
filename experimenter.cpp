#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "connect4_state.h"

int main(void)
{
    srand(time(NULL));
    
    using s = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;
    auto manager = Main::GameManager<Models::Minimax::MinimaxSelection<s>, Models::Minimax::MinimaxSelection<s>, Connect4::Connect4State, Connect4::Connect4Move>();
    auto resource = Common::IterationResource(100000);
    // auto resource = Common::TimeResource(10);
    manager.StartExperiment(resource, 1);

    return 0;
}