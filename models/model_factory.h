#ifndef MODEL_FACTORY_H_
#define MODEL_FACTORY_H_

#include <memory>

namespace Models
{

enum class ModelType
{
    STANDARD,
};

template<typename GameState, typename Move>
class ModelFactory
{
public:
    using GModel = Model<GameState, Move>;

    static std::unique_ptr<GModel> MakeModel(ModelType type)
    {
        switch (type)
        {
        default:
            break;
        }
    }

};

}

#endif