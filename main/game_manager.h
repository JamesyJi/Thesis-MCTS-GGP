#pragma once

#include <iostream>

#include "model.h"
#include "standard/standard.h"
#include "minimax/minimax_selection.h"
#include "minimax/minimax_rollout.h"
#include "game_results.h"
#include "game_types.h"
#include "pieces.h"
#include "resource.h"

namespace Main
{

    template <typename Model1, typename Model2, typename TState, typename TMove>
    class GameManager
    {
    public:
        using TraitsT = Models::Traits<TState, TMove>;

        GameManager(std::string resultsFile)
            : mResultsFile(resultsFile){};

        ~GameManager(){};

        void StartExperiment(Common::Resource &resource, int rounds)
        {
            for (int i = 0; i < rounds; ++i)
            {
                std::cout << "Starting round " << i << "\n";

                auto result = StartNewGame(resource);

                std::cout << result << "\n";
            }

            mGameResults.Log(mResultsFile + ".txt");
            mGameResults.LogTerminals(mResultsFile + "_terminals.csv");
            mGameResults.LogIterablePair(mResultsFile + "_gamelengths.csv", mGameResults.GetGameLengths());
            mGameResults.LogIterablePair(mResultsFile + "_rolloutlengths.csv", mGameResults.GetAvgRolloutLengths());
            mGameResults.LogIterablePair(mResultsFile + "_branchingfactors.csv", mGameResults.GetAvgBranchingFactors());
            // mGameResults.LogTerminalCorrelations(mResultsFile + "_RvT.csv", "RvT", mGameResults.GetAvgRolloutLengthsVAvgTerminals());
            // mGameResults.LogTerminalCorrelations(mResultsFile + "_BvT.csv", "BvT", mGameResults.GetAvgBranchingFactorsVAvgTerminals());
            // mGameResults.LogRBvTD(mResultsFile + "_RBvTD.csv");
        }

        Common::Result StartNewGame(Common::Resource &resource)
        {
            Games::GameState gameState;

            auto model1 = Models::Model<Model1, TraitsT>(TState(), gameState);
            auto model2 = Models::Model<Model2, TraitsT>(TState(), gameState);

            TState state{};
            TMove move{};

            while (state.EvaluateState(move) == Common::Result::ONGOING)
            {
                std::cout << "Turn " << gameState.GetTurn() << "\n";
                // Run a check on the game's terminals
                // switch (gameState.GetPlayerTurn())
                // {
                // case Common::Player::PLAYER1:
                //     model1.DetectTerminalStates();
                //     model1.DetectBranchingFactor();
                //     model1.DetectRolloutLengths(5000);
                //     break;
                // case Common::Player::PLAYER2:
                //     model2.DetectTerminalStates();
                //     model2.DetectBranchingFactor();
                //     model2.DetectRolloutLengths(5000);
                //     break;
                // default:
                //     throw std::runtime_error("No player's turn");
                // }

                resource.ResetAndStart();
                switch (gameState.GetPlayerTurn())
                {
                case Common::Player::PLAYER1:
                    move = model1.DecideMove(resource);
                    model2.NotifyOfOpponentMove(move);
                    break;
                case Common::Player::PLAYER2:
                    move = model2.DecideMove(resource);
                    model1.NotifyOfOpponentMove(move);
                    break;
                default:
                    throw std::runtime_error("No player's turn");
                }

                state.SimulateMove(move);

                std::cout << "===============\n";
                std::cout << state;
                std::cout << "===============\n";

                gameState.NextTurn();
                if (gameState.MaxTurns())
                {
                    std::cout << "GAME END DUE TO TOO MANY TURNS\n";
                    mGameResults.UpdateResult(Common::Result::DRAW, gameState);
                    return Common::Result::DRAW;
                }
            }

            std::cout << "GAME END\n";

            auto result = state.EvaluateState(move);
            mGameResults.UpdateResult(result, gameState);
            return result;
        }

    private:
        GameResults mGameResults;

        std::string mResultsFile;
    };

}