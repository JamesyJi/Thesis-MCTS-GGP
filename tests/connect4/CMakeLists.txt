add_executable(test_connect4
    connect4_state_unittest.cpp
)

add_google_test(test_connect4 connect4)