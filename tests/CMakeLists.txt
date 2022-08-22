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


# set(This MCTS_TESTS)

# set(Sources
#   breakthrough/breakthrough_minimax_ab_unittest.cpp
#   # breakthrough/breakthrough_state_evaluate_state_unittest.cpp
#   # breakthrough/breakthrough_state_legal_moves_unittest.cpp
#   # connect4/connect4_state_unittest.cpp
#   # othello/othello_state_unittest.cpp
# )

# add_executable(${This} ${Sources})

function(add_google_test test_target)
    target_link_libraries(${test_target} gtest gmock gtest_main lib_test_helpers)
    # Using the compile flags for the main executable from GCC_COMPILE_FLAGS
    # and appending test-specific flags from GCC_COMPILE_FLAGS_TEST
    target_compile_options(${test_target} PRIVATE ${GCC_COMPILE_FLAGS} ${GCC_COMPILE_FLAGS_TEST})
    add_test(${test_target} ${test_target})
endfunction(add_google_test)

# add_subdirectory(connect4)
add_subdirectory(breakthrough)
add_subdirectory(catchthelion)
add_subdirectory(othello)

add_subdirectory(models)
add_subdirectory(test_helpers)






