#include "strategy.h"
#include "game_constants.h"
#include <cmath>

namespace Strategy {

const int MAX_TURNS = 20;

const int TURN_DEPTH_A[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    6,
    5,
    4,
    4,
    6,
    5,
    5,
    5,
    4,
    4,
    4,
    3,
    2,
    1,
    1,
    0,
};

template <>
int DepthFromTurnA<CatchTheLion::CatchTheLionState>(double avgDepth) {
    if (static_cast<int>(std::round(avgDepth)) >= MAX_TURNS) {
        return 0;
    }
    return TURN_DEPTH_A[static_cast<int>(std::round(avgDepth))];
}

const int TURN_DEPTH_B[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    5,
    4,
    4,
    4,
    5,
    4,
    5,
    5,
    3,
    4,
    4,
    3,
    2,
    1,
    1,
    0,
};

template <>
int DepthFromTurnB<CatchTheLion::CatchTheLionState>(double avgDepth) {
    if (static_cast<int>(std::round(avgDepth)) >= MAX_TURNS) {
        return 0;
    }
    return TURN_DEPTH_B[static_cast<int>(std::round(avgDepth))];
}

const int TURN_DEPTH_C[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    4,
    3,
    3,
    3,
    4,
    3,
    4,
    4,
    2,
    3,
    3,
    2,
    1,
    1,
    0,
    0,
};

template <>
int DepthFromTurnC<CatchTheLion::CatchTheLionState>(double avgDepth) {
    if (static_cast<int>(std::round(avgDepth)) >= MAX_TURNS) {
        return 0;
    }
    return TURN_DEPTH_C[static_cast<int>(std::round(avgDepth))];
}

const int TURN_DEPTH_D[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    3,
    2,
    2,
    2,
    3,
    2,
    3,
    3,
    2,
    2,
    2,
    2,
    1,
    1,
    0,
    0,
};

template <>
int DepthFromTurnD<CatchTheLion::CatchTheLionState>(double avgDepth) {
    if (static_cast<int>(std::round(avgDepth)) >= MAX_TURNS) {
        return 0;
    }
    return TURN_DEPTH_D[static_cast<int>(std::round(avgDepth))];
}

const int TURN_DEPTH_E[MAX_TURNS] = {
    0,
    0,
    0,
    0,
    2,
    2,
    1,
    1,
    2,
    2,
    2,
    2,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
};

template <>
int DepthFromTurnE<CatchTheLion::CatchTheLionState>(double avgDepth) {
    if (static_cast<int>(std::round(avgDepth)) >= MAX_TURNS) {
        return 0;
    }
    return TURN_DEPTH_E[static_cast<int>(std::round(avgDepth))];
}

const int TURN_DEPTH_F[MAX_TURNS] = {
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
    0,
    0,
    0,
    0,
};

template <>
int DepthFromTurnF<CatchTheLion::CatchTheLionState>(double avgDepth) {
    if (static_cast<int>(std::round(avgDepth)) >= MAX_TURNS) {
        return 0;
    }
    return TURN_DEPTH_F[static_cast<int>(std::round(avgDepth))];
}

}