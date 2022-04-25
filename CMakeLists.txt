cmake_minimum_required(VERSION 3.0.0)
project(MCTS_GGP_THESIS VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(MCTS_GGP_THESIS experimenter.cpp)

add_subdirectory(common)
# add_subdirectory(games)
# add_subdirectory(main)
# add_subdirectory(mcts)
# add_subdirectory(models)

include_directories(.)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
