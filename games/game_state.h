#pragma once

#include "game_types.h"
#include "game_constants.h"

namespace Games
{

    class GameState
    {
    public:
        GameState(){};

        ~GameState(){};

        void NextTurn()
        {
            ++mTurn;
            mPlayerTurn = Common::GetOtherPlayer(mPlayerTurn);
        }

        int GetTurn() const
        {
            return mTurn;
        }

        Common::Player GetPlayerTurn() const
        {
            return mPlayerTurn;
        }

        int (*(GetTerminals)())[MAX_DEPTH + 1]
        {
            return mTerminals;
        }

        void FoundTerminal(int depth)
        {
            mTerminals[mTurn][depth]++;
        }

        inline void LogSimulationStatistics(int length)
        {
            IncrementSimulation();
            UpdateAvgRolloutLength(length);
        }

        inline void IncrementSimulation()
        {
            ++mSimulations[mTurn];
        }

        // To be called after simulation count is updated
        inline void UpdateAvgRolloutLength(int length)
        {
            mAvgRolloutLengths[mTurn] = (mAvgRolloutLengths[mTurn] * (mSimulations[mTurn] - 1) + length) / mSimulations[mTurn];
        }

        // This is called by the models during Expansion (before simulation count is updated)
        inline void UpdateAvgBranchingFactor(int branchingFactor)
        {
            mAvgBranchingFactors[mTurn] = (mAvgBranchingFactors[mTurn] * (mSimulations[mTurn] - 1) + branchingFactor) / mSimulations[mTurn];
        }

        int *GetSimulations()
        {
            return mSimulations;
        }

        bool MaxTurns() const
        {
            return mTurn == MAX_TURN;
        }

        double GetAvgRolloutLengthAtTurn(int turn)
        {
            return mAvgRolloutLengths[turn];
        }

        double GetAvgBranchingFactorAtTurn(int turn)
        {
            return mAvgBranchingFactors[turn];
        }

    private:
        int mTurn = 1;
        Common::Player mPlayerTurn = Common::Player::PLAYER1;

        // Terminal Logging mTerminal[4][8] = number of terminal results detected 8 moves on turn 4
        int mTerminals[MAX_TURN + 1][MAX_DEPTH + 1] = {{0}};

        // Simulation count logging mSimulations[4] = number of simulations on turn 4
        int mSimulations[MAX_TURN + 1] = {0};

        // Long rollout length means lots of random moves... and info is useless...
        // We should switch to minimax for rollouts... (BUT ONLY IF IT DETECTS USEFUL INFO)
        // Determine if this leads to shorter game lengths...
        double mAvgRolloutLengths[MAX_TURN + 1] = {0};

        double mAvgBranchingFactors[MAX_TURN + 1] = {0};

        // If the minimaxes are not detecting valuable information, switch them off
        // Track percentage of minimax detecting valuable information
        // Turn off if below certain threshhold?
    };

}