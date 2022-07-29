add_library(lib_test_helpers INTERFACE)

target_include_directories(lib_test_helpers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(lib_test_helpers INTERFACE
    common)

set_target_properties(lib_test_helpers PROPERTIES LINKER_LANGUAGE CXX)
