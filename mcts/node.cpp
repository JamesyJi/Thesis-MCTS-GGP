#include <limits>
#include <cmath>

#include <mcts/node.h>
#include <common/game_types.h>

namespace MCTS
{

// Assumption is that the node has children
template<typename GameState, typename Move>
Node<GameState, Move>& Node<GameState, Move>::GetRandomChild()
{
    // TODO: Can use faster random
    return mChildren[rand() % mNumChildren];
}

// Assumption is that the node has children
template<typename GameState, typename Move>
Node<GameState, Move>& Node<GameState, Move>::GetMostVisitedChild()
{
    int maxIndex = 0;
    int maxVisits = 0;
    for (int i = 0; i < mNumChildren; ++i) 
    {
        if (mChildren[i].visits > maxVisits) 
        {
            maxIndex = i;
            maxVisits = mChildren[i].visits;
        }
    }

    return mChildren[maxIndex];
}

// Assumption is that the node has children
template<typename GameState, typename Move>
Node<GameState, Move>& Node<GameState, Move>::GetHighestScoreChild()
{
    int maxIndex = 0;
    double maxScore = std::numeric_limits<double>::min();
    for (int i = 0; i < mNumChildren; ++i)
    {
        if (mChildren[i].GetNodeScore() > maxScore)
        {
            maxIndex = i;
            maxScore = mChildren[i].GetNodeScore();
        }
    }

    return mChildren[maxIndex];
}


// Expands the node, adding all legal possible nodes as children
template<typename GameState, typename Move>
void Node<GameState, Move>::ExpandNode()
{
    auto legalMoves = Move[GameState::MAX_MOVES];
    int nLegalMoves = mState.GetLegalMoves(mPlayerTurn, legalMoves);

    for (int i = 0; i < nLegalMoves; ++i) 
    {
        mChildren[i] = Node(mState.MakeMove(legalMoves[i]), Common::GetOtherPlayer(mPlayerTurn), this, legalMoves[i])
    }
}

// Assumes that the parent exists and is not null
template<typename GameState, typename Move>
double Node<GameState, Move>::GetNodeScore()
{
    if (mVisits == 0) return std::numeric_limits<double>::max();

    return (mValue / mVisits + 1.41 * std::sqrt(std::log(mParent->mVisits) / mVisits));
}

// Returns the child node matching the move or creates it if it doesn't exist
template<typename GameState, typename Move>
Node<GameState, Move>& Node<GameState, Move>::GetChild(Move& bove)
{
    for (int i = 0; i < mNumChildren; ++i)
    {
        if (mChildren[i].mLastMove == move) return mChildren[i];
    }

    // TODO: We could use SimulateMove if we are sure the parent will no longer refer to the state after this function
    mChildren[mNumChildren++] = Node(mState.MakeMove(move), Common::GetOtherPlayer(mPlayerTurn), this, move);    
    return mChildren[mNumChildren];
}

}