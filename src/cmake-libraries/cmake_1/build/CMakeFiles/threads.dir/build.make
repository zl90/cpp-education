# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build

# Include any dependencies generated for this target.
include CMakeFiles/threads.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/threads.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/threads.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threads.dir/flags.make

CMakeFiles/threads.dir/threads.cpp.o: CMakeFiles/threads.dir/flags.make
CMakeFiles/threads.dir/threads.cpp.o: ../threads.cpp
CMakeFiles/threads.dir/threads.cpp.o: CMakeFiles/threads.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/threads.dir/threads.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/threads.dir/threads.cpp.o -MF CMakeFiles/threads.dir/threads.cpp.o.d -o CMakeFiles/threads.dir/threads.cpp.o -c /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/threads.cpp

CMakeFiles/threads.dir/threads.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/threads.dir/threads.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/threads.cpp > CMakeFiles/threads.dir/threads.cpp.i

CMakeFiles/threads.dir/threads.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/threads.dir/threads.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/threads.cpp -o CMakeFiles/threads.dir/threads.cpp.s

# Object files for target threads
threads_OBJECTS = \
"CMakeFiles/threads.dir/threads.cpp.o"

# External object files for target threads
threads_EXTERNAL_OBJECTS =

threads: CMakeFiles/threads.dir/threads.cpp.o
threads: CMakeFiles/threads.dir/build.make
threads: CMakeFiles/threads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable threads"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threads.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threads.dir/build: threads
.PHONY : CMakeFiles/threads.dir/build

CMakeFiles/threads.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/threads.dir/cmake_clean.cmake
.PHONY : CMakeFiles/threads.dir/clean

CMakeFiles/threads.dir/depend:
	cd /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1 /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1 /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build /home/thinkgod/Documents/code/cpp-education/src/cmake-libraries/cmake_1/build/CMakeFiles/threads.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/threads.dir/depend
