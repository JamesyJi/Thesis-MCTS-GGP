add_library(main INTERFACE)

set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(main INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(main INTERFACE
    standard
    games
    models
)
