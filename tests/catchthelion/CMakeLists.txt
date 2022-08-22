add_executable(test_catchthelion
    catchthelion_state_legal_moves_unittest.cpp
    catchthelion_state_moves_unittest.cpp
    catchthelion_state_evaluate_state_unittest.cpp
    catchthelion_state_real_scenarios_test.cpp
    )

target_link_libraries(test_catchthelion
    catchthelion
    )

add_google_test(test_catchthelion)