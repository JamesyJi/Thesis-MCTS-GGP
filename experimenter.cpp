#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "detector/terminal_detector.h"
#include "connect4_state.h"
#include "breakthrough_state.h"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    
    using MoveT = Breakthrough::BreakthroughMove;
    using StateT = Breakthrough::BreakthroughState;
    using GameT = Models::Traits<Breakthrough::BreakthroughState, Breakthrough::BreakthroughMove>;
    // using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model2T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model1T = Models::Standard::Standard<GameT>;
    using Model2T = Models::Standard::Standard<GameT>;
    // using Model1T = Models::Detector::TerminalDetector<GameT>;
    // using Model2T = Models::Detector::TerminalDetector<GameT>;

    auto manager = Main::GameManager<Model1T, Model2T, StateT, MoveT>();
    // auto resource = Common::IterationResource(100000);
    auto resource = Common::TimeResource(5);
    manager.StartExperiment(resource, 1);

    return 0;
}