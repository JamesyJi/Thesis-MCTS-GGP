#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <iostream>

#include <models/model.h>
#include <common/game_types.h>
#include <common/resource.h>
#include <main/game_manager.h>
#include <mcts/state.h>

namespace Main
{

template <typename GameState, typename Move>
class GameManager
{
public:
    using GModel = Model<GameState, Move>;
    using GModelFactory = ModelFactory<GameState, Move>;

    GameManager(ModelType modelType1, ModelType modelType2)
    : mModelType1(modelType1)
    , mModelType2(modelType2)
    {}

    ~GameManager(){};

    void StartExperiment(Common::Resource& resource, int rounds)
    {
        for (int i = 0; i < rounds; ++i)
        {
            std::cout << "Starting round " << i << "\n";
            auto model1 = GModelFactory::MakeModel(mModelType1);
            auto model2 = GModelFactory::MakeModel(mModelType2);

            auto result = StartNewGame(GModel model1, GModel model2, resource);

            std::cout << result << "\n";
        }
    }

    Common::Result StartNewGame(GModel& model1, GModel& model2, Common::Resource& resource)
    {
        GameState state;
        Move move;
        GModel* curPlayer = model1;
        GModel* oppPlayer = model2;

        while (state.EvaluateState(move) == Common::Result::ONGOING)
        {
            resource.ResetAndStart();
            move = curPlayer->DecideMove(resource);

            oppPlayer->GetChild(move);
            state.SimulateMove(move);

            std::swap(curPlayer, oppPlayer);

            std::cout << state;
        }

        return state.EvaluateState(move);
    }

private:
    ModelType mModelType1;
    ModelType mModelType2;
};

}

#endif