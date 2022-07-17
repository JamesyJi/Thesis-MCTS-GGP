cmake_minimum_required(VERSION 3.14)
project(MCTS_GGP_THESIS VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include(CTest)
enable_testing()

add_subdirectory(common)
add_subdirectory(games)
add_subdirectory(mcts)
add_subdirectory(models)
add_subdirectory(main)
add_subdirectory(strategy)
add_subdirectory(tests)


file(GLOB SOURCES
    experimenter.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    common
    games
    connect4
    breakthrough
    strategy
    models
    standard
    mcts
    main
)

