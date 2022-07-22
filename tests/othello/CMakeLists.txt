add_executable(test_othello
    othello_state_unittest.cpp
)

add_google_test(test_othello othello)