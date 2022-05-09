// #include <main/game_manager.h>
// #include <models/model_factory.h>
#include <iostream>
#include "models/model.h"
#include "models/standard/standard.h"
#include "models/model_factory.h"
#include "common/game_types.h"
#include "games/connect4/state.h"
#include "games/connect4/move.h"

int main(void)
{
    std::cout << "Nothing for now\n";
    std::cout << Common::Result::DRAW << "\n";
    
    using s = Models::Traits<Connect4::Connect4State, Connect4::Connect4Move>;

    auto start = Connect4::Connect4State();
    auto m = Models::Standard::Standard<s>(Common::Player::PLAYER1, start);

    // auto m = Models::ModelFactory<Connect4::Connect4State, Connect4::Connect4Move>::MakeModel(Models::ModelType::STANDARD);

    return 0;
}