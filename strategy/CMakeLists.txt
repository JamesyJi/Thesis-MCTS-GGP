add_library(strategy
    strategy.h
    connect4_strategy.cpp
    breakthrough_strategy.cpp
    othello_strategy.cpp
    catchthelion_strategy.cpp
)

set_target_properties(strategy PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(strategy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(strategy
    games
    connect4
    breakthrough
    othello
    catchthelion
)

