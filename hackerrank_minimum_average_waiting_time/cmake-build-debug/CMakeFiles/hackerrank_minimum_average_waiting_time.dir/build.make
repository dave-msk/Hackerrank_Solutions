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
CMAKE_SOURCE_DIR = /home/david/ClionProjects/hackerrank_minimum_average_waiting_time

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hackerrank_minimum_average_waiting_time.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hackerrank_minimum_average_waiting_time.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hackerrank_minimum_average_waiting_time.dir/flags.make

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/flags.make
CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o -c /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/main.cpp

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/main.cpp > CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.i

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/main.cpp -o CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.s

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.requires

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.provides: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hackerrank_minimum_average_waiting_time.dir/build.make CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.provides

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.provides.build: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o


# Object files for target hackerrank_minimum_average_waiting_time
hackerrank_minimum_average_waiting_time_OBJECTS = \
"CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o"

# External object files for target hackerrank_minimum_average_waiting_time
hackerrank_minimum_average_waiting_time_EXTERNAL_OBJECTS =

hackerrank_minimum_average_waiting_time: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o
hackerrank_minimum_average_waiting_time: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/build.make
hackerrank_minimum_average_waiting_time: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hackerrank_minimum_average_waiting_time"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hackerrank_minimum_average_waiting_time.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hackerrank_minimum_average_waiting_time.dir/build: hackerrank_minimum_average_waiting_time

.PHONY : CMakeFiles/hackerrank_minimum_average_waiting_time.dir/build

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/requires: CMakeFiles/hackerrank_minimum_average_waiting_time.dir/main.cpp.o.requires

.PHONY : CMakeFiles/hackerrank_minimum_average_waiting_time.dir/requires

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hackerrank_minimum_average_waiting_time.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hackerrank_minimum_average_waiting_time.dir/clean

CMakeFiles/hackerrank_minimum_average_waiting_time.dir/depend:
	cd /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/ClionProjects/hackerrank_minimum_average_waiting_time /home/david/ClionProjects/hackerrank_minimum_average_waiting_time /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug /home/david/ClionProjects/hackerrank_minimum_average_waiting_time/cmake-build-debug/CMakeFiles/hackerrank_minimum_average_waiting_time.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hackerrank_minimum_average_waiting_time.dir/depend

