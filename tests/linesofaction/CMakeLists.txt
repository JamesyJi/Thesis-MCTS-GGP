add_executable(test_linesofaction
    linesofaction_state_legal_moves_unittest.cpp
)

target_link_libraries(test_linesofaction
    linesofaction
)

add_google_test(test_linesofaction)