#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "catchthelion_state.h"
#include "connect4_state.h"
#include "catchthelion_state.h"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    // auto resource = Common::TimeResource(1);
    
    using MoveT = CatchTheLion::CatchTheLionMove;
    using StateT = CatchTheLion::CatchTheLionState;
    using GameT = Models::Traits<CatchTheLion::CatchTheLionState, CatchTheLion::CatchTheLionMove>;
    auto resource = Common::TimeResource(1);

    // using Model1T = Models::Standard::Standard<GameT>;
    // using Model2T = Models::Standard::Standard<GameT>;
    // auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("catchthelion_SvS");
    // resource = Common::TimeResource(1);
    // manager0.StartExperiment(resource, 200);

    using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("catchthelion_1v2");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 200);

    using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("catchthelion_2v1");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 200);

    using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("catchthelion_1v3");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 200);

    using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("catchthelion_3v1");
    resource = Common::TimeResource(1);
    manager4.StartExperiment(resource, 200);

    using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("catchthelion_1v4");
    resource = Common::TimeResource(1);
    manager5.StartExperiment(resource, 200);

    using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("catchthelion_4v1");
    resource = Common::TimeResource(1);
    manager6.StartExperiment(resource, 200);

    using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model16T = Models::Standard::Standard<GameT>;
    auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("catchthelion_4vS");
    resource = Common::TimeResource(1);
    manager7.StartExperiment(resource, 200);

    using Model17T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("catchthelion_1v5");
    resource = Common::TimeResource(1);
    manager8.StartExperiment(resource, 200);

    using Model19T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model20T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("catchthelion_5v1");
    resource = Common::TimeResource(1);
    manager9.StartExperiment(resource, 200);

    using Model21T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model22T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("catchthelion_1v6");
    resource = Common::TimeResource(1);
    manager10.StartExperiment(resource, 200);

    using Model23T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model24T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager11 = Main::GameManager<Model23T, Model24T, StateT, MoveT>("catchthelion_6v1");
    resource = Common::TimeResource(1);
    manager11.StartExperiment(resource, 200);

    using Model25T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    using Model26T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager12 = Main::GameManager<Model25T, Model26T, StateT, MoveT>("catchthelion_2v3");
    resource = Common::TimeResource(1);
    manager12.StartExperiment(resource, 200);

    using Model27T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model28T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    auto manager13 = Main::GameManager<Model27T, Model28T, StateT, MoveT>("catchthelion_3v2");
    resource = Common::TimeResource(1);
    manager13.StartExperiment(resource, 200);

    using Model29T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    using Model30T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager14 = Main::GameManager<Model29T, Model30T, StateT, MoveT>("catchthelion_2v4");
    resource = Common::TimeResource(1);
    manager14.StartExperiment(resource, 200);

    using Model31T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model32T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    auto manager15 = Main::GameManager<Model31T, Model32T, StateT, MoveT>("catchthelion_4v2");
    resource = Common::TimeResource(1);
    manager15.StartExperiment(resource, 200);

    using Model33T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    using Model34T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    auto manager16 = Main::GameManager<Model33T, Model34T, StateT, MoveT>("catchthelion_2v5");
    resource = Common::TimeResource(1);
    manager16.StartExperiment(resource, 200);

    using Model35T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model36T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    auto manager17 = Main::GameManager<Model35T, Model36T, StateT, MoveT>("catchthelion_5v2");
    resource = Common::TimeResource(1);
    manager17.StartExperiment(resource, 200);

    using Model37T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    using Model38T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager18 = Main::GameManager<Model37T, Model38T, StateT, MoveT>("catchthelion_2v6");
    resource = Common::TimeResource(1);
    manager18.StartExperiment(resource, 200);

    using Model39T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model40T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    auto manager19 = Main::GameManager<Model39T, Model40T, StateT, MoveT>("catchthelion_6v2");
    resource = Common::TimeResource(1);
    manager19.StartExperiment(resource, 200);

    using Model41T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model42T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager20 = Main::GameManager<Model41T, Model42T, StateT, MoveT>("catchthelion_3v4");
    resource = Common::TimeResource(1);
    manager20.StartExperiment(resource, 200);

    using Model43T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model44T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager21 = Main::GameManager<Model43T, Model44T, StateT, MoveT>("catchthelion_4v3");
    resource = Common::TimeResource(1);
    manager21.StartExperiment(resource, 200);

    using Model45T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model46T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    auto manager22 = Main::GameManager<Model45T, Model46T, StateT, MoveT>("catchthelion_3v5");
    resource = Common::TimeResource(1);
    manager22.StartExperiment(resource, 200);

    using Model47T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model48T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager23 = Main::GameManager<Model47T, Model48T, StateT, MoveT>("catchthelion_5v3");
    resource = Common::TimeResource(1);
    manager23.StartExperiment(resource, 200);

    using Model49T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model50T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager24 = Main::GameManager<Model49T, Model50T, StateT, MoveT>("catchthelion_3v6");
    resource = Common::TimeResource(1);
    manager24.StartExperiment(resource, 200);

    using Model51T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model52T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager25 = Main::GameManager<Model51T, Model52T, StateT, MoveT>("catchthelion_6v3");
    resource = Common::TimeResource(1);
    manager25.StartExperiment(resource, 200);

    using Model53T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model54T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    auto manager26 = Main::GameManager<Model53T, Model54T, StateT, MoveT>("catchthelion_4v5");
    resource = Common::TimeResource(1);
    manager26.StartExperiment(resource, 200);

    using Model55T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model56T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager27 = Main::GameManager<Model55T, Model56T, StateT, MoveT>("catchthelion_5v4");
    resource = Common::TimeResource(1);
    manager27.StartExperiment(resource, 200);

    using Model57T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    using Model58T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager28 = Main::GameManager<Model57T, Model58T, StateT, MoveT>("catchthelion_4v6");
    resource = Common::TimeResource(1);
    manager28.StartExperiment(resource, 200);

    using Model59T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model60T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    auto manager29 = Main::GameManager<Model59T, Model60T, StateT, MoveT>("catchthelion_6v4");
    resource = Common::TimeResource(1);
    manager29.StartExperiment(resource, 200);

    using Model61T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    using Model62T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    auto manager30 = Main::GameManager<Model61T, Model62T, StateT, MoveT>("catchthelion_5v6");
    resource = Common::TimeResource(1);
    manager30.StartExperiment(resource, 200);

    using Model63T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    using Model64T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    auto manager31 = Main::GameManager<Model63T, Model64T, StateT, MoveT>("catchthelion_6v5");
    resource = Common::TimeResource(1);
    manager31.StartExperiment(resource, 200);

    return 0;
}