# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shashwat/Documents/CPL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shashwat/Documents/CPL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SergeySubway.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SergeySubway.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SergeySubway.dir/flags.make

CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.o: CMakeFiles/SergeySubway.dir/flags.make
CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.o: ../Upsolve/DIV1CVirtual1/SergeySubway.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shashwat/Documents/CPL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.o -c /home/shashwat/Documents/CPL/Upsolve/DIV1CVirtual1/SergeySubway.cpp

CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shashwat/Documents/CPL/Upsolve/DIV1CVirtual1/SergeySubway.cpp > CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.i

CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shashwat/Documents/CPL/Upsolve/DIV1CVirtual1/SergeySubway.cpp -o CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.s

# Object files for target SergeySubway
SergeySubway_OBJECTS = \
"CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.o"

# External object files for target SergeySubway
SergeySubway_EXTERNAL_OBJECTS =

SergeySubway: CMakeFiles/SergeySubway.dir/Upsolve/DIV1CVirtual1/SergeySubway.cpp.o
SergeySubway: CMakeFiles/SergeySubway.dir/build.make
SergeySubway: CMakeFiles/SergeySubway.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shashwat/Documents/CPL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SergeySubway"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SergeySubway.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SergeySubway.dir/build: SergeySubway

.PHONY : CMakeFiles/SergeySubway.dir/build

CMakeFiles/SergeySubway.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SergeySubway.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SergeySubway.dir/clean

CMakeFiles/SergeySubway.dir/depend:
	cd /home/shashwat/Documents/CPL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shashwat/Documents/CPL /home/shashwat/Documents/CPL /home/shashwat/Documents/CPL/cmake-build-debug /home/shashwat/Documents/CPL/cmake-build-debug /home/shashwat/Documents/CPL/cmake-build-debug/CMakeFiles/SergeySubway.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SergeySubway.dir/depend

