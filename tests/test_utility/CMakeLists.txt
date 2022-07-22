add_library(test_utility INTERFACE)

target_include_directories(test_utility INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(test_utility INTERFACE
    common
)