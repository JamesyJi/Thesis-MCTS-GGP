#ifndef MCTS_NODE_H_
#define MCTS_NODE_H_

#include <mcts/state.h>
#include <common/game_types.h>

namespace MCTS
{

template<typename GameState, typename Move>
class Node
{
public:
    using GState = State<GameState, Move>;

    Node(GState& state, Common::Player player, Node* parent, Move& lastMove)
    : mState(state)
    , mPlayerTurn(player)
    , mParent(parent)
    , mLastMove(lastMove)
    {}

    ~Node(){} // TODO

    Node& GetRandomChild();
    Node& GetMostVisitedChild();
    Node& GetHighestScoreChild();
    void ExpandNode();
    double GetNodeScore();
    Node& GetChild(Move& opponentMove);
    bool HasChildren();

    void NullParent()
    {
        mParent = nullptr;
    }

    GState& GetState()
    {
        return mState;
    }

    Move& GetLastMove()
    {
        return mLastMove;
    }

    Common::Player GetPlayerTurn()
    {
        return mPlayerTurn;
    }

private:
    GState& mState;
    Node* const mParent = nullptr;
    Node mChildren[GameState::MAX_MOVES];
    int mNumChildren = 0;

    double mValue = 0;
    int mVisits = 0;

    const Move mLastMove;
    Common::Player mPlayerTurn;
};

}

#endif