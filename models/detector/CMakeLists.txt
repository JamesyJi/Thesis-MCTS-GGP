add_library(detector INTERFACE)

target_link_libraries(detector INTERFACE 
    common
    models
    mcts)

set_target_properties(detector PROPERTIES LINKER_LANGUAGE CXX)
