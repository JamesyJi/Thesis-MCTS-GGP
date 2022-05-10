add_library(common INTERFACE)

target_include_directories(common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX)
