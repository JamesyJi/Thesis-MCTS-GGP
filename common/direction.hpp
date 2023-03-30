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

static std::ostream& operator<<(std::ostream& os, Direction direction) {
    switch (direction) {
    case Direction::N: return os << "NORTH";
    case Direction::NE: return os << "NORTH-EAST";
    case Direction::E: return os << "EAST";
    case Direction::SE: return os << "SOUTH-EAST";
    case Direction::S: return os << "SOUTH";
    case Direction::SW: return os << "SOUTH-WEST";
    case Direction::W: return os << "WEST";
    case Direction::NW: return os << "NORTH-WEST";
    }
}

template <Direction> struct DirectionToStep;

template <> struct DirectionToStep<Direction::N> {
    static constexpr std::pair<int, int> value = { -1, 0 };
};

template <> struct DirectionToStep<Direction::NE> {
    static constexpr std::pair<int, int> value = { -1, 1 };
};

template <> struct DirectionToStep<Direction::E> {
    static constexpr std::pair<int, int> value = { 0, 1 };
};

template <> struct DirectionToStep<Direction::SE> {
    static constexpr std::pair<int, int> value = { 1, 1 };
};

template <> struct DirectionToStep<Direction::S> {
    static constexpr std::pair<int, int> value = { 1, 0 };
};

template <> struct DirectionToStep<Direction::SW> {
    static constexpr std::pair<int, int> value = { 1, -1 };
};

template <> struct DirectionToStep<Direction::W> {
    static constexpr std::pair<int, int> value = { 0, -1 };
};

template <> struct DirectionToStep<Direction::NW> {
    static constexpr std::pair<int, int> value = { -1, -1 };
};

}