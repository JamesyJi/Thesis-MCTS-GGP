add_subdirectory(standard)
add_subdirectory(minimax)

add_library(models INTERFACE)

target_include_directories(models INTERFACE .)
# target_include_directories(models PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# target_link_libraries(
#     models 
#     mcts
# )


# add_library(common)

# target_include_directories(
#     common
#     PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/..
# )