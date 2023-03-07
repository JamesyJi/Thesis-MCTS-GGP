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

    using MoveT = Connect4::Connect4Move;
    using StateT = Connect4::Connect4State;
    using GameT = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;
    // auto resource = Common::TimeResource(1);

    using Model1T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn4<StateT>>;
    using Model2T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager0 = Main::GameManager<Model1T, Model2T, StateT, MoveT>("connect4_Dv3_4");
    resource = Common::TimeResource(1);
    manager0.StartExperiment(resource, 100);

    using Model3T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model4T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn4<StateT>>;
    auto manager1 = Main::GameManager<Model3T, Model4T, StateT, MoveT>("connect4_3vD_4");
    resource = Common::TimeResource(1);
    manager1.StartExperiment(resource, 100);

    using Model5T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn5<StateT>>;
    using Model6T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager2 = Main::GameManager<Model5T, Model6T, StateT, MoveT>("connect4_Dv3_5");
    resource = Common::TimeResource(1);
    manager2.StartExperiment(resource, 100);

    using Model7T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model8T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn5<StateT>>;
    auto manager3 = Main::GameManager<Model7T, Model8T, StateT, MoveT>("connect4_3vD_5");
    resource = Common::TimeResource(1);
    manager3.StartExperiment(resource, 100);

    using Model9T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn6<StateT>>;
    using Model10T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager4 = Main::GameManager<Model9T, Model10T, StateT, MoveT>("connect4_Dv3_6");
    resource = Common::TimeResource(1);
    manager4.StartExperiment(resource, 100);

    using Model11T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model12T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn6<StateT>>;
    auto manager5 = Main::GameManager<Model11T, Model12T, StateT, MoveT>("connect4_3vD_6");
    resource = Common::TimeResource(1);
    manager5.StartExperiment(resource, 100);

    using Model13T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn7<StateT>>;
    using Model14T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    auto manager6 = Main::GameManager<Model13T, Model14T, StateT, MoveT>("connect4_Dv3_7");
    resource = Common::TimeResource(1);
    manager6.StartExperiment(resource, 100);

    using Model15T = Models::Minimax::MinimaxSelection<GameT, Strategy::FixedDepth3>;
    using Model16T = Models::Minimax::MinimaxSelection<GameT, Strategy::DepthFromTurn7<StateT>>;
    auto manager7 = Main::GameManager<Model15T, Model16T, StateT, MoveT>("connect4_3vD_7");
    resource = Common::TimeResource(1);
    manager7.StartExperiment(resource, 100);

    return 0;
}