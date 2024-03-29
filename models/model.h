#pragma once

#include <memory>
#include <utility>
#include <iostream>

#include "game_types.h"
#include "resource.h"
#include "node.h"
#include "node.cpp"
#include "game_state.h"
#include "game_constants.h"

namespace Models
{

    template <typename TState, typename TMove>
    struct Traits
    {
        using StateT = TState;
        using MoveT = TMove;
    };

    template <typename M, typename TTraits>
    class Model
    {
    public:
        using StateT = typename TTraits::StateT;
        using MoveT = typename TTraits::MoveT;
        using NodeT = MCTS::Node<StateT, MoveT>;

        MoveT DecideMove(Common::Resource &resource)
        {
            std::cout << "deciding move...\n";
            while (resource.UseResource())
            {
                static_cast<M *>(this)->ExecuteStrategy();
            }

            std::cout << "DECIDED MOVE\n";
            // std::cout << mRoot->GetLastMove() << "\n";
            // mRoot->LogChildStats();

            // std::cout << "enter a number to continue\n";
            // int i;
            // std::cin >> i;

            mRoot = mRoot->DecideOnBestChild();
            mRoot->NullParent();
            std::cout << mRoot->GetLastMove() << "\n";
            return mRoot->GetLastMove();
        }

        void NotifyOfOpponentMove(MoveT &move)
        {
            mRoot = mRoot->GetChild(move);
            // mRoot = std::move(mRoot->GetChild(move));
            mRoot->NullParent();
        }

        void ExecuteStrategy()
        {
            static_cast<M *>(this)->ExecuteStrategy();
        }

        NodeT &SelectBestChild()
        {
            return static_cast<M *>(this)->SelectBestChild();
        }

        Common::Result Simulate(NodeT &node)
        {
            StateT simulateState = node.GetStateCopy();
            auto playerTurn = node.GetPlayerTurn();
            MoveT move = node.GetLastMove();

            int length = 0;
            while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
            {
                move = static_cast<M *>(this)->SimulationPolicy(simulateState, playerTurn);
                simulateState.SimulateMove(move);
                playerTurn = Common::GetOtherPlayer(playerTurn);

                if (++length == MAX_TURN)
                    break;
            }

            mGameState.LogSimulationStatistics();

            return simulateState.EvaluateState(move);
        }

        void BackPropagate(NodeT &node, Common::Result result);

        void BackPropagateProven(NodeT &node, Common::Result result);

        static Common::Result MinimaxAB(StateT &state, const MoveT &lastMove, int depth, Common::Result alpha, Common::Result beta, Common::Player player);

        void DetectTerminalStates();

        void DetectRolloutLengths(int numSimulations);

        void DetectBranchingFactor();

        Model(const StateT &state, Games::GameState &gameState)
            : mRoot(std::make_unique<NodeT>(state, Common::Player::PLAYER1, nullptr, MoveT())), mGameState(gameState){};

    protected:
        std::unique_ptr<NodeT> mRoot;
        Games::GameState &mGameState;
    };

    // Backpropagates results
    template <typename M, typename TTraits>
    void Model<M, TTraits>::BackPropagate(NodeT &node, Common::Result result)
    {
        auto winnerloser = Common::GetWinnerAndLoser(result);

        NodeT *curNode = &node;
        while (curNode != nullptr)
        {
            if (curNode->IsProven())
            {
                curNode = curNode->GetParent();
                continue;
            }

            if (std::get<1>(winnerloser) == curNode->GetPlayerTurn())
            {
                curNode->IncrValue();
            }
            else if (std::get<0>(winnerloser) == curNode->GetPlayerTurn())
            {
                curNode->DecrValue();
            }

            curNode->Visit();
            curNode = curNode->GetParent();
        }
    }

    // Backpropagates proven results
    template <typename M, typename TTraits>
    void Model<M, TTraits>::BackPropagateProven(NodeT &node, Common::Result result)
    {
        if (result == Common::Result::ONGOING || result == Common::Result::DRAW)
        {
            return;
        }

        auto curPlayer = node.GetPlayerTurn();

        NodeT *curNode;

        if (result == Common::PlayerToResult(curPlayer))
        {
            // The player who moved into this turn lost
            node.template ProveResult<Common::Proven::LOSS>();
            curNode = node.GetParent();
        }
        else
        {
            // The player who moved into this turn won
            node.template ProveResult<Common::Proven::WIN>();
            curNode = node.GetParent();
            if (curNode != nullptr)
            {
                curNode->template ProveResult<Common::Proven::LOSS>();
                curNode = curNode->GetParent();
            }
        }

        // Try to propagate everything up the tree as far as possible by checking
        // to see if all children nodes are proven
        while (curNode != nullptr)
        {
            if (!curNode->TryProveWinFromChildren())
            {
                return;
            }

            // Node has been proven to be a win. The prior move must be a loss
            curNode = curNode->GetParent();
            if (curNode != nullptr)
            {
                curNode->template ProveResult<Common::Proven::LOSS>();
                curNode = curNode->GetParent();
            }
        }
    }

