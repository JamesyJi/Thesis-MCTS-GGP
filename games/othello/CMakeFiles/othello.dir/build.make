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
include games/othello/CMakeFiles/othello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include games/othello/CMakeFiles/othello.dir/compiler_depend.make

# Include the progress variables for this target.
include games/othello/CMakeFiles/othello.dir/progress.make

# Include the compile flags for this target's objects.
include games/othello/CMakeFiles/othello.dir/flags.make

games/othello/CMakeFiles/othello.dir/othello_state.cpp.o: games/othello/CMakeFiles/othello.dir/flags.make
games/othello/CMakeFiles/othello.dir/othello_state.cpp.o: games/othello/othello_state.cpp
games/othello/CMakeFiles/othello.dir/othello_state.cpp.o: games/othello/CMakeFiles/othello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Documents/Thesis_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object games/othello/CMakeFiles/othello.dir/othello_state.cpp.o"
	cd /Users/james/Documents/Thesis_C++/games/othello && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT games/othello/CMakeFiles/othello.dir/othello_state.cpp.o -MF CMakeFiles/othello.dir/othello_state.cpp.o.d -o CMakeFiles/othello.dir/othello_state.cpp.o -c /Users/james/Documents/Thesis_C++/games/othello/othello_state.cpp

games/othello/CMakeFiles/othello.dir/othello_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/othello.dir/othello_state.cpp.i"
	cd /Users/james/Documents/Thesis_C++/games/othello && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Documents/Thesis_C++/games/othello/othello_state.cpp > CMakeFiles/othello.dir/othello_state.cpp.i

games/othello/CMakeFiles/othello.dir/othello_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/othello.dir/othello_state.cpp.s"
	cd /Users/james/Documents/Thesis_C++/games/othello && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Documents/Thesis_C++/games/othello/othello_state.cpp -o CMakeFiles/othello.dir/othello_state.cpp.s

# Object files for target othello
othello_OBJECTS = \
"CMakeFiles/othello.dir/othello_state.cpp.o"

# External object files for target othello
othello_EXTERNAL_OBJECTS =

games/othello/libothello.a: games/othello/CMakeFiles/othello.dir/othello_state.cpp.o
games/othello/libothello.a: games/othello/CMakeFiles/othello.dir/build.make
games/othello/libothello.a: games/othello/CMakeFiles/othello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Documents/Thesis_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libothello.a"
	cd /Users/james/Documents/Thesis_C++/games/othello && $(CMAKE_COMMAND) -P CMakeFiles/othello.dir/cmake_clean_target.cmake
	cd /Users/james/Documents/Thesis_C++/games/othello && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/othello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
games/othello/CMakeFiles/othello.dir/build: games/othello/libothello.a
.PHONY : games/othello/CMakeFiles/othello.dir/build

games/othello/CMakeFiles/othello.dir/clean:
	cd /Users/james/Documents/Thesis_C++/games/othello && $(CMAKE_COMMAND) -P CMakeFiles/othello.dir/cmake_clean.cmake
.PHONY : games/othello/CMakeFiles/othello.dir/clean

games/othello/CMakeFiles/othello.dir/depend:
	cd /Users/james/Documents/Thesis_C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++/games/othello /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++/games/othello /Users/james/Documents/Thesis_C++/games/othello/CMakeFiles/othello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : games/othello/CMakeFiles/othello.dir/depend

