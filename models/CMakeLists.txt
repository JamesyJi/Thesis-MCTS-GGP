add_subdirectory(standard)
add_subdirectory(minimax)
add_subdirectory(detector)

add_library(models INTERFACE)

target_include_directories(models INTERFACE .)