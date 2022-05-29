#pragma once

#include <iostream>

#include "model.h"
#include "standard/standard.h"
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

    GameManager()
    {};

    ~GameManager(){};

    void StartExperiment(Common::Resource& resource, int rounds)
    {
        for (int i = 0; i < rounds; ++i)
        {
            std::cout << "Starting round " << i << "\n";
            auto model1 = Models::Model<Model1, TraitsT>(Common::Player::PLAYER1, TState());
            auto model2 = Models::Model<Model2, TraitsT>(Common::Player::PLAYER2, TState());

            auto result = StartNewGame(model1, model2, resource);

            std::cout << result << "\n";
        }
    }


    Common::Result StartNewGame(Models::Model<Model1, TraitsT>& model1, Models::Model<Model2, TraitsT> & model2, Common::Resource& resource)
    {
        TState state;
        TMove move;
        
        auto playerTurn = Common::Player::PLAYER1;

        while (state.EvaluateState(move) == Common::Result::ONGOING)
        {
            resource.ResetAndStart();
            switch (playerTurn)
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

            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        std::cout << "GAME END\n";

        return state.EvaluateState(move);
    }
};

}