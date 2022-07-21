add_library(catchthelion
    catchthelion_move.h
    catchthelion_state.h
    catchthelion_state.cpp)

target_include_directories(catchthelion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(catchthelion common)