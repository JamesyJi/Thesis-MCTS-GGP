add_subdirectory(standard)
add_subdirectory(minimax)

add_library(models INTERFACE)

target_include_directories(models INTERFACE .)
target_link_libraries(models INTERFACE
    mcts
    games
)