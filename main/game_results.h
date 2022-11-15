#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

#include "game_types.h"
#include "game_state.h"

namespace Main
{

    static double Round2dp(double x)
    {
        return ceil(x * 100.0) / 100.0;
    }

    class GameResults
    {
    public:
        GameResults(){};

        ~GameResults(){};

        void UpdateResult(Common::Result result)
        {
            if (result == Common::Result::DRAW)
            {
                mDraws++;
            }
            else if (result == Common::Result::PLAYER1_WIN)
            {
                mPlayer1Wins++;
            }
            else if (result == Common::Result::PLAYER2_WIN)
            {
                mPlayer2Wins++;
            }

            mTotalGames++;
        }

        // Called after update result
        void Accumulate(Games::GameState &gameState)
        {
            std::cout << "accumulating\n";

            for (int turn = 1; turn < gameState.GetTurn(); ++turn)
            {
                mGameLengths[turn]++;

                double rolloutLength = gameState.GetAvgRolloutLengthAtTurn(turn);
                double branchingFactor = gameState.GetAvgBranchingFactorAtTurn(turn);

                mAvgRolloutLengths[turn] = Round2dp((mAvgRolloutLengths[turn] * (mTotalGames - 1) + rolloutLength) / mTotalGames);
                mAvgBranchingFactors[turn] = Round2dp((mAvgBranchingFactors[turn] * (mTotalGames - 1) + branchingFactor) / mTotalGames);
            }

            // Updating Terminals
            int(*terminals)[11] = gameState.GetTerminals();
            for (int turn = 1; turn < gameState.GetTurn(); ++turn)
            {
                for (int depth = 1; depth <= 10; ++depth)
                {
                    mTerminals[turn][depth] += terminals[turn][depth];
                }
            }

            // Updating Avg Simulations of first turn
            int *simulations = gameState.GetSimulations();

            mAvgSimsP1 = (mAvgSimsP1 * (mTotalGames - 1) + simulations[1]) / mTotalGames;
            mAvgSimsP2 = (mAvgSimsP2 * (mTotalGames - 1) + simulations[2]) / mTotalGames;

            UpdateTerminalsVsRolloutLengths(gameState);
        }

        void UpdateTerminalsVsRolloutLengths(Games::GameState &gameState)
        {
            int(*terminals)[11] = gameState.GetTerminals();

            for (int turn = 1; turn < gameState.GetTurn(); ++turn)
            {
                double length = Round2dp(gameState.GetAvgRolloutLengthAtTurn(turn));
                for (int depth = 1; depth <= 10; ++depth)
                {
                    int nTerminals = terminals[turn][depth];
                    auto &terminalVsCount = mTerminalsVsRolloutLengths[length][depth];
                    int newCount = ++terminalVsCount.second;
                    int curTerminals = terminalVsCount.first;
                    terminalVsCount.first = (curTerminals * (newCount - 1) + nTerminals) / newCount;
                }
            }
        }

        void Log(const std::string &fileName)
        {
            std::ofstream file(fileName, std::ofstream::trunc);

            file << "Player1 Win: " << mPlayer1Wins << "\n";
            file << "Player2 Win: " << mPlayer2Wins << "\n";
            file << "Draws: " << mDraws << "\n";
            file << "Total: " << mTotalGames << "\n";
            file << "AvgSimulationsPlayer1: " << mAvgSimsP1 << "\n";
            file << "AvgSimulationsPlayer2: " << mAvgSimsP2 << "\n";
            file.close();
        }

        void LogTerminals(const std::string &fileName) const
        {
            std::ofstream file(fileName, std::ofstream::trunc);
            file << "TURN,1,2,3,4,5,6,7,8,9,10,\n";
            for (auto &it : mTerminals)
            {
                file << it.first << ",";
                for (auto &it2 : it.second)
                {
                    file << it2.second << ",";
                }
                file << "\n";
            }

            file.close();
        }

        // Logs an iterable with it.first and it.second to a given file
        template <typename Iterable>
        void LogIterablePair(const std::string &fileName, Iterable iterable) const
        {
            std::ofstream file(fileName, std::ofstream::trunc);
            for (const auto &it : iterable)
            {
                file << it.first << " : " << it.second << "\n";
            }
            file.close();
        }

        void LogTerminalsVsRolloutLengths(const std::string &fileName) const
        {
            std::ofstream file(fileName, std::ofstream::trunc);
            file << "RvD,1,2,3,4,5,6,7,8,9,10,\n";
            for (auto &it : mTerminalsVsRolloutLengths)
            {
                file << it.first << ",";
                for (auto &it2 : it.second)
                {
                    file << it2.second.first << ",";
                }
                file << "\n";
            }

            file.close();
        }

        std::map<int, int> const &GetGameLengths() const { return mGameLengths; }
        std::map<int, int> const &GetAvgRolloutLengths() const { return mAvgRolloutLengths; }
        std::map<int, int> const &GetAvgBranchingFactors() const { return mAvgBranchingFactors; }

    private:
        int mPlayer1Wins = 0;
        int mPlayer2Wins = 0;
        int mDraws = 0;
        int mTotalGames = 0;

        // Game lengths {turn : games ended at this turn}
        // We start at turn 1
        std::map<int, int> mGameLengths{};

        // Number of terminal games {turn : {depth : count}}
        std::map<int, std::map<int, int>> mTerminals = {};

        // Average number of simulations for 1st move respectively
        double mAvgSimsP1 = 0;
        double mAvgSimsP2 = 0;

        // Average rollout lengths by turn (turn : mAvgRolloutLengths)
        // We start at turn 1
        std::map<int, int> mAvgRolloutLengths{};

        // Average branching factors by turn (turn : mAvgBranchingFactors)
        // We start at turn 1
        std::map<int, int> mAvgBranchingFactors{};

        // Rollout lengths, Branching Factors, Terminals, Depth
        // ((RL, BF), {Terminals@D1, Terminals@D2, Terminals@D3...})
        // std::array<std::pair<std::pair<double, double>, std::array<int, 11>>, 300> mRBvTD{};

        // To find a correlation between rollout lengths and number of terminals
        // RolloutLengths v Depths 1, 2, 3, 4, 5, 6, 7, 8
        //      5.3               2343 // Average number of terminals
        //      6.7
        //      8.8
        //      ...
        // {rollouts : { depth : <terminals, count>}}
        std::map<double, std::map<int, std::pair<int, int>>> mTerminalsVsRolloutLengths = {};
    };

}