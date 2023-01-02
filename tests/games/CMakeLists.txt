add_executable(test_games
    game_state_unittest.cpp
)

target_link_libraries(test_games games)

add_google_test(test_games)