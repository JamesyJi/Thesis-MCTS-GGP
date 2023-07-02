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

    using Connect4MoveT = Othello::OthelloMove;
    using Connect4StateT = Othello::OthelloState;
    using Connect4GameT = Models::Traits<Connect4StateT, Connect4MoveT>;

    resource = Common::TimeResource(1);

    using Model1T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model2T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnA<Connect4StateT>>;
    auto manager0 = Main::GameManager<Model1T, Model2T, Connect4StateT, Connect4MoveT>("connect4_1vA");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 200);

    using Model3T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnA<Connect4StateT>>;
    using Model4T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager1 = Main::GameManager<Model3T, Model4T, Connect4StateT, Connect4MoveT>("connect4_Av1");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 200);

    using Model5T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model6T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnB<Connect4StateT>>;
    auto manager2 = Main::GameManager<Model5T, Model6T, Connect4StateT, Connect4MoveT>("connect4_1vB");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 200);

    using Model7T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnB<Connect4StateT>>;
    using Model8T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager3 = Main::GameManager<Model7T, Model8T, Connect4StateT, Connect4MoveT>("connect4_Bv1");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 200);

    using Model9T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model10T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnC<Connect4StateT>>;
    auto manager4 = Main::GameManager<Model9T, Model10T, Connect4StateT, Connect4MoveT>("connect4_1vC");
    resource = Common::TimeResource(1);
    manager4.StartExperiment(resource, 200);

    using Model11T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnC<Connect4StateT>>;
    using Model12T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager5 = Main::GameManager<Model11T, Model12T, Connect4StateT, Connect4MoveT>("connect4_Cv1");
    resource = Common::TimeResource(1);
    manager5.StartExperiment(resource, 200);

    using Model13T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model14T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnD<Connect4StateT>>;
    auto manager6 = Main::GameManager<Model13T, Model14T, Connect4StateT, Connect4MoveT>("connect4_1vD");
    resource = Common::TimeResource(1);
    manager6.StartExperiment(resource, 200);

    using Model15T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnD<Connect4StateT>>;
    using Model16T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager7 = Main::GameManager<Model15T, Model16T, Connect4StateT, Connect4MoveT>("connect4_Dv1");
    resource = Common::TimeResource(1);
    manager7.StartExperiment(resource, 200);

    using Model17T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model18T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnE<Connect4StateT>>;
    auto manager8 = Main::GameManager<Model17T, Model18T, Connect4StateT, Connect4MoveT>("connect4_1vE");
    resource = Common::TimeResource(1);
    manager8.StartExperiment(resource, 200);

    using Model19T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnE<Connect4StateT>>;
    using Model20T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager9 = Main::GameManager<Model19T, Model20T, Connect4StateT, Connect4MoveT>("connect4_Ev1");
    resource = Common::TimeResource(1);
    manager9.StartExperiment(resource, 200);

    using Model21T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnF<Connect4StateT>>;
    using Model22T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager10 = Main::GameManager<Model21T, Model22T, Connect4StateT, Connect4MoveT>("connect4_Fv1");
    resource = Common::TimeResource(1);
    manager10.StartExperiment(resource, 200);

    using Model23T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model24T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnF<Connect4StateT>>;
    auto manager11 = Main::GameManager<Model23T, Model24T, Connect4StateT, Connect4MoveT>("connect4_1vF");
    resource = Common::TimeResource(1);
    manager11.StartExperiment(resource, 200);

    using Model25T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnG<Connect4StateT>>;
    using Model26T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager12 = Main::GameManager<Model25T, Model26T, Connect4StateT, Connect4MoveT>("connect4_Gv1");
    resource = Common::TimeResource(1);
    manager12.StartExperiment(resource, 200);

    using Model27T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model28T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnG<Connect4StateT>>;
    auto manager13 = Main::GameManager<Model27T, Model28T, Connect4StateT, Connect4MoveT>("connect4_1vG");
    resource = Common::TimeResource(1);
    manager13.StartExperiment(resource, 200);

    using Model29T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnH<Connect4StateT>>;
    using Model30T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager14 = Main::GameManager<Model29T, Model30T, Connect4StateT, Connect4MoveT>("connect4_Hv1");
    resource = Common::TimeResource(1);
    manager14.StartExperiment(resource, 200);

    using Model31T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model32T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnH<Connect4StateT>>;
    auto manager15 = Main::GameManager<Model31T, Model32T, Connect4StateT, Connect4MoveT>("connect4_1vH");
    resource = Common::TimeResource(1);
    manager15.StartExperiment(resource, 200);

    using Model33T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnI<Connect4StateT>>;
    using Model34T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager16 = Main::GameManager<Model33T, Model34T, Connect4StateT, Connect4MoveT>("connect4_Iv1");
    resource = Common::TimeResource(1);
    manager16.StartExperiment(resource, 200);

    using Model35T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model36T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnI<Connect4StateT>>;
    auto manager17 = Main::GameManager<Model35T, Model36T, Connect4StateT, Connect4MoveT>("connect4_1vI");
    resource = Common::TimeResource(1);
    manager17.StartExperiment(resource, 200);

    using Model37T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnJ<Connect4StateT>>;
    using Model38T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    auto manager18 = Main::GameManager<Model37T, Model38T, Connect4StateT, Connect4MoveT>("connect4_Jv1");
    resource = Common::TimeResource(1);
    manager18.StartExperiment(resource, 200);

    using Model39T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::FixedDepth1>;
    using Model40T = Models::Minimax::MinimaxSelection<Connect4GameT, Strategy::DepthFromTurnJ<Connect4StateT>>;
    auto manager19 = Main::GameManager<Model39T, Model40T, Connect4StateT, Connect4MoveT>("connect4_1vJ");
    resource = Common::TimeResource(1);
    manager19.StartExperiment(resource, 200);

    using CatchTheLionMoveT = CatchTheLion::CatchTheLionMove;
    using CatchTheLionStateT = CatchTheLion::CatchTheLionState;
    using CatchTheLionGameT = Models::Traits<CatchTheLionStateT, CatchTheLionMoveT>;

    using Model41T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    using Model42T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnA<CatchTheLionStateT>>;
    auto manager20 = Main::GameManager<Model41T, Model42T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_1vA");
    resource = Common::TimeResource(1);
    manager20.StartExperiment(resource, 200);

    using Model43T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnA<CatchTheLionStateT>>;
    using Model44T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    auto manager21 = Main::GameManager<Model43T, Model44T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_Av1");
    resource = Common::TimeResource(1);
    manager21.StartExperiment(resource, 200);

    using Model45T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    using Model46T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnB<CatchTheLionStateT>>;
    auto manager22 = Main::GameManager<Model45T, Model46T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_1vB");
    resource = Common::TimeResource(1);
    manager22.StartExperiment(resource, 200);

    using Model47T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnB<CatchTheLionStateT>>;
    using Model48T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    auto manager23 = Main::GameManager<Model47T, Model48T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_Bv1");
    resource = Common::TimeResource(1);
    manager23.StartExperiment(resource, 200);

    using Model49T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    using Model50T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnC<CatchTheLionStateT>>;
    auto manager24 = Main::GameManager<Model49T, Model50T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_1vC");
    resource = Common::TimeResource(1);
    manager24.StartExperiment(resource, 200);

    using Model51T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnC<CatchTheLionStateT>>;
    using Model52T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    auto manager25 = Main::GameManager<Model51T, Model52T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_Cv1");
    resource = Common::TimeResource(1);
    manager25.StartExperiment(resource, 200);

    using Model53T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    using Model54T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnD<CatchTheLionStateT>>;
    auto manager26 = Main::GameManager<Model53T, Model54T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_1vD");
    resource = Common::TimeResource(1);
    manager26.StartExperiment(resource, 200);

    using Model55T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnD<CatchTheLionStateT>>;
    using Model56T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    auto manager27 = Main::GameManager<Model55T, Model56T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_Dv1");
    resource = Common::TimeResource(1);
    manager27.StartExperiment(resource, 200);

    using Model57T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    using Model58T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnE<CatchTheLionStateT>>;
    auto manager28 = Main::GameManager<Model57T, Model58T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_1vE");
    resource = Common::TimeResource(1);
    manager28.StartExperiment(resource, 200);

    using Model59T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnE<CatchTheLionStateT>>;
    using Model60T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    auto manager29 = Main::GameManager<Model59T, Model60T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_Ev1");
    resource = Common::TimeResource(1);
    manager29.StartExperiment(resource, 200);

    using Model61T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnF<CatchTheLionStateT>>;
    using Model62T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    auto manager30 = Main::GameManager<Model61T, Model62T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_Fv1");
    resource = Common::TimeResource(1);
    manager30.StartExperiment(resource, 200);

    using Model63T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::FixedDepth1>;
    using Model64T = Models::Minimax::MinimaxSelection<CatchTheLionGameT, Strategy::DepthFromTurnF<CatchTheLionStateT>>;
    auto manager31 = Main::GameManager<Model63T, Model64T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_1vF");
    resource = Common::TimeResource(1);
    manager31.StartExperiment(resource, 200);

    using BreakthroughMoveT = Breakthrough::BreakthroughMove;
    using BreakthroughStateT = Breakthrough::BreakthroughState;
    using BreakthroughGameT = Models::Traits<BreakthroughStateT, BreakthroughMoveT>;

    using Model65T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model66T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnA<BreakthroughStateT>>;
    auto manager32 = Main::GameManager<Model65T, Model66T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vA");
    resource = Common::TimeResource(1);
    manager32.StartExperiment(resource, 200);

    using Model67T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnA<BreakthroughStateT>>;
    using Model68T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager33 = Main::GameManager<Model67T, Model68T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Av1");
    resource = Common::TimeResource(1);
    manager33.StartExperiment(resource, 200);

    using Model69T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model70T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnB<BreakthroughStateT>>;
    auto manager34 = Main::GameManager<Model69T, Model70T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vB");
    resource = Common::TimeResource(1);
    manager34.StartExperiment(resource, 200);

    using Model71T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnB<BreakthroughStateT>>;
    using Model72T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager35 = Main::GameManager<Model71T, Model72T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Bv1");
    resource = Common::TimeResource(1);
    manager35.StartExperiment(resource, 200);

    using Model73T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model74T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnC<BreakthroughStateT>>;
    auto manager36 = Main::GameManager<Model73T, Model74T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vC");
    resource = Common::TimeResource(1);
    manager36.StartExperiment(resource, 200);

    using Model75T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnC<BreakthroughStateT>>;
    using Model76T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager37 = Main::GameManager<Model75T, Model76T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Cv1");
    resource = Common::TimeResource(1);
    manager37.StartExperiment(resource, 200);

    using Model77T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model78T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnD<BreakthroughStateT>>;
    auto manager38 = Main::GameManager<Model77T, Model78T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vD");
    resource = Common::TimeResource(1);
    manager38.StartExperiment(resource, 200);

    using Model79T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnD<BreakthroughStateT>>;
    using Model80T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager39 = Main::GameManager<Model79T, Model80T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Dv1");
    resource = Common::TimeResource(1);
    manager39.StartExperiment(resource, 200);

    using Model81T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model82T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnE<BreakthroughStateT>>;
    auto manager40 = Main::GameManager<Model81T, Model82T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vE");
    resource = Common::TimeResource(1);
    manager40.StartExperiment(resource, 200);

    using Model83T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnE<BreakthroughStateT>>;
    using Model84T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager41 = Main::GameManager<Model83T, Model84T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Ev1");
    resource = Common::TimeResource(1);
    manager41.StartExperiment(resource, 200);

    using Model85T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnF<BreakthroughStateT>>;
    using Model86T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager42 = Main::GameManager<Model85T, Model86T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Fv1");
    resource = Common::TimeResource(1);
    manager42.StartExperiment(resource, 200);

    using Model87T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model88T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnF<BreakthroughStateT>>;
    auto manager43 = Main::GameManager<Model87T, Model88T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vF");
    resource = Common::TimeResource(1);
    manager43.StartExperiment(resource, 200);

    using Model89T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model90T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnE<BreakthroughStateT>>;
    auto manager44 = Main::GameManager<Model89T, Model90T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vG");
    resource = Common::TimeResource(1);
    manager44.StartExperiment(resource, 200);

    using Model91T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnE<BreakthroughStateT>>;
    using Model92T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager45 = Main::GameManager<Model91T, Model92T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Gv1");
    resource = Common::TimeResource(1);
    manager45.StartExperiment(resource, 200);

    using Model93T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnF<BreakthroughStateT>>;
    using Model94T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    auto manager46 = Main::GameManager<Model93T, Model94T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_Hv1");
    resource = Common::TimeResource(1);
    manager46.StartExperiment(resource, 200);

    using Model95T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::FixedDepth1>;
    using Model96T = Models::Minimax::MinimaxSelection<BreakthroughGameT, Strategy::DepthFromTurnF<BreakthroughStateT>>;
    auto manager47 = Main::GameManager<Model95T, Model96T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_1vH");
    resource = Common::TimeResource(1);
    manager47.StartExperiment(resource, 200);



    return 0;
}