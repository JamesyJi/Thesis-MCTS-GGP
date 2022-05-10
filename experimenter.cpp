// #include <main/game_manager.h>
#include <iostream>
#include "main/game_manager.h"
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


    // auto manager = Main::GameManager<Models::Standard::Standard

    auto m1 = Models::Standard::Standard<s>(Common::Player::PLAYER1, Connect4::Connect4State());
    auto m2 = Models::Standard::Standard<s>(Common::Player::PLAYER2, Connect4::Connect4State());

    auto m3 = Main::GameManager<Connect4::Connect4State, Connect4::Connect4Move>();


    return 0;
}