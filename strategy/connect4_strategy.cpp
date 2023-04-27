#include "strategy.h"

namespace Strategy
{

const std::size_t MAX_BRANCHING = 8; // Maximum branching factor we will account for in our calculations
const int TURN_DEPTH_A[MAX_BRANCHING] = {
    -1,
    1,
    3,
    4,
    6,
    7,
    9,
    10,
};

template <>
int DepthFromTurnA<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnB<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnC<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnD<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnE<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnF<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnG<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnH<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnI<Connect4::Connect4State>(const std::size_t branching)
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
};

template <>
int DepthFromTurnJ<Connect4::Connect4State>(const std::size_t branching)
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
