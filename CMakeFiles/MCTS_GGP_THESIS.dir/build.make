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
include CMakeFiles/MCTS_GGP_THESIS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MCTS_GGP_THESIS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MCTS_GGP_THESIS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MCTS_GGP_THESIS.dir/flags.make

CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o: CMakeFiles/MCTS_GGP_THESIS.dir/flags.make
CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o: experimenter.cpp
CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o: CMakeFiles/MCTS_GGP_THESIS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Documents/Thesis_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o -MF CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o.d -o CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o -c /Users/james/Documents/Thesis_C++/experimenter.cpp

CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Documents/Thesis_C++/experimenter.cpp > CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.i

CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Documents/Thesis_C++/experimenter.cpp -o CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.s

# Object files for target MCTS_GGP_THESIS
MCTS_GGP_THESIS_OBJECTS = \
"CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o"

# External object files for target MCTS_GGP_THESIS
MCTS_GGP_THESIS_EXTERNAL_OBJECTS =

MCTS_GGP_THESIS: CMakeFiles/MCTS_GGP_THESIS.dir/experimenter.cpp.o
MCTS_GGP_THESIS: CMakeFiles/MCTS_GGP_THESIS.dir/build.make
MCTS_GGP_THESIS: games/connect4/libconnect4.a
MCTS_GGP_THESIS: games/breakthrough/libbreakthrough.a
MCTS_GGP_THESIS: games/catchthelion/libcatchthelion.a
MCTS_GGP_THESIS: games/othello/libothello.a
MCTS_GGP_THESIS: games/linesofaction/liblinesofaction.a
MCTS_GGP_THESIS: strategy/libstrategy.a
MCTS_GGP_THESIS: mcts/libmcts.a
MCTS_GGP_THESIS: games/catchthelion/libcatchthelion.a
MCTS_GGP_THESIS: games/othello/libothello.a
MCTS_GGP_THESIS: games/connect4/libconnect4.a
MCTS_GGP_THESIS: games/breakthrough/libbreakthrough.a
MCTS_GGP_THESIS: mcts/libmcts.a
MCTS_GGP_THESIS: CMakeFiles/MCTS_GGP_THESIS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Documents/Thesis_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MCTS_GGP_THESIS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MCTS_GGP_THESIS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MCTS_GGP_THESIS.dir/build: MCTS_GGP_THESIS
.PHONY : CMakeFiles/MCTS_GGP_THESIS.dir/build

CMakeFiles/MCTS_GGP_THESIS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MCTS_GGP_THESIS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MCTS_GGP_THESIS.dir/clean

CMakeFiles/MCTS_GGP_THESIS.dir/depend:
	cd /Users/james/Documents/Thesis_C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++/CMakeFiles/MCTS_GGP_THESIS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MCTS_GGP_THESIS.dir/depend

