add_library(
    connect4
    move.h
    state.h
    state.cpp
)

target_link_libraries(connect4 common)