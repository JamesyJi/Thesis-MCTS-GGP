# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/james/Documents/Thesis_C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/james/Documents/Thesis_C++

# Include any dependencies generated for this target.
include tests/models/CMakeFiles/test_models.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/models/CMakeFiles/test_models.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/models/CMakeFiles/test_models.dir/progress.make

# Include the compile flags for this target's objects.
include tests/models/CMakeFiles/test_models.dir/flags.make

tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o: tests/models/CMakeFiles/test_models.dir/flags.make
tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o: tests/models/minimax_rollout_simulation_policy_unittest.cpp
tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o: tests/models/CMakeFiles/test_models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Documents/Thesis_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o"
	cd /Users/james/Documents/Thesis_C++/tests/models && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o -MF CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o.d -o CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o -c /Users/james/Documents/Thesis_C++/tests/models/minimax_rollout_simulation_policy_unittest.cpp

tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.i"
	cd /Users/james/Documents/Thesis_C++/tests/models && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Documents/Thesis_C++/tests/models/minimax_rollout_simulation_policy_unittest.cpp > CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.i

tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.s"
	cd /Users/james/Documents/Thesis_C++/tests/models && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Documents/Thesis_C++/tests/models/minimax_rollout_simulation_policy_unittest.cpp -o CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.s

# Object files for target test_models
test_models_OBJECTS = \
"CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o"

# External object files for target test_models
test_models_EXTERNAL_OBJECTS =

tests/models/test_models: tests/models/CMakeFiles/test_models.dir/minimax_rollout_simulation_policy_unittest.cpp.o
tests/models/test_models: tests/models/CMakeFiles/test_models.dir/build.make
tests/models/test_models: games/connect4/libconnect4.a
tests/models/test_models: strategy/libstrategy.a
tests/models/test_models: lib/libgtest.a
tests/models/test_models: lib/libgmock.a
tests/models/test_models: lib/libgtest_main.a
tests/models/test_models: mcts/libmcts.a
tests/models/test_models: games/connect4/libconnect4.a
tests/models/test_models: games/breakthrough/libbreakthrough.a
tests/models/test_models: games/othello/libothello.a
tests/models/test_models: games/catchthelion/libcatchthelion.a
tests/models/test_models: lib/libgtest.a
tests/models/test_models: tests/models/CMakeFiles/test_models.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Documents/Thesis_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_models"
	cd /Users/james/Documents/Thesis_C++/tests/models && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_models.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/models/CMakeFiles/test_models.dir/build: tests/models/test_models
.PHONY : tests/models/CMakeFiles/test_models.dir/build

tests/models/CMakeFiles/test_models.dir/clean:
	cd /Users/james/Documents/Thesis_C++/tests/models && $(CMAKE_COMMAND) -P CMakeFiles/test_models.dir/cmake_clean.cmake
.PHONY : tests/models/CMakeFiles/test_models.dir/clean

tests/models/CMakeFiles/test_models.dir/depend:
	cd /Users/james/Documents/Thesis_C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++/tests/models /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++/tests/models /Users/james/Documents/Thesis_C++/tests/models/CMakeFiles/test_models.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/models/CMakeFiles/test_models.dir/depend