    template <typename M, typename TTraits>
    Common::Result Model<M, TTraits>::MinimaxAB(StateT &state, const MoveT &lastMove, int depth, Common::Result alpha, Common::Result beta, Common::Player player)
    {
        if (depth == 0 || state.EvaluateState(lastMove) != Common::Result::ONGOING)
            return state.EvaluateState(lastMove);

        MoveT legalMoves[StateT::MAX_MOVES];
        int nLegalMoves = state.GetLegalMoves(player, legalMoves);

        switch (player)
        {
        case Common::Player::PLAYER1:
        {
            Common::Result maxEval = Common::Result::PLAYER2_WIN;

            for (int i = 0; i < nLegalMoves; ++i)
            {
                state.SimulateMove(legalMoves[i]);
                Common::Result evaluation = MinimaxAB(state, legalMoves[i], depth - 1, alpha, beta, Common::GetOtherPlayer(player));
                state.UndoMove(legalMoves[i]);

                if (evaluation > maxEval)
                    maxEval = evaluation;
                if (maxEval > alpha)
                    alpha = maxEval;
                if (beta <= alpha)
                    break;
            }

            return maxEval;
        }
        case Common::Player::PLAYER2:
        {
            Common::Result minEval = Common::Result::PLAYER1_WIN;

            for (int i = 0; i < nLegalMoves; ++i)
            {
                state.SimulateMove(legalMoves[i]);
                Common::Result evaluation = MinimaxAB(state, legalMoves[i], depth - 1, alpha, beta, Common::GetOtherPlayer(player));
                state.UndoMove(legalMoves[i]);
                if (evaluation < minEval)
                    minEval = evaluation;
                if (minEval < beta)
                    beta = minEval;
                if (beta <= alpha)
                    break;
            }

            return minEval;
        }
        default:
            throw "player's turn cannot be none in minimax";
        }
    }

    template <typename M, typename TTraits>
    void Model<M, TTraits>::DetectTerminalStates()
    {
        std::cout << "Detecting Terminal States...\n";
        auto &rootState = mRoot->GetStateRef();
        auto &lastMove = mRoot->GetLastMove();
        auto curPlayer = mRoot->GetPlayerTurn();

        if (rootState.EvaluateState(lastMove) != Common::Result::ONGOING)
        {
            return;
        }

        MoveT legalMoves[StateT::MAX_MOVES];
        int nLegalMoves = rootState.GetLegalMoves(curPlayer, legalMoves);
        if (nLegalMoves == 0)
        {
            return;
        }

        // For each move, get the next state and then check if any terminals can be detected
        for (int i = 0; i < nLegalMoves; ++i)
        {
            auto &legalMove = legalMoves[i];
            auto childState = rootState.MakeMove(legalMove);

            for (int depth = 1; depth <= MAX_DEPTH; ++depth)
            {
                auto result = MinimaxAB(childState, legalMove, depth, Common::Result::PLAYER2_WIN, Common::Result::PLAYER1_WIN, Common::GetOtherPlayer(curPlayer));
                if (result != Common::Result::ONGOING)
                {
                    this->mGameState.FoundTerminal(depth);
                }
            }
        }

        std::cout << "Finished Detecting Terminal States\n";
    }

    template <typename M, typename TTraits>
    void Model<M, TTraits>::DetectBranchingFactor()
    {
        std::cout << "Detecting Branching Factor...\n";

        this->mGameState.UpdateAvgBranchingFactor(mRoot->GetNumChildren());
    }

    template <typename M, typename TTraits>
    void Model<M, TTraits>::DetectRolloutLengths(int numSimulations)
    {
        std::cout << "Detecting Rollout Lengths...\n";

        for (int i = 0; i < numSimulations; ++i) {
            // Basically Simulate() but if we didn't care about the result
            // When have time, can refactor Simulate to take in a template
            NodeT &node = *this->mRoot.get();
            StateT simulateState = node.GetStateCopy();
            auto playerTurn = node.GetPlayerTurn();
            MoveT move = node.GetLastMove();

            int length = 0;
            while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
            {
                move = static_cast<M *>(this)->SimulationPolicy(simulateState, playerTurn);
                simulateState.SimulateMove(move);
                playerTurn = Common::GetOtherPlayer(playerTurn);

                if (++length == MAX_TURN)
                    break;
            }

            this->mGameState.UpdateAvgRolloutLength(length);
        }
    }
}
