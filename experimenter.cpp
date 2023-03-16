#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "minimax/minimax_rollout.h"
#include "connect4_state.h"
#include "othello_state.h"
#include "breakthrough_state.h"
#include "catchthelion_state.h"
#include "strategy.h"

int main(void)
{
    srand(time(NULL));
    auto resource = Common::TimeResource(1);

    using Connect4MoveT = Connect4::Connect4Move;
    using Connect4StateT = Connect4::Connect4State;
    using Connect4GameT = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;

    using Model1T = Models::Standard::Standard<Connect4GameT>;
    using Model2T = Models::Standard::Standard<Connect4GameT>;
    auto manager0 = Main::GameManager<Model1T, Model2T, Connect4StateT, Connect4MoveT>("connect4_SvS");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 200);

    using OthelloMoveT = Othello::OthelloMove;
    using OthelloStateT = Othello::OthelloState;
    using OthelloGameT = Models::Traits<Othello::OthelloState, Othello::OthelloMove>;

    using Model5T = Models::Standard::Standard<OthelloGameT>;
    using Model6T = Models::Standard::Standard<OthelloGameT>;
    auto manager2 = Main::GameManager<Model5T, Model6T, OthelloStateT, OthelloMoveT>("othello_SvS");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 200);

    using BreakthroughMoveT = Breakthrough::BreakthroughMove;
    using BreakthroughStateT = Breakthrough::BreakthroughState;
    using BreakthroughGameT = Models::Traits<Breakthrough::BreakthroughState, Breakthrough::BreakthroughMove>;

    using Model3T = Models::Standard::Standard<BreakthroughGameT>;
    using Model4T = Models::Standard::Standard<BreakthroughGameT>;
    auto manager1 = Main::GameManager<Model3T, Model4T, BreakthroughStateT, BreakthroughMoveT>("breakthrough_SvS");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 200);

    using CatchTheLionMoveT = CatchTheLion::CatchTheLionMove;
    using CatchTheLionStateT = CatchTheLion::CatchTheLionState;
    using CatchTheLionGameT = Models::Traits<CatchTheLion::CatchTheLionState, CatchTheLion::CatchTheLionMove>;

    using Model7T = Models::Standard::Standard<CatchTheLionGameT>;
    using Model8T = Models::Standard::Standard<CatchTheLionGameT>;
    auto manager3 = Main::GameManager<Model7T, Model8T, CatchTheLionStateT, CatchTheLionMoveT>("catchthelion_SvS");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 200);


    // using MoveT = Connect4::Connect4Move;
    // using StateT = Connect4::Connect4State;
    // using GameT = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;
    // auto resource = Common::TimeResource(1);

    // using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnE<StateT>>;
    // using Model2T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("connect4_Dv3_E");
    // resource = Common::TimeResource(1);
    // manager0.StartExperiment(resource, 100);

    // using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnE<StateT>>;
    // auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("connect4_3vD_E");
    // resource = Common::TimeResource(1);
    // manager1.StartExperiment(resource, 100);

    // using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnF<StateT>>;
    // using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("connect4_Dv3_F");
    // resource = Common::TimeResource(1);
    // manager2.StartExperiment(resource, 100);

    // using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnF<StateT>>;
    // auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("connect4_3vD_F");
    // resource = Common::TimeResource(1);
    // manager3.StartExperiment(resource, 100);

    // using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnG<StateT>>;
    // using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("connect4_Dv3_G");
    // resource = Common::TimeResource(1);
    // manager4.StartExperiment(resource, 100);

    // using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnG<StateT>>;
    // auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("connect4_3vD_G");
    // resource = Common::TimeResource(1);
    // manager5.StartExperiment(resource, 100);

    // using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnH<StateT>>;
    // using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("connect4_Dv3_H");
    // resource = Common::TimeResource(1);
    // manager6.StartExperiment(resource, 100);

    // using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model16T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnH<StateT>>;
    // auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("connect4_3vD_H");
    // resource = Common::TimeResource(1);
    // manager7.StartExperiment(resource, 100);

    // using Model17T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnI2<StateT>>;
    // using Model18T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // auto manager8 = Main::GameManager<Model17T, Model18T, StateT, MoveT>("connect4_Dv3_I2");
    // resource = Common::TimeResource(1);
    // manager8.StartExperiment(resource, 100);

    // using Model19T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    // using Model20T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurnI2<StateT>>;
    // auto manager9 = Main::GameManager<Model19T, Model20T, StateT, MoveT>("connect4_3vD_I2");
    // resource = Common::TimeResource(1);
    // manager9.StartExperiment(resource, 100);

    return 0;
}