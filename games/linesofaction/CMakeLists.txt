add_library(linesofaction
    linesofaction_move.hpp
    linesofaction_state.hpp
    linesofaction_state.cpp)

target_include_directories(linesofaction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(linesofaction common)