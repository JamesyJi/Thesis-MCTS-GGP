add_library(connect4
    move.h
    state.h
    state.cpp
)

target_include_directories(connect4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(connect4 common)