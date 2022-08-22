add_executable(test_models
    minimax_rollout_simulation_policy_unittest.cpp
)

target_link_libraries(test_models
    common
    connect4
    models
    strategy
)

add_google_test(test_models)