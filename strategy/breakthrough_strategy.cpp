#include "strategy.h"
#include <cmath>

namespace Strategy
{
const int MAX_TURNS = 30; // Maximum number of turns we will account for in our calculations
const int TURN_DEPTH_A[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    0,
    7,
    7,
    8,
    8,
    8,
    8,
    7,
    7,
    6,
    6,
    5,
    4,
    4,
    4,
    3,
    2,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnA<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_A[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_B[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    0,
    6,
    7,
    7,
    7,
    7,
    7,
    6,
    6,
    6,
    5,
    5,
    4,
    4,
    3,
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
};

template <>
int DepthFromTurnB<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_B[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_C[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    0,
    5,
    6,
    6,
    6,
    6,
    6,
    5,
    5,
    5,
    4,
    4,
    3,
    3,
    3,
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
};

template <>
int DepthFromTurnC<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_C[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_D[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    0,
    4,
    5,
    5,
    5,
    5,
    5,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    2,
    2,
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
};

template <>
int DepthFromTurnD<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_D[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_E[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    0,
    3,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
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
};

template <>
int DepthFromTurnE<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_E[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_F[MAX_TURNS] = {
    0,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
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
};

template <>
int DepthFromTurnF<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_F[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_G[MAX_TURNS] = {
    0,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    1,
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
};

template <>
int DepthFromTurnG<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_G[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_H[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
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
int DepthFromTurnH<Breakthrough::BreakthroughState>(double avgDepth)
{
    if (static_cast<int>(std::round(avgDepth)) < MAX_TURNS)
    {
        return TURN_DEPTH_H[static_cast<int>(std::round(avgDepth))];
    }
    else
    {
        return 0;
    }
}
}