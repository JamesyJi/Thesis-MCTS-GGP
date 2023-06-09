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

    using MoveT = Othello::OthelloMove;
    using StateT = Othello::OthelloState;
    using GameT = Models::Traits<StateT, MoveT>;

    resource = Common::TimeResource(1);

    using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model2T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnA<StateT>>;
    auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("othello_1vA");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 200);

    using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnA<StateT>>;
    using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("othello_Av1");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 200);

    using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnB<StateT>>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("othello_1vB");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 200);

    using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnB<StateT>>;
    using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("othello_Bv1");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 200);

    using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnC<StateT>>;
    auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("othello_1vC");
    resource = Common::TimeResource(1);
    manager4.StartExperiment(resource, 200);

    using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnC<StateT>>;
    using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("othello_Cv1");
    resource = Common::TimeResource(1);
    manager5.StartExperiment(resource, 200);

    using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnD<StateT>>;
    auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("othello_1vD");
    resource = Common::TimeResource(1);
    manager6.StartExperiment(resource, 200);

    using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnD<StateT>>;
    using Model16T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("othello_Dv1");
    resource = Common::TimeResource(1);
    manager7.StartExperiment(resource, 200);

    using Model17T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnE<StateT>>;
    auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("othello_1vE");
    resource = Common::TimeResource(1);
    manager8.StartExperiment(resource, 200);

    using Model19T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnE<StateT>>;
    using Model20T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth1>;
    auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("othello_Ev1");
    resource = Common::TimeResource(1);
    manager9.StartExperiment(resource, 200);

    // using Model21T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnF<StateT>>;
    // using Model22T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager10 = Main::GameManager<Model21T, Model22T, StateT, MoveT>("othello_Dv3_F");
    // resource = Common::TimeResource(1);
    // manager10.StartExperiment(resource, 200);

    // using Model23T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model24T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnF<StateT>>;
    // auto manager11 = Main::GameManager<Model23T, Model24T, StateT, MoveT>("othello_3vD_F");
    // resource = Common::TimeResource(1);
    // manager11.StartExperiment(resource, 200);

    // using Model25T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnG<StateT>>;
    // using Model26T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager12 = Main::GameManager<Model25T, Model26T, StateT, MoveT>("othello_Dv3_G");
    // resource = Common::TimeResource(1);
    // manager12.StartExperiment(resource, 200);

    // using Model27T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model28T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnG<StateT>>;
    // auto manager13 = Main::GameManager<Model27T, Model28T, StateT, MoveT>("othello_3vD_G");
    // resource = Common::TimeResource(1);
    // manager13.StartExperiment(resource, 200);

    // using Model29T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnH<StateT>>;
    // using Model30T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager14 = Main::GameManager<Model29T, Model30T, StateT, MoveT>("othello_Dv3_H");
    // resource = Common::TimeResource(1);
    // manager14.StartExperiment(resource, 200);

    // using Model31T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model32T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnH<StateT>>;
    // auto manager15 = Main::GameManager<Model31T, Model32T, StateT, MoveT>("othello_3vD_H");
    // resource = Common::TimeResource(1);
    // manager15.StartExperiment(resource, 200);

    // using Model33T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnI<StateT>>;
    // using Model34T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager16 = Main::GameManager<Model33T, Model34T, StateT, MoveT>("othello_Dv3_I");
    // resource = Common::TimeResource(1);
    // manager16.StartExperiment(resource, 200);

    // using Model35T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model36T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnI<StateT>>;
    // auto manager17 = Main::GameManager<Model35T, Model36T, StateT, MoveT>("othello_3vD_I");
    // resource = Common::TimeResource(1);
    // manager17.StartExperiment(resource, 200);

    // using Model37T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnJ<StateT>>;
    // using Model38T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager18 = Main::GameManager<Model37T, Model38T, StateT, MoveT>("othello_Dv3_J");
    // resource = Common::TimeResource(1);
    // manager18.StartExperiment(resource, 200);

    // using Model39T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model40T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnJ<StateT>>;
    // auto manager19 = Main::GameManager<Model39T, Model40T, StateT, MoveT>("othello_3vD_J");
    // resource = Common::TimeResource(1);
    // manager19.StartExperiment(resource, 200);

    return 0;
}