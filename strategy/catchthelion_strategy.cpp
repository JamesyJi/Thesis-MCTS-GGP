#include "strategy.h"
#include "game_constants.h"

namespace Strategy {

const std::size_t MAX_BRANCHING = 36;

const int TURN_DEPTH_A[MAX_BRANCHING] = {
    -1,
    0,
    0,
    1,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    3,
    2,
    3,
    3,
    4,
    3,
    4,
    4,
    6,
};

template <>
int DepthFromTurnA<CatchTheLion::CatchTheLionState>(const std::size_t branching) {
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
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    3,
    2,
    2,
    3,
    2,
    3,
    2,
    2,
    3,
    3,
    3,
    3,
    4,
    3,
    2,
    2,
    3,
    3,
    4,
    3,
    4,
    3,
    5,
};

template <>
int DepthFromTurnB<CatchTheLion::CatchTheLionState>(const std::size_t branching) {
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_A[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_C[MAX_BRANCHING] = {
    -1,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    2,
    1,
    2,
    2,
    3,
    2,
    3,
    3,
    4,
};

template <>
int DepthFromTurnC<CatchTheLion::CatchTheLionState>(const std::size_t branching) {
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_A[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_D[MAX_BRANCHING] = {
    -1,
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
    2,
    1,
    1,
    2,
    1,
    2,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
};

template <>
int DepthFromTurnD<CatchTheLion::CatchTheLionState>(const std::size_t branching) {
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_A[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_E[MAX_BRANCHING] = {
    -1,
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
    1,
    1,
    1,
    2,
};

template <>
int DepthFromTurnE<CatchTheLion::CatchTheLionState>(const std::size_t branching) {
    if (branching < MAX_BRANCHING)
    {
        return TURN_DEPTH_A[branching];
    }
    else
    {
        return 0;
    }
}

const int TURN_DEPTH_F[MAX_BRANCHING] = {
    -1,
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
    1,
    0,
    0,
    1,
    0,
    1,
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
    1,
    1,
    1,
    1,
    1,
    1,
    1,
};

template <>
int DepthFromTurnF<CatchTheLion::CatchTheLionState>(const std::size_t branching) {
    return TURN_DEPTH_F[branching];
}

}