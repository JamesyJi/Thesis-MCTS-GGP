#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "detector/terminal_detector.h"
#include "connect4_state.h"
#include "breakthrough_state.h"
#include "othello_state.h"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    
    using MoveT = Connect4::Connect4Move;
    using StateT = Connect4::Connect4State;
    using GameT = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;
    // using Model1T = Models::Detector::TerminalDetector<GameT>;
    // using Model2T = Models::Detector::TerminalDetector<GameT>;
    auto resource = Common::TimeResource(1);

    // using Model1T = Models::Standard::Standard<GameT>;
    // using Model2T = Models::Standard::Standard<GameT>;
    // auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("connect4_SvS");
    // resource = Common::TimeResource(1);
    // manager0.StartExperiment(resource, 100);

    using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("connect4_6v7");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 100);

    using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("connect4_7v6");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 100);

    // using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("connect4_4v6");
    // resource = Common::TimeResource(1);
    // manager3.StartExperiment(resource, 100);

    // using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("connect4_6v4");
    // resource = Common::TimeResource(1);
    // manager4.StartExperiment(resource, 100);

    // using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("connect4_5v7");
    // resource = Common::TimeResource(1);
    // manager5.StartExperiment(resource, 100);

    // using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("connect4_7v5");
    // resource = Common::TimeResource(1);
    // manager6.StartExperiment(resource, 100);

    // using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // using Model16T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("connect4_5v6");
    // resource = Common::TimeResource(1);
    // manager7.StartExperiment(resource, 100);

    // using Model17T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("connect4_6v5");
    // resource = Common::TimeResource(1);
    // manager8.StartExperiment(resource, 100);

    return 0;
}