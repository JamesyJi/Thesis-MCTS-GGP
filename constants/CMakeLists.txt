add_library(constants INTERFACE)

target_include_directories(constants INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(constants PROPERTIES LINKER_LANGUAGE CXX)