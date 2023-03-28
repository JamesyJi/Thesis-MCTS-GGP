#pragma once


namespace Common
{

/**
* 8 directions, assuming top left is 0,0 and bottom right is N, M.
* North is up
*/
enum class Direction {
    N,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW,
};

template <Direction> struct DirectionToStep;

template <> struct DirectionToStep<Direction::N> {
    static constexpr std::pair<int, int> value = { 0, -1 };
};

template <> struct DirectionToStep<Direction::NE> {
    static constexpr std::pair<int, int> value = { 1, -1 };
};

template <> struct DirectionToStep<Direction::E> {
    static constexpr std::pair<int, int> value = { 1, 0 };
};

template <> struct DirectionToStep<Direction::SE> {
    static constexpr std::pair<int, int> value = { 1, 1 };
};

template <> struct DirectionToStep<Direction::S> {
    static constexpr std::pair<int, int> value = { 0, 1 };
};

template <> struct DirectionToStep<Direction::SW> {
    static constexpr std::pair<int, int> value = { -1, 1 };
};

template <> struct DirectionToStep<Direction::W> {
    static constexpr std::pair<int, int> value = { -1, 0 };
};

template <> struct DirectionToStep<Direction::NW> {
    static constexpr std::pair<int, int> value = { -1, -1 };
};

}