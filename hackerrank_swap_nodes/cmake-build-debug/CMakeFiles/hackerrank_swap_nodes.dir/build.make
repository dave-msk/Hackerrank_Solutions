# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/david/IDE/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/david/IDE/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/ClionProjects/hackerrank_swap_nodes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hackerrank_swap_nodes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hackerrank_swap_nodes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hackerrank_swap_nodes.dir/flags.make

CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o: CMakeFiles/hackerrank_swap_nodes.dir/flags.make
CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o -c /home/david/ClionProjects/hackerrank_swap_nodes/main.cpp

CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/ClionProjects/hackerrank_swap_nodes/main.cpp > CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.i

CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/ClionProjects/hackerrank_swap_nodes/main.cpp -o CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.s

CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.requires

CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.provides: CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hackerrank_swap_nodes.dir/build.make CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.provides

CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.provides.build: CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o


# Object files for target hackerrank_swap_nodes
hackerrank_swap_nodes_OBJECTS = \
"CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o"

# External object files for target hackerrank_swap_nodes
hackerrank_swap_nodes_EXTERNAL_OBJECTS =

hackerrank_swap_nodes: CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o
hackerrank_swap_nodes: CMakeFiles/hackerrank_swap_nodes.dir/build.make
hackerrank_swap_nodes: CMakeFiles/hackerrank_swap_nodes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hackerrank_swap_nodes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hackerrank_swap_nodes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hackerrank_swap_nodes.dir/build: hackerrank_swap_nodes

.PHONY : CMakeFiles/hackerrank_swap_nodes.dir/build

CMakeFiles/hackerrank_swap_nodes.dir/requires: CMakeFiles/hackerrank_swap_nodes.dir/main.cpp.o.requires

.PHONY : CMakeFiles/hackerrank_swap_nodes.dir/requires

CMakeFiles/hackerrank_swap_nodes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hackerrank_swap_nodes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hackerrank_swap_nodes.dir/clean

CMakeFiles/hackerrank_swap_nodes.dir/depend:
	cd /home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/ClionProjects/hackerrank_swap_nodes /home/david/ClionProjects/hackerrank_swap_nodes /home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug /home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug /home/david/ClionProjects/hackerrank_swap_nodes/cmake-build-debug/CMakeFiles/hackerrank_swap_nodes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hackerrank_swap_nodes.dir/depend

