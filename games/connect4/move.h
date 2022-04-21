#ifndef GAMES_CONNECT4_MOVE_H_
#define GAMES_CONNECT4_MOVE_H_

#include <common/game_types.h>

namespace Connect4
{

// Empty is 0
// Board size is 6 high, 7 wide
// 0, 0 top left
// 5, 6, bottom right
// Moves are defined by: (x, y, z) where:
//      x: player1 or 2
//      y: row index (0 to 5)
//      x: col index (0 to 6)
struct Connect4Move
{
    Common::Player player;
    int row;
    int col;
};

}

#endif