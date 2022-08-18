add_executable(test_models
    minimax_rollout_simulation_policy_unittest.cpp
)

add_google_test(test_models models)