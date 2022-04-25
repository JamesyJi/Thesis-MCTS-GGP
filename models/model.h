#ifndef MCTS_MODEL_H_
#define MCTS_MODEL_H_

#include <common/game_types.h>
#include <common/resource.h>
#include <mcts/state.h>
#include <mcts/node.h>

namespace Models
{

template<typename GameState, typename Move>
class Model
{
public:
    using GState = State<GameState, Move>;
    using GNode = Node<GameState, Move>;

    Model(Common::Player player, GState& state)
    : mPlayer(player)
    {}

    ~Model(){}

    GameState& DecideMove(Common::Resource&);

    virtual void ExecuteStrategy() = 0;


private:
    Common::Player mPlayer;
    GNode& mRoot;
};

}

#endif