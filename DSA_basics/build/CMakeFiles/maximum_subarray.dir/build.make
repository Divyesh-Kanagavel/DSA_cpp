# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build

# Include any dependencies generated for this target.
include CMakeFiles/maximum_subarray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/maximum_subarray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/maximum_subarray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maximum_subarray.dir/flags.make

CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o: CMakeFiles/maximum_subarray.dir/flags.make
CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o: /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/basics/maxsum_subarray.c
CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o: CMakeFiles/maximum_subarray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o -MF CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o.d -o CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o -c /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/basics/maxsum_subarray.c

CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/basics/maxsum_subarray.c > CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.i

CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/basics/maxsum_subarray.c -o CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.s

# Object files for target maximum_subarray
maximum_subarray_OBJECTS = \
"CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o"

# External object files for target maximum_subarray
maximum_subarray_EXTERNAL_OBJECTS =

maximum_subarray: CMakeFiles/maximum_subarray.dir/src/basics/maxsum_subarray.c.o
maximum_subarray: CMakeFiles/maximum_subarray.dir/build.make
maximum_subarray: CMakeFiles/maximum_subarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable maximum_subarray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/maximum_subarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maximum_subarray.dir/build: maximum_subarray
.PHONY : CMakeFiles/maximum_subarray.dir/build

CMakeFiles/maximum_subarray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/maximum_subarray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/maximum_subarray.dir/clean

CMakeFiles/maximum_subarray.dir/depend:
	cd /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles/maximum_subarray.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/maximum_subarray.dir/depend

