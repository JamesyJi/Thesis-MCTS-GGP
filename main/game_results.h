#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <vector>
#include <array>

#include "game_types.h"
#include "game_state.h"
#include "game_constants.h"

namespace Main
{

template <int N>
static double RoundDP(double x)
{
    return ceil(x * 10.0 * N) / (10.0 * N);
}

// The count is the current count before the new value has been added in
static double ComputeNewAvg(double original, int count, double newValue)
{
    return (original * count + newValue) / (count + 1);
}

class GameResults
{
public:
    GameResults() {};

    ~GameResults() {};

    void UpdateResult(Common::Result result, Games::GameState& gameState)
    {
        mTotalGames++;

        switch (result)
        {
        case Common::Result::DRAW:
            mDraws++;
            break;
        case Common::Result::PLAYER1_WIN:
            mPlayer1Wins++;
            break;
        case Common::Result::PLAYER2_WIN:
            mPlayer2Wins++;
            break;
        default:
            break;
        }

        Accumulate(gameState);
    }

    // Called after update result
    void Accumulate(Games::GameState& gameState)
    {
        std::cout << "accumulating\n";

        int(*terminals)[MAX_DEPTH + 1] = gameState.GetTerminals();

        for (int turn = 1; turn < gameState.GetTurn(); ++turn)
        {
            for (int depth = 1; depth <= MAX_DEPTH; ++depth)
            {
                mTerminals[turn][depth] += terminals[turn][depth];
            }

            mGameLengths[turn]++;

            double rolloutLength = gameState.GetAvgRolloutLengthAtTurn(turn);
            double branchingFactor = gameState.GetAvgBranchingFactorAtTurn(turn);
            mAvgRolloutLengths[turn] = RoundDP<2>(ComputeNewAvg(mAvgRolloutLengths[turn], mTotalGames - 1, rolloutLength));
            mAvgBranchingFactors[turn] = RoundDP<2>(ComputeNewAvg(mAvgBranchingFactors[turn], mTotalGames - 1, branchingFactor));
        }

        // Updating Avg Simulations of first turn
        int* simulations = gameState.GetSimulations();
        mAvgSimsP1 = ComputeNewAvg(mAvgSimsP1, mTotalGames - 1, simulations[1]);
        mAvgSimsP2 = ComputeNewAvg(mAvgSimsP2, mTotalGames - 1, simulations[2]);

        UpdateTerminalCorrelations(gameState);
    }

    void UpdateTerminalCorrelations(Games::GameState& gameState)
    {
        int(*terminals)[MAX_DEPTH + 1] = gameState.GetTerminals();
        auto& mRvT = mAvgRolloutLengthsVAvgTerminals;
        auto& mBvT = mAvgBranchingFactorsVAvgTerminals;

        for (int turn = 1; turn < gameState.GetTurn(); ++turn)
        {
            double rolloutLength = RoundDP<2>(gameState.GetAvgRolloutLengthAtTurn(turn));
            double branchingFactor = RoundDP<2>(gameState.GetAvgBranchingFactorAtTurn(turn));

            std::array<int, MAX_DEPTH + 1> td;
            for (int depth = 1; depth <= MAX_DEPTH; ++depth)
            {
                mRvT[rolloutLength][depth].first = RoundDP<2>(ComputeNewAvg(mRvT[rolloutLength][depth].first, mRvT[rolloutLength][depth].second++, terminals[turn][depth]));
                mBvT[branchingFactor][depth].first = RoundDP<2>(ComputeNewAvg(mBvT[branchingFactor][depth].first, mBvT[branchingFactor][depth].second++, terminals[turn][depth]));
                td[depth] = terminals[turn][depth];
            }

            mRBvTD.push_back(std::make_pair(std::make_pair(rolloutLength, branchingFactor), td));
        }
    }

    void Log(const std::string& fileName)
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

    void LogTerminals(const std::string& fileName) const
    {
        std::ofstream file(fileName, std::ofstream::trunc);
        file << "TURN";
        for (int depth = 1; depth <= MAX_DEPTH; ++depth)
        {
            file << "," << depth;
        }
        file << "\n";

        for (auto& it : mTerminals)
        {
            file << it.first << ",";
            for (auto& it2 : it.second)
            {
                file << it2.second << ",";
            }
            file << "\n";
        }

        file.close();
    }

    // Logs an iterable with it.first and it.second to a given file
    template <typename Iterable>
    void LogIterablePair(const std::string& fileName, Iterable iterable) const
    {
        std::ofstream file(fileName, std::ofstream::trunc);
        for (const auto& it : iterable)
        {
            file << it.first << " : " << it.second << "\n";
        }
        file.close();
    }

    void LogTerminalCorrelations(const std::string& fileName, const std::string& title, std::map<double, std::map<int, std::pair<double, int>>> iterable) const
    {
        std::ofstream file(fileName, std::ofstream::trunc);
        file << title;
        for (int depth = 1; depth <= MAX_DEPTH; ++depth)
        {
            file << "," << depth;
        }
        file << "\n";

        for (auto& it : iterable)
        {
            file << it.first;
            for (auto& it2 : it.second)
            {
                file << "," << it2.second.first;
            }
            file << "\n";
        }
        file.close();
    }

    void LogRBvTD(const std::string& fileName)
    {
        std::ofstream file(fileName, std::ofstream::trunc);

        file << "RBvTD";
        for (int depth = 1; depth <= MAX_DEPTH; ++depth)
        {
            file << "," << depth;
        }
        file << "\n";

        for (auto& [rb, td] : mRBvTD)
        {
            file << "(" << rb.first << "," << rb.second << "):";

            for (int depth = 1; depth <= MAX_DEPTH; ++depth)
            {
                file << td[depth] << ",";
            }
            file << "\n";
        }
    }

    std::map<int, int> const& GetGameLengths() const { return mGameLengths; }
    std::map<int, double> const& GetAvgRolloutLengths() const { return mAvgRolloutLengths; }
    std::map<int, double> const& GetAvgBranchingFactors() const { return mAvgBranchingFactors; }
    std::map<double, std::map<int, std::pair<double, int>>> const& GetAvgRolloutLengthsVAvgTerminals() { return mAvgRolloutLengthsVAvgTerminals; }
    std::map<double, std::map<int, std::pair<double, int>>> const& GetAvgBranchingFactorsVAvgTerminals() { return mAvgBranchingFactorsVAvgTerminals; }

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
    std::map<int, double> mAvgRolloutLengths{};

    // Average branching factors by turn (turn : mAvgBranchingFactors)
    // We start at turn 1
    std::map<int, double> mAvgBranchingFactors{};

    // To find a correlation between rollout lengths and number of terminals
    // RolloutLengths v Depths 1, 2, 3, 4, 5, 6, 7, 8
    //      5.3               2343 // Average number of terminals
    //      6.7
    //      8.8
    //      ...
    // {rollouts : { depth : { terminals : count }}}
    // The count is to help us compute the average
    std::map<double, std::map<int, std::pair<double, int>>> mAvgRolloutLengthsVAvgTerminals;

    // Same as above
    // { branchingFactors : { depth : { terminals : count }}}
    std::map<double, std::map<int, std::pair<double, int>>> mAvgBranchingFactorsVAvgTerminals;

    // Rollout lengths, Branching Factors, Terminals, Depth
    // ((RL, BF), {Terminals@D1, Terminals@D2, Terminals@D3...})
    // There could easily be duplicate (RL, BF) and the terminals they map to are the terminals found for one game at that point.
    std::vector<std::pair<std::pair<double, double>, std::array<int, MAX_DEPTH + 1>>> mRBvTD;
};
}