#pragma once

#include <iostream>

#include "model.h"
#include "standard/standard.h"
#include "game_results.h"
#include "game_types.h"
#include "pieces.h"
#include "resource.h"

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)
#define E Common::Piece()

namespace Main
{

template<typename Model1, typename Model2, typename TState, typename TMove>
class GameManager
{
public:
    using TraitsT = Models::Traits<TState, TMove>;

    GameManager(){};

    ~GameManager(){};

    void StartExperiment(Common::Resource& resource, int rounds)
    {
        for (int i = 0; i < rounds; ++i)
        {
            std::cout << "Starting round " << i << "\n";

            auto result = StartNewGame(resource);

            std::cout << result << "\n";
        }

        mGameResults.Log("results.txt");
        mGameResults.LogTerminals("terminals.csv");
    }


    Common::Result StartNewGame(Common::Resource& resource)
    {
        Games::GameState gameState;

        auto model1 = Models::Model<Model1, TraitsT>(Common::Player::PLAYER1, TState(), gameState);
        auto model2 = Models::Model<Model2, TraitsT>(Common::Player::PLAYER2, TState(), gameState);

        TState state;
        TMove move;

        while (state.EvaluateState(move) == Common::Result::ONGOING)
        {
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
        }

        std::cout << "GAME END\n";

        auto result = state.EvaluateState(move);
        mGameResults.UpdateResult(result);
        mGameResults.Accumulate(gameState);
        return result;
    }

private:
    GameResults mGameResults;
};

}