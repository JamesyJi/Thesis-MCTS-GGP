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

inline Result PlayerToResult(Player player)
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

inline Player GetOtherPlayer(Player player)
{
    return player == Player::PLAYER1 ? Player::PLAYER2 : Player::PLAYER1;
}

std::ostream& operator<<(std::ostream& os, Player player)
{
    switch (player)
    {
        case Player::NONE : return os << "NONE";
        case Player::PLAYER1 : return os << "PLAYER1";
        case Player::PLAYER2 : return os << "PLAYER2";
    }
}

std::ostream& operator<<(std::ostream& os, Result result)
{
    switch (result)
    {
        case Result::PLAYER1_WIN : return os << "PLAYER1_WIN";
        case Result::PLAYER2_WIN : return os << "PLAYER2_WIN";
        case Result::DRAW : return os << "DRAW";
        case Result::ONGOING : return os << "ONGOING";
    }
}


}
#endif