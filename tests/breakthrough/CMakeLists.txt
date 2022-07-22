add_executable(test_breakthrough 
    breakthrough_state_evaluate_state_unittest.cpp
    breakthrough_state_legal_moves_unittest.cpp
    )
    
add_google_test(test_breakthrough breakthrough)