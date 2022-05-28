#pragma once

#include <memory>

#include "game_types.h"

namespace MCTS
{

template<typename TState, typename TMove>
class Node
{
public:
    Node(const TState& state, Common::Player player, Node* parent, const TMove& lastMove)
    : mState(state)
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
    bool TryProveWinFromChildren();

    void NullParent()
    {
        mParent = nullptr;
    }

    void ProveResult(double value)
    {
        mProven = true;
        mValue = value;
        mVisits = std::numeric_limits<int>::max();
    }

    bool IsProven() const
    {
        return mProven;
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

    TState GetStateCopy() const
    {
        return mState;
    }

    TState& GetStateRef()
    {
        return mState;
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
            std::cout << mChildren[i]->GetStateRef();
        }
    }

private:
    TState mState;
    Node* mParent = nullptr;
    std::unique_ptr<Node> mChildren[TState::MAX_MOVES];
    int mNumChildren = 0;

    bool mProven = false; // Toggle to true when we have proven the result so no need to adjust value
    double mValue = 0;
    int mVisits = 0;

    const TMove mLastMove;
    Common::Player mPlayerTurn;
};

}
