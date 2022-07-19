#pragma once

#include <iterator>
#include <cstddef>
#include <optional>

#include "othello_state.h"

static Othello::OthelloState GenerateState();
Common::Piece RandomPiece();

template <typename T>
struct StateGenIterator {
    using difference_type = int;
    using value_type = T;
    using pointer = const T*;
    using reference = const T&;
    using iterator_category = std::input_iterator_tag;

    StateGenIterator() {}
    explicit StateGenIterator(std::function<std::optional<T>()> f_) : f(f_), v(f()) {}

    StateGenIterator(StateGenIterator<T> const &) = default;
    StateGenIterator(StateGenIterator<T> &&) = default;
    StateGenIterator<T>& operator=(StateGenIterator<T> const &) = default;
    StateGenIterator<T>& operator=(StateGenIterator<T> &&) = default;

    bool operator==(StateGenIterator<T> const &rhs) {
        return (!v) && (!rhs.v); // only compare equal if both at end
    }
    bool operator!=(StateGenIterator<T> const &rhs) { return !(*this == rhs); }

    StateGenIterator<T>& operator++() {
        v = f();
        return *this;
    }
    StateGenIterator<T> operator++(int) {
        auto tmp = *this;
        ++*this;
        return tmp;
    }

    // throw `std::bad_optional_access` if you try to dereference an end iterator
    T const& operator*() const {
        return v.value();
    }

private:
    std::function<std::optional<T>()> f;
    std::optional<T> v;
};

template <typename T>
StateGenIterator<T> generate_begin(std::function<std::optional<T>()> f) { return StateGenIterator<T>(f); }

template <typename T>
StateGenIterator<T> generate_end(std::function<std::optional<T>()>) { return StateGenIterator<T>(); }

struct StateGenerator
{
    StateGenerator(int limit)
    : mCurIter(0)
    , mLimit(limit)
    {}

    std::optional<Othello::OthelloState> operator()()
    {
        if (mCurIter == mLimit) return std::nullopt;
        
        ++mCurIter;
        return GenerateState();
    }

    int mCurIter;
    int mLimit;
};


static Othello::OthelloState GenerateState()
{
    Common::Piece position[Othello::OthelloState::ROWS][Othello::OthelloState::COLS];

    for (int row = 0; row < Othello::OthelloState::ROWS; ++row)
        for (int col = 0; col < Othello::OthelloState::COLS; ++col)
            position[row][col] = RandomPiece();

    return Othello::OthelloState(position);
}

Common::Piece RandomPiece()
{
    int choice = rand() % 3;
    switch (choice)
    {
    case 0:
        return Common::Piece();
    case 1:
        return Common::Piece(Common::Player::PLAYER1);
    case 2:
        return Common::Piece(Common::Player::PLAYER2);
    default:
        throw("RandomPiece should only be 0 1 2");
    }
}