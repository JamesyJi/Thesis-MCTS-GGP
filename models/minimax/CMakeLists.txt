add_library(minimax INTERFACE)

target_link_libraries(minimax INTERFACE 
    common
    models
    mcts)

set_target_properties(minimax PROPERTIES LINKER_LANGUAGE CXX)
