#pragma once

#include <common/game_types.h>

#include <memory>

namespace MCTS
{

template<typename TState, typename TMove>
class Node
{
public:
    Node(std::unique_ptr<TState> state, Common::Player player, Node* parent, const TMove& lastMove)
    : mState(std::move(state))
    , mPlayerTurn(player)
    , mParent(parent)
    , mLastMove(lastMove)
    {}

    Node& GetRandomChild() const;
    Node& GetMostVisitedChild() const;
    Node& GetHighestScoreChild() const;
    void ExpandNode();
    double GetNodeScore() const;
    Node& GetChild(TMove& opponentMove) const;
    bool HasChildren() const;

    void NullParent()
    {
        mParent = nullptr;
    }

    void IncrValue()
    {
        ++mValue;
    }

    void DecrValue()
    {
        --mValue;
    }

    void Visit()
    {
        ++mVisits;
    }

    Node* GetParent() const
    {
        return mParent;
    }

    TState& GetState() const
    {
        return mState;
    }

    int GetVisits() const
    {
        return mVisits;
    }

    TMove& GetLastMove() const
    {
        return mLastMove;
    }

    Common::Player GetPlayerTurn() const
    {
        return mPlayerTurn;
    }

private:
    std::unique_ptr<TState> mState;
    Node* const mParent = nullptr;
    std::unique_ptr<Node> mChildren[TState::MAX_MOVES];
    int mNumChildren = 0;

    double mValue = 0;
    int mVisits = 0;

    const TMove mLastMove;
    Common::Player mPlayerTurn;
};

}
