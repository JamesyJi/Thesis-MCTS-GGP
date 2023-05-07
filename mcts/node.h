#pragma once

#include <memory>

#include "game_types.h"

namespace MCTS
{

template<typename TState, typename TMove>
class Node
{
public:
    Node(const TState& state, Common::Player player, Node* parent, const TMove& lastMove, std::size_t depth)
        : mState(state)
        , mParent(parent)
        , mLastMove(lastMove)
        , mPlayerTurn(player)
        , mDepth(depth)
    {}

    Node& GetRandomChild() const;
    int GetNumChildren() const;
    std::unique_ptr<Node> DecideOnBestChild();
    Node& GetHighestScoreChild() const;
    int ExpandNode();
    double GetNodeScore() const;
    std::unique_ptr<Node> GetChild(TMove& opponentMove);
    bool HasChildren() const;
    bool TryProveWinFromChildren();

    void NullParent()
    {
        mParent = nullptr;
    }

    template<Common::Proven R>
    void ProveResult()
    {
        mProven = R;
        if constexpr (R == Common::Proven::WIN)
        {
            mValue = std::numeric_limits<double>::max();
        }
        else if constexpr (R == Common::Proven::LOSS)
        {
            mValue = std::numeric_limits<double>::lowest();
        }
    }

    bool IsProven() const
    {
        return mProven != Common::Proven::NONE;
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

    inline bool AlreadyMinimaxed() const
    {
        return mAlreadyMinimaxed;
    }

    inline void FlagAsAlreadyMinimaxed()
    {
        mAlreadyMinimaxed = true;
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

    Common::Proven GetProven() const
    {
        return mProven;
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

    std::size_t GetDepth() const {
        return mDepth;
    }

    Node* GetChild(int index) const
    {
        return mChildren[index].get();
    }

    void LogChildStats() const
    {
        for (int i = 0; i < mNumChildren; ++i)
        {
            std::cout << "value " << mChildren[i]->GetValue() << " visits " << mChildren[i]->GetVisits() << " score " << mChildren[i]->GetNodeScore() << "\n";
            std::cout << mChildren[i]->GetStateRef();
        }
    }

    int GetBranchingFactor() const {
        if (mExpanded) {
            return mNumChildren;
        }

        std::runtime_error("GetBranchingFactor called on unexpanded node");
    }
private:
    TState mState;
    Node* mParent = nullptr;
    std::unique_ptr<Node> mChildren[TState::MAX_MOVES];
    int mNumChildren = 0; // This is set by expand node...
    bool mExpanded = false; // Set to true when expanded

    Common::Proven mProven = Common::Proven::NONE;
    double mValue = 0;
    int mVisits = 0;

    // True if we have already minimaxed at this node
    bool mAlreadyMinimaxed = false;

    const TMove mLastMove;
    Common::Player mPlayerTurn;

    // Starting at 1 for the original root of the Tree
    std::size_t mDepth;
};

}
