#pragma once

#include <tuple>
#include <iostream>

namespace Common
{

enum class Player
{
    PLAYER1,
    PLAYER2,
    NONE,
    PLAYER_TOTAL // Do not remove, used for array sizing
};

enum class Result
{
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW,
    ONGOING
};

enum class Proven
{
    WIN,
    LOSS,
    NONE,
};

inline bool operator<(Result a, Result b)
{
    switch (a)
    {
    case Result::PLAYER1_WIN:
        return false;
    case Result::PLAYER2_WIN:
        switch (b)
        {
        case Result::PLAYER2_WIN:
            return false;
        default:
            return true;
        }
    case Result::DRAW:
    case Result::ONGOING:
        switch (b)
        {
        case Result::PLAYER1_WIN:
            return true;
        default:
            return false;
        }
    }
}

inline bool operator<=(Result a, Result b)
{
    switch (a)
    {
    case Result::PLAYER1_WIN:
        switch (b)
        {
        case Result::PLAYER1_WIN:
            return true;
        default:
            return false;
        }
    case Result::PLAYER2_WIN:
        return true;
    case Result::DRAW:
    case Result::ONGOING:
        switch (b)
        {
        case Result::PLAYER2_WIN:
            return false;
        default:
            return true;
        }
    }
}

inline bool operator>(Result a, Result b)
{
    switch (a)
    {
    case Result::PLAYER1_WIN:
        switch (b)
        {
        case Result::PLAYER1_WIN:
            return false;
        default:
            return true;
        }
    case Result::PLAYER2_WIN:
        return false;
    case Result::DRAW:
    case Result::ONGOING:
        switch (b)
        {
        case Result::PLAYER2_WIN:
            return true;
        default:
            return false;
        }
    }
}

inline bool operator>=(Result a, Result b)
{
    switch (a)
    {
    case Result::PLAYER1_WIN:
        return true;
    case Result::PLAYER2_WIN:
        switch (b)
        {
        case Result::PLAYER2_WIN:
            return true;
        default:
            return false;
        }
    case Result::DRAW:
    case Result::ONGOING:
        switch (b)
        {
        case Result::PLAYER1_WIN:
            return false;
        default:
            return true;
        }
    }
}

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

inline Player ResultToPlayer(Result result)
{
    switch (result)
    {
    case Result::PLAYER1_WIN:
        return Player::PLAYER1;
    case Result::PLAYER2_WIN:
        return Player::PLAYER2;
    default:
        return Player::NONE;
    }
}

inline std::tuple<Player, Player> GetWinnerAndLoser(Result result)
{
    switch (result)
    {
    case Result::PLAYER1_WIN:
        return { Player::PLAYER1, Player::PLAYER2 };
    case Result::PLAYER2_WIN:
        return { Player::PLAYER2, Player::PLAYER1 };
    default:
        return { Player::NONE, Player::NONE };
    }
}

inline Player GetOtherPlayer(Player player)
{
    return player == Player::PLAYER1 ? Player::PLAYER2 : Player::PLAYER1;
}

static std::ostream& operator<<(std::ostream& os, Player player)
{
    switch (player)
    {
    case Player::NONE: return os << "NONE";
    case Player::PLAYER1: return os << "PLAYER1";
    case Player::PLAYER2: return os << "PLAYER2";
    default: return os << "Other";
    }
}

static std::ostream& operator<<(std::ostream& os, Result result)
{
    switch (result)
    {
    case Result::PLAYER1_WIN: return os << "PLAYER1_WIN";
    case Result::PLAYER2_WIN: return os << "PLAYER2_WIN";
    case Result::DRAW: return os << "DRAW";
    case Result::ONGOING: return os << "ONGOING";
    }
}

}