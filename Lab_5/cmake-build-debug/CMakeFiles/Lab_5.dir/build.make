# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/willard/ECE220/Lab_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/willard/ECE220/Lab_5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_5.dir/flags.make

CMakeFiles/Lab_5.dir/main.cpp.o: CMakeFiles/Lab_5.dir/flags.make
CMakeFiles/Lab_5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willard/ECE220/Lab_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_5.dir/main.cpp.o"
	/usr/lib/ccache/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_5.dir/main.cpp.o -c /home/willard/ECE220/Lab_5/main.cpp

CMakeFiles/Lab_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_5.dir/main.cpp.i"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/willard/ECE220/Lab_5/main.cpp > CMakeFiles/Lab_5.dir/main.cpp.i

CMakeFiles/Lab_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_5.dir/main.cpp.s"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/willard/ECE220/Lab_5/main.cpp -o CMakeFiles/Lab_5.dir/main.cpp.s

CMakeFiles/Lab_5.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lab_5.dir/main.cpp.o.requires

CMakeFiles/Lab_5.dir/main.cpp.o.provides: CMakeFiles/Lab_5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab_5.dir/build.make CMakeFiles/Lab_5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lab_5.dir/main.cpp.o.provides

CMakeFiles/Lab_5.dir/main.cpp.o.provides.build: CMakeFiles/Lab_5.dir/main.cpp.o


# Object files for target Lab_5
Lab_5_OBJECTS = \
"CMakeFiles/Lab_5.dir/main.cpp.o"

# External object files for target Lab_5
Lab_5_EXTERNAL_OBJECTS =

Lab_5: CMakeFiles/Lab_5.dir/main.cpp.o
Lab_5: CMakeFiles/Lab_5.dir/build.make
Lab_5: CMakeFiles/Lab_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/willard/ECE220/Lab_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_5.dir/build: Lab_5

.PHONY : CMakeFiles/Lab_5.dir/build

CMakeFiles/Lab_5.dir/requires: CMakeFiles/Lab_5.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Lab_5.dir/requires

CMakeFiles/Lab_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab_5.dir/clean

CMakeFiles/Lab_5.dir/depend:
	cd /home/willard/ECE220/Lab_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/willard/ECE220/Lab_5 /home/willard/ECE220/Lab_5 /home/willard/ECE220/Lab_5/cmake-build-debug /home/willard/ECE220/Lab_5/cmake-build-debug /home/willard/ECE220/Lab_5/cmake-build-debug/CMakeFiles/Lab_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab_5.dir/depend

