add_subdirectory(breakthrough)
add_subdirectory(catchthelion)
add_subdirectory(connect4)
add_subdirectory(othello)
add_subdirectory(linesofaction)

add_library(games INTERFACE)

target_include_directories(games INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(games PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(games INTERFACE
    constants
)