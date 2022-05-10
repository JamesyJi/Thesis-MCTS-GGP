#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <iostream>

#include <models/model.h>
#include <models/model_factory.h>
#include <common/game_types.h>
#include <common/resource.h>

namespace Main
{

template <template <typename> class Model1, template <typename> class Model2, typename TState, typename TMove>
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
            auto model1 = Model1<TraitsT>(Common::Player::PLAYER1, TState());
            auto model2 = Model2<TraitsT>(Common::Player::PLAYER2, TState());

            auto result = StartNewGame(model1, model2, resource);

            std::cout << result << "\n";
        }
    }


    Common::Result StartNewGame(Model1<TraitsT>& model1, Model2<TraitsT> & model2, Common::Resource& resource)
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
                    model2.GetChild(move);
                    break;
                case Common::Player::PLAYER2:
                    move = model2.DecideMove(resource);
                    model1.GetChild(move);
                    break;
                default:
                    throw std::runtime_error "No player's turn";
            }

            state.SimulateMove(move);

            std::cout << state;

            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        return state.EvaluateState(move);
    }
};

}

#endif