#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <iostream>

#include <models/model.h>
#include <models/model_factory.h>
#include <common/game_types.h>
#include <common/resource.h>

namespace Main
{

template <typename TState, typename TMove>
class GameManager
{
public:
    using TraitsT = Models::Traits<TState, TMove>;

    GameManager(Models::ModelType model1Type, Models::ModelType model2Type)
    : mModel1Type(model1Type)
    , mModel2Type(model2Type)
    {};

    ~GameManager(){};

    void StartExperiment(Common::Resource& resource, int rounds)
    {
        for (int i = 0; i < rounds; ++i)
        {
            std::cout << "Starting round " << i << "\n";
            auto model1 = Models::ModelFactory<TraitsT>::MakeModel(Common::Player::PLAYER1, mModel1Type);
            auto model2 = Models::ModelFactory<TraitsT>::MakeModel(Common::Player::PLAYER2, mModel2Type);

            auto result = StartNewGame(model1, model2, resource);

            std::cout << result << "\n";
        }
    }


    Common::Result StartNewGame(Model1T& model1, Model2T& model2, Common::Resource& resource)
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
                    std::throw "No player's turn";
            }

            state.SimulateMove(move);

            std::cout << state;
        }

        return state.EvaluateState(move);
    }
private:
    Models::ModelType mModel1Type;
    Models::ModelType mModel2Type;
};

}

#endif