add_executable(test_connect4
    connect4_state_unittest.cpp
)

target_link_libraries(test_connect4
    connect4
)

add_google_test(test_connect4)