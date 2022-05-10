cmake_minimum_required(VERSION 3.1.4)
project(MCTS_GGP_THESIS VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

add_subdirectory(common)
add_subdirectory(games)
add_subdirectory(mcts)
add_subdirectory(models)
add_subdirectory(main)

add_executable(${PROJECT_NAME} experimenter.cpp)

target_link_libraries(${PROJECT_NAME}
    main
    models
    standard
    games
    connect4
    common
)
