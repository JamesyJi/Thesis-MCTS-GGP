add_executable(test_othello
    othello_state_evaluate_state_unittest.cpp
    othello_state_legal_moves_unittest.cpp
    )

add_google_test(test_othello othello)
