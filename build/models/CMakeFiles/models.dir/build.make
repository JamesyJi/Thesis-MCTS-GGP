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
CMAKE_BINARY_DIR = /Users/james/Documents/Thesis_C++/build

# Include any dependencies generated for this target.
include models/CMakeFiles/models.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include models/CMakeFiles/models.dir/compiler_depend.make

# Include the progress variables for this target.
include models/CMakeFiles/models.dir/progress.make

# Include the compile flags for this target's objects.
include models/CMakeFiles/models.dir/flags.make

models/CMakeFiles/models.dir/model.cpp.o: models/CMakeFiles/models.dir/flags.make
models/CMakeFiles/models.dir/model.cpp.o: ../models/model.cpp
models/CMakeFiles/models.dir/model.cpp.o: models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Documents/Thesis_C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object models/CMakeFiles/models.dir/model.cpp.o"
	cd /Users/james/Documents/Thesis_C++/build/models && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT models/CMakeFiles/models.dir/model.cpp.o -MF CMakeFiles/models.dir/model.cpp.o.d -o CMakeFiles/models.dir/model.cpp.o -c /Users/james/Documents/Thesis_C++/models/model.cpp

models/CMakeFiles/models.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/model.cpp.i"
	cd /Users/james/Documents/Thesis_C++/build/models && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Documents/Thesis_C++/models/model.cpp > CMakeFiles/models.dir/model.cpp.i

models/CMakeFiles/models.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/model.cpp.s"
	cd /Users/james/Documents/Thesis_C++/build/models && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Documents/Thesis_C++/models/model.cpp -o CMakeFiles/models.dir/model.cpp.s

# Object files for target models
models_OBJECTS = \
"CMakeFiles/models.dir/model.cpp.o"

# External object files for target models
models_EXTERNAL_OBJECTS =

models/libmodels.a: models/CMakeFiles/models.dir/model.cpp.o
models/libmodels.a: models/CMakeFiles/models.dir/build.make
models/libmodels.a: models/CMakeFiles/models.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Documents/Thesis_C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmodels.a"
	cd /Users/james/Documents/Thesis_C++/build/models && $(CMAKE_COMMAND) -P CMakeFiles/models.dir/cmake_clean_target.cmake
	cd /Users/james/Documents/Thesis_C++/build/models && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/models.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
models/CMakeFiles/models.dir/build: models/libmodels.a
.PHONY : models/CMakeFiles/models.dir/build

models/CMakeFiles/models.dir/clean:
	cd /Users/james/Documents/Thesis_C++/build/models && $(CMAKE_COMMAND) -P CMakeFiles/models.dir/cmake_clean.cmake
.PHONY : models/CMakeFiles/models.dir/clean

models/CMakeFiles/models.dir/depend:
	cd /Users/james/Documents/Thesis_C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Documents/Thesis_C++ /Users/james/Documents/Thesis_C++/models /Users/james/Documents/Thesis_C++/build /Users/james/Documents/Thesis_C++/build/models /Users/james/Documents/Thesis_C++/build/models/CMakeFiles/models.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : models/CMakeFiles/models.dir/depend
