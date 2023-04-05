#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "minimax/minimax_rollout.h"
#include "othello_state.h"
#include "breakthrough_state.h"
#include "breakthrough_state.h"
#include "linesofaction_state.hpp"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    auto resource = Common::TimeResource(1);

    using MoveT = Breakthrough::BreakthroughMove;
    using StateT = Breakthrough::BreakthroughState;
    using GameT = Models::Traits<StateT, MoveT>;

    resource = Common::TimeResource(1);

    using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnA<StateT>>;
    using Model2T = Models::Standard::Standard<GameT>;
    auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("breakthrough_DvS_A");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 200);

    using Model3T = Models::Standard::Standard<GameT>;
    using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnA<StateT>>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("breakthrough_SvD_A");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 200);

    using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnB<StateT>>;
    using Model6T = Models::Standard::Standard<GameT>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("breakthrough_DvS_B");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 200);

    using Model7T = Models::Standard::Standard<GameT>;
    using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnB<StateT>>;
    auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("breakthrough_SvD_B");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 200);

    using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnC<StateT>>;
    using Model10T = Models::Standard::Standard<GameT>;
    auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("breakthrough_DvS_C");
    resource = Common::TimeResource(1);
    manager4.StartExperiment(resource, 200);

    using Model11T = Models::Standard::Standard<GameT>;
    using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnC<StateT>>;
    auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("breakthrough_SvD_C");
    resource = Common::TimeResource(1);
    manager5.StartExperiment(resource, 200);

    using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnD<StateT>>;
    using Model14T = Models::Standard::Standard<GameT>;
    auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("breakthrough_DvS_D");
    resource = Common::TimeResource(1);
    manager6.StartExperiment(resource, 200);

    using Model15T = Models::Standard::Standard<GameT>;
    using Model16T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnD<StateT>>;
    auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("breakthrough_SvD_D");
    resource = Common::TimeResource(1);
    manager7.StartExperiment(resource, 200);

    using Model17T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnE<StateT>>;
    using Model18T = Models::Standard::Standard<GameT>;
    auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("breakthrough_DvS_E");
    resource = Common::TimeResource(1);
    manager8.StartExperiment(resource, 200);

    using Model19T = Models::Standard::Standard<GameT>;
    using Model20T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnE<StateT>>;
    auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("breakthrough_SvD_E");
    resource = Common::TimeResource(1);
    manager9.StartExperiment(resource, 200);

    using Model21T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnF<StateT>>;
    using Model22T = Models::Standard::Standard<GameT>;
    auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("breakthrough_DvS_F");
    resource = Common::TimeResource(1);
    manager10.StartExperiment(resource, 200);

    using Model23T = Models::Standard::Standard<GameT>;
    using Model24T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnF<StateT>>;
    auto manager11 = Main::GameManager<Model23T, Model24T, StateT, MoveT>("breakthrough_SvD_F");
    resource = Common::TimeResource(1);
    manager11.StartExperiment(resource, 200);

    using Model25T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnG<StateT>>;
    using Model26T = Models::Standard::Standard<GameT>;
    auto manager12 = Main::GameManager<Model25T, Model26T, StateT, MoveT>("breakthrough_DvS_G");
    resource = Common::TimeResource(1);
    manager12.StartExperiment(resource, 200);

    using Model27T = Models::Standard::Standard<GameT>;
    using Model28T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnG<StateT>>;
    auto manager13 = Main::GameManager<Model27T, Model28T, StateT, MoveT>("breakthrough_SvD_G");
    resource = Common::TimeResource(1);
    manager13.StartExperiment(resource, 200);

    using Model29T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnH<StateT>>;
    using Model30T = Models::Standard::Standard<GameT>;
    auto manager14 = Main::GameManager<Model29T, Model30T, StateT, MoveT>("breakthrough_DvS_H");
    resource = Common::TimeResource(1);
    manager14.StartExperiment(resource, 200);

    using Model31T = Models::Standard::Standard<GameT>;
    using Model32T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnH<StateT>>;
    auto manager15 = Main::GameManager<Model31T, Model32T, StateT, MoveT>("breakthrough_SvD_H");
    resource = Common::TimeResource(1);
    manager15.StartExperiment(resource, 200);

    // using Model33T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnI<StateT>>;
    // using Model34T = Models::Standard::Standard<GameT>;
    // auto manager16 = Main::GameManager<Model33T, Model34T, StateT, MoveT>("breakthrough_DvS_I");
    // resource = Common::TimeResource(1);
    // manager16.StartExperiment(resource, 200);

    // using Model35T = Models::Standard::Standard<GameT>;
    // using Model36T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnI<StateT>>;
    // auto manager17 = Main::GameManager<Model35T, Model36T, StateT, MoveT>("breakthrough_SvD_I");
    // resource = Common::TimeResource(1);
    // manager17.StartExperiment(resource, 200);

    // using Model37T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnJ<StateT>>;
    // using Model38T = Models::Standard::Standard<GameT>;
    // auto manager18 = Main::GameManager<Model37T, Model38T, StateT, MoveT>("breakthrough_DvS_J");
    // resource = Common::TimeResource(1);
    // manager18.StartExperiment(resource, 200);

    // using Model39T = Models::Standard::Standard<GameT>;
    // using Model40T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnJ<StateT>>;
    // auto manager19 = Main::GameManager<Model39T, Model40T, StateT, MoveT>("breakthrough_SvD_J");
    // resource = Common::TimeResource(1);
    // manager19.StartExperiment(resource, 200);

    return 0;
}