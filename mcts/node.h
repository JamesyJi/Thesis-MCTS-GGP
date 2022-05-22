#pragma once

#include <memory>

#include "game_types.h"

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
    std::unique_ptr<Node> GetMostVisitedChild();
    Node& GetHighestScoreChild() const;
    void ExpandNode();
    double GetNodeScore() const;
    std::unique_ptr<Node> GetChild(TMove& opponentMove);
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

    TState* GetState()
    {
        return mState.get();
    }

    double GetValue() const
    {
        return mValue;
    }

    int GetVisits() const
    {
        return mVisits;
    }

    const TMove& GetLastMove()
    {
        return mLastMove;
    }

    Common::Player GetPlayerTurn() const
    {
        return mPlayerTurn;
    }

    void LogChildStats() const
    {
        for (int i = 0; i < mNumChildren; ++i)
        {
            std::cout << "value " << mChildren[i]->GetValue() << " visits " << mChildren[i]->GetVisits() << " score " << mChildren[i]->GetNodeScore() << "\n";
            std::cout << *(mChildren[i]->GetState());
        }
    }

private:
    std::unique_ptr<TState> mState;
    Node* mParent = nullptr;
    std::unique_ptr<Node> mChildren[TState::MAX_MOVES];
    int mNumChildren = 0;

    double mValue = 0;
    int mVisits = 0;

    const TMove mLastMove;
    Common::Player mPlayerTurn;
};

}
