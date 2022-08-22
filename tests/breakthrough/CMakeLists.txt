add_executable(test_breakthrough
    breakthrough_state_evaluate_state_unittest.cpp
    breakthrough_state_legal_moves_unittest.cpp
    )

target_link_libraries(test_breakthrough
    breakthrough
)

add_google_test(test_breakthrough)