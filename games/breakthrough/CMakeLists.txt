add_library(breakthrough
    breakthrough_move.h
    breakthrough_state.h
    breakthrough_state.cpp)

target_include_directories(breakthrough PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(breakthrough common)