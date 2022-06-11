#pragma once

#include "model.h"

namespace Models::Detector
{

template<typename TTraits>
class TerminalDetector : public Model<TerminalDetector<TTraits>, TTraits>
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;

    TerminalDetector(Common::Player player, const StateT& state, Games::GameState& gameState)
    : Model<TerminalDetector<TTraits>, TTraits>(player, state, gameState)
    {}

    ~TerminalDetector(){}

    void ExecuteStrategy()
    {
        // Only run detector once per turn
        if (mLastRanDetector != this->mGameState.GetTurn()) {
            DetectTerminalStates();
            mLastRanDetector = this->mGameState.GetTurn();
        }

        // Selection
        NodeT& promisingNode = SelectBestChild();
        StateT& promisingState = promisingNode.GetStateRef();

        // Expansion
        if (promisingState.EvaluateState(promisingNode.GetLastMove()) == Common::Result::ONGOING)
        {
            promisingNode.ExpandNode();
        }

        // Simulation
        NodeT& exploreNode = promisingNode.HasChildren() ? promisingNode.GetRandomChild() : promisingNode;

        auto evaluation = Simulate(exploreNode);
    
        // Back Propagation
        this->BackPropagate(exploreNode, evaluation);
    }

    void DetectTerminalStates() {
        // Log for depths 1 2 3 4 5 6 7 8 9 10 11 12
        std::cout << "detecting terminal state\n";
        for (int i = 1; i <= 12; ++i) 
        {
            std::cout << i << "\n";
            auto result = this->MinimaxAB(this->mRoot->GetStateRef(), this->mRoot->GetLastMove(), i, Common::Result::PLAYER2_WIN, Common::Result::PLAYER1_WIN, this->mRoot->GetPlayerTurn());
            if (result != Common::Result::ONGOING)
            {
                std::cout << "DETECTED " << result << "\n";
                this->mGameState.FoundTerminal(i);
            }
        }
        std::cout << "finished detecting terminal state\n";
    }

    NodeT& SelectBestChild()
    {
        NodeT* bestChild = this->mRoot.get();

        while (bestChild->HasChildren())
        {
            bestChild = &bestChild->GetHighestScoreChild();
        }

        return *bestChild;
    }

    Common::Result Simulate(NodeT& node)
    {
        StateT simulateState = node.GetStateCopy();
        auto playerTurn = node.GetPlayerTurn();
        MoveT move = node.GetLastMove();
        
        MoveT legalMoves[StateT::MAX_MOVES];
        int nLegalMoves;
        while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
        {
            nLegalMoves = simulateState.GetLegalMoves(playerTurn, legalMoves);
            move = legalMoves[rand() % nLegalMoves];
            simulateState.SimulateMove(move);
            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        return simulateState.EvaluateState(move);
    }

private:
    int mLastRanDetector = 0;
};

}