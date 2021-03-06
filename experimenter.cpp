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

    // using ModelT = Models::Standard::Standard<GameT>;
    // using Model0T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // auto manager = Main::GameManager<ModelT, Model0T, StateT, MoveT>("test");
    // auto resourceIter = Common::IterationResource(100000);
    // manager.StartExperiment(resourceIter, 1);

    using Model1T = Models::Standard::Standard<GameT>;
    using Model2T = Models::Standard::Standard<GameT>;
    auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("breakthrough_SvS");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 100);

    using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model4T = Models::Standard::Standard<GameT>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("breakthrough_1vS");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 100);

    using Model5T = Models::Standard::Standard<GameT>;
    using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("breakthrough_Sv1");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 100);

    using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    using Model8T = Models::Standard::Standard<GameT>;
    auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("breakthrough_2vS");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 100);

    using Model9T = Models::Standard::Standard<GameT>;
    using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("breakthrough_Sv2");
    resource = Common::TimeResource(1);
    manager4.StartExperiment(resource, 100);

    using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model12T = Models::Standard::Standard<GameT>;
    auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("breakthrough_3vS");
    resource = Common::TimeResource(1);
    manager5.StartExperiment(resource, 100);

    using Model13T = Models::Standard::Standard<GameT>;
    using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("breakthrough_Sv3");
    resource = Common::TimeResource(1);
    manager6.StartExperiment(resource, 100);

    using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model16T = Models::Standard::Standard<GameT>;
    auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("breakthrough_4vS");
    resource = Common::TimeResource(1);
    manager7.StartExperiment(resource, 100);

    using Model17T = Models::Standard::Standard<GameT>;
    using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("breakthrough_Sv4");
    resource = Common::TimeResource(1);
    manager8.StartExperiment(resource, 100);

    using Model19T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model20T = Models::Standard::Standard<GameT>;
    auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("breakthrough_5vS");
    resource = Common::TimeResource(1);
    manager9.StartExperiment(resource, 100);

    using Model21T = Models::Standard::Standard<GameT>;
    using Model22T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("breakthrough_Sv5");
    resource = Common::TimeResource(1);
    manager10.StartExperiment(resource, 100);

    using Model23T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model24T = Models::Standard::Standard<GameT>;
    auto manager11 = Main::GameManager<Model23T, Model24T, StateT, MoveT>("breakthrough_6vS");
    resource = Common::TimeResource(1);
    manager11.StartExperiment(resource, 100);

    using Model25T = Models::Standard::Standard<GameT>;
    using Model26T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager12 = Main::GameManager<Model25T, Model26T, StateT, MoveT>("breakthrough_Sv6");
    resource = Common::TimeResource(1);
    manager12.StartExperiment(resource, 100);

    using Model27T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    using Model28T = Models::Standard::Standard<GameT>;
    auto manager13 = Main::GameManager<Model27T, Model28T, StateT, MoveT>("breakthrough_7vS");
    resource = Common::TimeResource(1);
    manager13.StartExperiment(resource, 100);

    using Model29T = Models::Standard::Standard<GameT>;
    using Model30T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    auto manager14 = Main::GameManager<Model29T, Model30T, StateT, MoveT>("breakthrough_Sv7");
    resource = Common::TimeResource(1);
    manager14.StartExperiment(resource, 100);

    using Model31T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    using Model32T = Models::Standard::Standard<GameT>;
    auto manager15 = Main::GameManager<Model31T, Model32T, StateT, MoveT>("breakthrough_8vS");
    resource = Common::TimeResource(1);
    manager15.StartExperiment(resource, 100);

    using Model33T = Models::Standard::Standard<GameT>;
    using Model34T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    auto manager16 = Main::GameManager<Model33T, Model34T, StateT, MoveT>("breakthrough_Sv8");
    resource = Common::TimeResource(1);
    manager16.StartExperiment(resource, 100);

    return 0;
}