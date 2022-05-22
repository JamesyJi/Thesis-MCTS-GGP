cmake_minimum_required(VERSION 3.14)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


set(This MCTS_TESTS)

set(Sources
  connect4/state_unittest.cpp
)

add_executable(${This} ${Sources})

add_test(
  NAME ${This}
  COMMAND ${This}
)

target_include_directories(
  ${This}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/connect4
)

target_link_libraries(${This} PUBLIC
    gtest_main
    connect4
)





