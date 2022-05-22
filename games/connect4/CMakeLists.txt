add_library(connect4
    connect4_move.h
    connect4_state.h
    connect4_state.cpp
)

target_include_directories(connect4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(connect4 common)