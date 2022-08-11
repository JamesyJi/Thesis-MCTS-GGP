#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "catchthelion_state.h"
#include "connect4_state.h"
#include "breakthrough_state.h"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    // auto resource = Common::TimeResource(1);
    
    using MoveT = CatchTheLion::CatchTheLionMove;
    using StateT = CatchTheLion::CatchTheLionState;
    using GameT = Models::Traits<CatchTheLion::CatchTheLionState, CatchTheLion::CatchTheLionMove>;
    auto resource = Common::TimeResource(1);

    using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn<StateT>>;
    using Model2T = Models::Standard::Standard<GameT>;
    auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("catchthelion_DvS");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 30);

    using Model3T = Models::Standard::Standard<GameT>;
    using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn<StateT>>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("catchthelion_SvD");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 30);

    using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn<StateT>>;
    using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("catchthelion_Dv3");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 30);

    using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn<StateT>>;
    auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("catchthelion_3vD");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 30);



    // using Model9T = Models::Standard::Standard<GameT>;
    // using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth2>;
    // auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("breakthrough_Sv2");
    // resource = Common::TimeResource(1);
    // manager4.StartExperiment(resource, 200);

    // using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model12T = Models::Standard::Standard<GameT>;
    // auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("breakthrough_3vS");
    // resource = Common::TimeResource(1);
    // manager5.StartExperiment(resource, 200);

    // using Model13T = Models::Standard::Standard<GameT>;
    // using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("breakthrough_Sv3");
    // resource = Common::TimeResource(1);
    // manager6.StartExperiment(resource, 200);

    // using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // using Model16T = Models::Standard::Standard<GameT>;
    // auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("breakthrough_4vS");
    // resource = Common::TimeResource(1);
    // manager7.StartExperiment(resource, 200);

    // using Model17T = Models::Standard::Standard<GameT>;
    // using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth4>;
    // auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("breakthrough_Sv4");
    // resource = Common::TimeResource(1);
    // manager8.StartExperiment(resource, 200);

    // using Model19T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // using Model20T = Models::Standard::Standard<GameT>;
    // auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("breakthrough_5vS");
    // resource = Common::TimeResource(1);
    // manager9.StartExperiment(resource, 200);

    // using Model21T = Models::Standard::Standard<GameT>;
    // using Model22T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth5>;
    // auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("breakthrough_Sv5");
    // resource = Common::TimeResource(1);
    // manager10.StartExperiment(resource, 200);

    // using Model23T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // using Model24T = Models::Standard::Standard<GameT>;
    // auto manager11 = Main::GameManager<Model23T, Model24T, StateT, MoveT>("breakthrough_6vS");
    // resource = Common::TimeResource(1);
    // manager11.StartExperiment(resource, 200);

    // using Model25T = Models::Standard::Standard<GameT>;
    // using Model26T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth6>;
    // auto manager12 = Main::GameManager<Model25T, Model26T, StateT, MoveT>("breakthrough_Sv6");
    // resource = Common::TimeResource(1);
    // manager12.StartExperiment(resource, 200);

    // using Model27T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // using Model28T = Models::Standard::Standard<GameT>;
    // auto manager13 = Main::GameManager<Model27T, Model28T, StateT, MoveT>("breakthrough_7vS");
    // resource = Common::TimeResource(1);
    // manager13.StartExperiment(resource, 200);

    // using Model29T = Models::Standard::Standard<GameT>;
    // using Model30T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth7>;
    // auto manager14 = Main::GameManager<Model29T, Model30T, StateT, MoveT>("breakthrough_Sv7");
    // resource = Common::TimeResource(1);
    // manager14.StartExperiment(resource, 200);

    // using Model31T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    // using Model32T = Models::Standard::Standard<GameT>;
    // auto manager15 = Main::GameManager<Model31T, Model32T, StateT, MoveT>("breakthrough_8vS");
    // resource = Common::TimeResource(1);
    // manager15.StartExperiment(resource, 200);

    // using Model33T = Models::Standard::Standard<GameT>;
    // using Model34T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth8>;
    // auto manager16 = Main::GameManager<Model33T, Model34T, StateT, MoveT>("breakthrough_Sv8");
    // resource = Common::TimeResource(1);
    // manager16.StartExperiment(resource, 200);

    return 0;
}