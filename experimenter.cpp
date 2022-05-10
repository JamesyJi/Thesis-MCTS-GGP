#include <iostream>
#include "game_manager.h"
#include "resource.h"
#include "standard/standard.h"
#include "connect4/state.h"

int main(void)
{
    auto manager = Main::GameManager<Models::Standard::Standard, Models::Standard::Standard, Connect4::Connect4State, Connect4::Connect4Move>();
    auto resource = Common::TimeResource(10);
    manager.StartExperiment(resource, 10);

    return 0;
}