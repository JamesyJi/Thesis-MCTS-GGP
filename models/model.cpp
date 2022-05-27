#include <iostream>

#include "model.h"

namespace Models
{

// typename Model<M, TTraits>::MoveT Model<M, TTraits>::DecideMove

template<typename M, typename TTraits>
Common::Result Model<M, TTraits>::Minimax(StateT& state, MoveT& lastMove, int depth, Common::Result alpha, Common::Result beta, Common::Player player)
{

    if (depth == 0 || state.EvaluateState(lastMove)) return state.EvaluateState(lastMove);

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
                Common::Result evaluation = Minimax(state, legalMoves[i], depth - 1, alpha, beta, Common::GetOtherPlayer(player));
                state.UndoMove(legalMoves[i]);    
                if (evaluation > maxEval) maxEval = evaluation;
                if (maxEval > alpha) alpha = maxEval;
                if (beta <= alpha) break;
            }

            return maxEval;
        }
        case Common::Player::PLAYER2:
        {
            Common::Result minEval = Common::Result::PLAYER1_WIN;
            
            for (int i = 0; i < nLegalMoves; ++i)
            {
                state.SimulateMove(legalMoves[i]);
                Common::Result evaluation = Minimax(state, legalMoves[i], depth - 1, alpha, beta, Common::GetOtherPlayer(player));
                state.UndoMove(legalMoves[i]);
                if (evaluation < minEval) minEval = evaluation;
                if (minEval < beta) beta = minEval;
                if (beta <= alpha) break;
            }

            return minEval;
        }
        default:
            throw "player's turn cannot be none in minimax";
    }

}

// template<typename M, typename TTraits>
// typename Model<M, TTraits>::MoveT Model<M, TTraits>::DecideMove(Common::Resource& resource)
// {
//     std::cout << "Deciding move...\n";
//     while (resource.UseResource())
//     {
//         static_cast<M*>(this)->ExecuteStrategy();
//     }

//     mRoot = mRoot.GetMostVisitedChild();
//     mRoot.NullParent();

//     return mRoot.GetLastMove();
// }

// template<typename M, typename TTraits>
// void Model<M, TTraits>::NotifyOfOpponentMove(MoveT& move)
// {
//     mRoot = mRoot.GetChild(move);
//     mRoot.NullParent();
// }


}