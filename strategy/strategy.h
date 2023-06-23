#pragma once

#include "game_state.h"
#include "connect4_state.h"
#include "breakthrough_state.h"
#include "othello_state.h"
#include "catchthelion_state.h"

namespace Strategy
{

inline int FixedDepth1(double) { return 1; }
inline int FixedDepth2(double) { return 2; }
inline int FixedDepth3(double) { return 3; }
inline int FixedDepth4(double) { return 4; }
inline int FixedDepth5(double) { return 5; }
inline int FixedDepth6(double) { return 6; }
inline int FixedDepth7(double) { return 7; }
inline int FixedDepth8(double) { return 8; }
inline int FixedDepth9(double) { return 9; }
inline int FixedDepth10(double) { return 10; }

template <typename TState>
int DepthFromTurnA(double avgDepth) = delete;

template <>
int DepthFromTurnA<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnA<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnA<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnA<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnB(double avgDepth) = delete;

template <>
int DepthFromTurnB<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnB<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnB<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnB<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnB<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnC(double avgDepth) = delete;

template <>
int DepthFromTurnC<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnC<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnC<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnC<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnD(double avgDepth) = delete;

template <>
int DepthFromTurnD<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnD<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnD<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnD<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnE(double avgDepth) = delete;

template <>
int DepthFromTurnE<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnE<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnE<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnE<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnF(double avgDepth) = delete;

template <>
int DepthFromTurnF<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnF<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnF<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnF<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnG(double avgDepth) = delete;

template <>
int DepthFromTurnG<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnG<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnG<Othello::OthelloState>(double avgDepth);

template <>
int DepthFromTurnG<CatchTheLion::CatchTheLionState>(double avgDepth);

template <typename TState>
int DepthFromTurnH(double avgDepth) = delete;

template <>
int DepthFromTurnH<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnH<Breakthrough::BreakthroughState>(double avgDepth);

template <>
int DepthFromTurnH<Othello::OthelloState>(double avgDepth);

template <typename TState>
int DepthFromTurnI(double avgDepth) = delete;

template <>
int DepthFromTurnI<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnI<Othello::OthelloState>(double avgDepth);

template <typename TState>
int DepthFromTurnJ(double avgDepth) = delete;

template <>
int DepthFromTurnJ<Connect4::Connect4State>(double avgDepth);

template <>
int DepthFromTurnJ<Othello::OthelloState>(double avgDepth);

}
