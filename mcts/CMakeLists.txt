add_library(mcts
    node.h
    node.cpp
)

target_include_directories(mcts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mcts common)