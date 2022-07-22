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
    // auto resource = Common::TimeResource(1);
    
    using MoveT = Breakthrough::BreakthroughMove;
    using StateT = Breakthrough::BreakthroughState;
    using GameT = Models::Traits<Breakthrough::BreakthroughState, Breakthrough::BreakthroughMove>;
    // using Model1T = Models::Detector::TerminalDetector<GameT>;
    // using Model2T = Models::Detector::TerminalDetector<GameT>;
    auto resource = Common::TimeResource(1);
    // auto manager = Main::GameManager<Model1T, Model2T, StateT, MoveT>("breakthrough_terminal");
    // manager.StartExperiment(resource, 100);

    using ModelT = Models::Standard::Standard<GameT>;
    using Model0T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager = Main::GameManager<ModelT, Model0T, StateT, MoveT>("test");
    auto resourceIter = Common::IterationResource(100000);
    manager.StartExperiment(resourceIter, 1);

    // using Model1T = Models::Standard::Standard<GameT>;
    // using Model2T = Models::Standard::Standard<GameT>;
    // auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("breakthrough_SvS");
    // resource = Common::TimeResource(1);
    // manager0.StartExperiment(resource, 100);

    // using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("breakthrough_6v7");
    // resource = Common::TimeResource(1);
    // manager1.StartExperiment(resource, 100);

    // using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("breakthrough_7v6");
    // resource = Common::TimeResource(1);
    // manager2.StartExperiment(resource, 100);

    // using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("breakthrough_4v6");
    // resource = Common::TimeResource(1);
    // manager3.StartExperiment(resource, 100);

    // using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("breakthrough_6v4");
    // resource = Common::TimeResource(1);
    // manager4.StartExperiment(resource, 100);

    // using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("breakthrough_5v7");
    // resource = Common::TimeResource(1);
    // manager5.StartExperiment(resource, 100);

    // using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("breakthrough_7v5");
    // resource = Common::TimeResource(1);
    // manager6.StartExperiment(resource, 100);

    // using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // using Model16T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("breakthrough_5v6");
    // resource = Common::TimeResource(1);
    // manager7.StartExperiment(resource, 100);

    // using Model17T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("breakthrough_6v5");
    // resource = Common::TimeResource(1);
    // manager8.StartExperiment(resource, 100);

<<<<<<< HEAD
    using Model21T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    using Model22T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("breakthrough_8v6");
    resource = Common::TimeResource(1);
    manager10.StartExperiment(resource, 100);
=======
    // using Model19T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model20T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    // auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("breakthrough_6v8");
    // resource = Common::TimeResource(1);
    // manager9.StartExperiment(resource, 100);

    // using Model21T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model22T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    // auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("breakthrough_8v6");
    // resource = Common::TimeResource(1);
    // manager10.StartExperiment(resource, 100);
>>>>>>> breakthrough-debug

    return 0;
}