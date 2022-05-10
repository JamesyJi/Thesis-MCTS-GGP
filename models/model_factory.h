#ifndef MODEL_FACTORY_H_
#define MODEL_FACTORY_H_

#include <memory>
#include <unordered_map>

#include <common/game_types.h>
#include <models/standard/standard.h>

namespace Models
{

enum class ModelType
{
    STANDARD,
};

template <typename TTraits>
class ModelFactory
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using ModelVariant = std::variant
    <
        Standard::Standard<TTraits>
    >;

    static std::unique_ptr<ModelVariant> MakeModel(Common::Player player, ModelType type)
    {
        switch (type)
        {
            case ModelType::STANDARD:
                return std::make_unique<Standard::Standard<TTraits>>(player, StateT());
            default:
                break;
        }
    }
};

}

#endif