#include <limits>
#include <cmath>

#include "node.h"

namespace MCTS
{

// Assumption is that the node has children
template<typename TState, typename TMove>
Node<TState, TMove>& Node<TState, TMove>::GetRandomChild() const
{
    // TODO: Can use faster random
    if (mNumChildren == 0) {
        std::cout << "NO CHILDREN FOR NODE\n";
        std::cout << mState;
    }
    return *mChildren[rand() % mNumChildren].get();
}

// PRECONDITION: Node has children
// Returns the child node which will lead to the best outcome for the player of the current node
// 1. Looks for any nodes which are proven wins
// 2. Looks for most visited node
template<typename TState, typename TMove>
std::unique_ptr<Node<TState, TMove>> Node<TState, TMove>::DecideOnBestChild()
{
    for (int i = 0; i < mNumChildren; ++i)
    {
        if (mChildren[i]->GetProven() == Common::Proven::WIN)
        {
            return std::move(mChildren[i]);
        }
    }

    int maxIndex = -1;
    int maxVisits = 0;
    for (int i = 0; i < mNumChildren; ++i) 
    {
        if (mChildren[i]->GetVisits() > maxVisits) 
        {
            maxIndex = i;
            maxVisits = mChildren[i]->GetVisits();
        }
    }

    return std::move(mChildren[maxIndex]);
}

// Assumption is that the node has children
template<typename TState, typename TMove>
Node<TState, TMove>& Node<TState, TMove>::GetHighestScoreChild() const
{
    int maxIndex = 0;
    double maxScore = std::numeric_limits<double>::lowest();
    for (int i = 0; i < mNumChildren; ++i)
    {
        if (mChildren[i]->GetNodeScore() > maxScore)
        {
            maxIndex = i;
            maxScore = mChildren[i]->GetNodeScore();
        }
    }

    return *mChildren[maxIndex];
}


// Expands the node, adding all legal possible nodes as children
template<typename TState, typename TMove>
void Node<TState, TMove>::ExpandNode()
{
    TMove legalMoves[TState::MAX_MOVES];
    mNumChildren = mState.GetLegalMoves(mPlayerTurn, legalMoves);

    for (int i = 0; i < mNumChildren; ++i) 
    {
        mChildren[i] = std::make_unique<Node<TState, TMove>>(TState(mState.MakeMove(legalMoves[i])), Common::GetOtherPlayer(mPlayerTurn), this, legalMoves[i]);
        // std::cout << mChildren[i]->GetStateRef();
    }
}

// Assumes that the parent exists and is not null
template<typename TState, typename TMove>
double Node<TState, TMove>::GetNodeScore() const
{
    if (mVisits == 0) return std::numeric_limits<double>::max();

    return (mValue / mVisits + 1.41 * std::sqrt(std::log(mParent->GetVisits()) / mVisits));
}

// Returns the child node matching the move or creates it if it doesn't exist
// Will move ownership to the calling unique pointer
template<typename TState, typename TMove>
std::unique_ptr<Node<TState, TMove>> Node<TState, TMove>::GetChild(TMove& move)
{
    for (int i = 0; i < mNumChildren; ++i)
    {
        if (mChildren[i]->mLastMove == move) return std::move(mChildren[i]);
    }

    // TODO: We could use SimulateMove if we are sure the parent will no longer refer to the state after this function
    mChildren[mNumChildren++] = std::make_unique<Node<TState, TMove>>(mState.MakeMove(move), Common::GetOtherPlayer(mPlayerTurn), this, move);    
    return std::move(mChildren[mNumChildren - 1]);
}

// True if this node has children, false if it does not
template <typename TState, typename TMove>
bool Node<TState, TMove>::HasChildren() const
{
    return mNumChildren != 0;
}

// PRECONDITION: This node has expanded all its child nodes
// Tries to prove that this node is a win based on its children.
// If all children nodes are proven losses, then this node itself must be a win
// Returns true is this node is proven to be a win and false otherwise
template <typename TState, typename TMove>
bool Node<TState, TMove>::TryProveWinFromChildren()
{
    for (int i = 0; i < mNumChildren; ++i)
    {
        if (mChildren[i]->GetProven() != Common::Proven::LOSS)
        {
            return false;
        }
    }

    ProveResult<Common::Proven::WIN>();
    return true;
}

}