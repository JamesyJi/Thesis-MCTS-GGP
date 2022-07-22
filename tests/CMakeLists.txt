cmake_minimum_required(VERSION 3.14)
project(tests CXX C)


set(GCC_COMPILE_FLAGS -Wall -Werror -Wvla -O0 -Wno-unused-function -Wno-unused-variable)

# Download Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

function(add_google_test test_target target)
    target_link_libraries(${test_target} ${target} test_utility gtest_main)
    # Using the compile flags for the main executable from GCC_COMPILE_FLAGS
    # and appending test-specific flags from GCC_COMPILE_FLAGS_TEST
    target_compile_options(${test_target} PRIVATE ${GCC_COMPILE_FLAGS} ${GCC_COMPILE_FLAGS_TEST})
    add_test(${test_target} ${test_target})
endfunction(add_google_test)

add_subdirectory(breakthrough)
add_subdirectory(connect4)
add_subdirectory(othello)
add_subdirectory(test_utility)




