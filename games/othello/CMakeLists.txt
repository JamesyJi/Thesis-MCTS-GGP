add_library(othello
    othello_state.cpp
)

target_include_directories(othello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(othello common)