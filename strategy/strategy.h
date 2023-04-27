#pragma once

#include "game_state.h"
#include "connect4_state.h"
#include "breakthrough_state.h"
#include "othello_state.h"
#include "catchthelion_state.h"

namespace Strategy
{

// TODO: Make this take in no argument
inline int FixedDepth1(const std::size_t) { return 1; }
inline int FixedDepth2(const std::size_t) { return 2; }
inline int FixedDepth3(const std::size_t) { return 3; }
inline int FixedDepth4(const std::size_t) { return 4; }
inline int FixedDepth5(const std::size_t) { return 5; }
inline int FixedDepth6(const std::size_t) { return 6; }
inline int FixedDepth7(const std::size_t) { return 7; }
inline int FixedDepth8(const std::size_t) { return 8; }
inline int FixedDepth9(const std::size_t) { return 9; }
inline int FixedDepth10(const std::size_t) { return 10; }

template <typename TState>
int DepthFromTurnA(const std::size_t) = delete;

template <>
int DepthFromTurnA<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnA<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnA<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnA<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnB(const std::size_t) = delete;

template <>
int DepthFromTurnB<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnB<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnB<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnB<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnC(const std::size_t) = delete;

template <>
int DepthFromTurnC<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnC<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnC<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnC<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnD(const std::size_t) = delete;

template <>
int DepthFromTurnD<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnD<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnD<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnD<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnE(const std::size_t) = delete;

template <>
int DepthFromTurnE<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnE<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnE<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnE<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnF(const std::size_t) = delete;

template <>
int DepthFromTurnF<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnF<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnF<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnF<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnG(const std::size_t) = delete;

template <>
int DepthFromTurnG<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnG<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnG<Othello::OthelloState>(const std::size_t);

template <>
int DepthFromTurnG<CatchTheLion::CatchTheLionState>(const std::size_t);

template <typename TState>
int DepthFromTurnH(const std::size_t) = delete;

template <>
int DepthFromTurnH<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnH<Breakthrough::BreakthroughState>(const std::size_t);

template <>
int DepthFromTurnH<Othello::OthelloState>(const std::size_t);

template <typename TState>
int DepthFromTurnI(const std::size_t) = delete;

template <>
int DepthFromTurnI<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnI<Othello::OthelloState>(const std::size_t);

template <typename TState>
int DepthFromTurnJ(const std::size_t) = delete;

template <>
int DepthFromTurnJ<Connect4::Connect4State>(const std::size_t);

template <>
int DepthFromTurnJ<Othello::OthelloState>(const std::size_t);

}
