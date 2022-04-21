#ifndef COMMON_GAME_TYPES_H_
#define COMMON_GAME_TYPES_H_

namespace Common
{

enum class Player
{
    PLAYER1,
    PLAYER2,
    NONE,
};

enum class Result 
{
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW,
    ONGOING
};

Result PlayerToResult(Player player)
{
    switch (player)
    {
        case Player::PLAYER1:
            return Result::PLAYER1_WIN;
        case Player::PLAYER2:
            return Result::PLAYER2_WIN;
        default:
            throw "Only Player1 or Player2 can convert to a result!";
    }
}

}
#endif