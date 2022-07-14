// #pragma once

// #include <iterator>
// #include <cstddef>

// class OthelloStateGenerator : public std::iterator<std::forward_iterator_tag>
// {
// public:
//     struct Iterator
//     {
//         using iterator_category = std::forward_iterator_tag;
//         using difference_type = std::ptrdiff_t;
//         using value_type = int;
//         using pointer = int*;
//         using reference = int&;

//         reference operator*() const
//         {
//             return *mState; 
//         }

//         reference operator() const
//         {
//             return *mState;
//         }

//         Iterator(pointer ptr) : mPtr(ptr)
    
//     private:
//         pointer mPtr;
//     }

//     Iterator begin() { return Iterator()}
// private:
//     int seed;
// };