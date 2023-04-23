#include "strategy.h"
namespace Strategy
{
const std::size_t MAX_BRANCHING = 22;

const int TURN_DEPTH_A[MAX_BRANCHING] = {
    -1,
    1,
    3,
    4,
    6,
    7,
    9,
    10,
    7,
    5,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnA<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_A[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_B[MAX_BRANCHING] = {
    -1,
    1,
    3,
    4,
    5,
    6,
    8,
    9,
    6,
    5,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnB<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_B[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_C[MAX_BRANCHING] = {
    -1,
    1,
    2,
    3,
    5,
    6,
    7,
    8,
    5,
    4,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnC<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_C[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_D[MAX_BRANCHING] = {
    -1,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    5,
    4,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnD<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_D[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_E[MAX_BRANCHING] = {
    -1,
    1,
    2,
    3,
    3,
    4,
    5,
    6,
    4,
    3,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnE<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_E[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_F[MAX_BRANCHING] = {
    -1,
    1,
    1,
    2,
    3,
    4,
    4,
    5,
    3,
    3,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnF<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_F[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_G[MAX_BRANCHING] = {
    -1,
    1,
    1,
    2,
    2,
    3,
    3,
    4,
    3,
    2,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnG<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_G[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_H[MAX_BRANCHING] = {
    -1,
    0,
    1,
    1,
    2,
    2,
    3,
    3,
    2,
    2,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnH<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_H[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_I[MAX_BRANCHING] = {
    -1,
    0,
    1,
    1,
    1,
    1,
    2,
    2,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnI<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_I[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_J[MAX_BRANCHING] = {
    -1,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnJ<Othello::OthelloState>(const std::size_t branching)
{
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_J[branching];
    }
    else
    {
        return 0;
    }
}

}