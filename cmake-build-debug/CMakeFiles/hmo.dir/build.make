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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shashwat/Documents/CPL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shashwat/Documents/CPL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hmo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hmo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hmo.dir/flags.make

CMakeFiles/hmo.dir/OJ/hmo.cpp.o: CMakeFiles/hmo.dir/flags.make
CMakeFiles/hmo.dir/OJ/hmo.cpp.o: ../OJ/hmo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shashwat/Documents/CPL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hmo.dir/OJ/hmo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hmo.dir/OJ/hmo.cpp.o -c /home/shashwat/Documents/CPL/OJ/hmo.cpp

CMakeFiles/hmo.dir/OJ/hmo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hmo.dir/OJ/hmo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shashwat/Documents/CPL/OJ/hmo.cpp > CMakeFiles/hmo.dir/OJ/hmo.cpp.i

CMakeFiles/hmo.dir/OJ/hmo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hmo.dir/OJ/hmo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shashwat/Documents/CPL/OJ/hmo.cpp -o CMakeFiles/hmo.dir/OJ/hmo.cpp.s

# Object files for target hmo
hmo_OBJECTS = \
"CMakeFiles/hmo.dir/OJ/hmo.cpp.o"

# External object files for target hmo
hmo_EXTERNAL_OBJECTS =

hmo: CMakeFiles/hmo.dir/OJ/hmo.cpp.o
hmo: CMakeFiles/hmo.dir/build.make
hmo: CMakeFiles/hmo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shashwat/Documents/CPL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hmo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hmo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hmo.dir/build: hmo

.PHONY : CMakeFiles/hmo.dir/build

CMakeFiles/hmo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hmo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hmo.dir/clean

CMakeFiles/hmo.dir/depend:
	cd /home/shashwat/Documents/CPL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shashwat/Documents/CPL /home/shashwat/Documents/CPL /home/shashwat/Documents/CPL/cmake-build-debug /home/shashwat/Documents/CPL/cmake-build-debug /home/shashwat/Documents/CPL/cmake-build-debug/CMakeFiles/hmo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hmo.dir/depend

