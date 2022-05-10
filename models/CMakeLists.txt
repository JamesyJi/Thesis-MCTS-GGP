add_subdirectory(standard)

add_library(models
    model.h
    model.cpp
)

target_include_directories(models INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(models 
    mcts
    common)


# add_library(common)

# target_include_directories(
#     common
#     PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/..
# )