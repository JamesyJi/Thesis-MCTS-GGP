add_library(standard INTERFACE)

target_link_libraries(standard INTERFACE common)
target_link_libraries(standard INTERFACE models)
set_target_properties(standard PROPERTIES LINKER_LANGUAGE CXX)
