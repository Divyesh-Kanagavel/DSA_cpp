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
include CMakeFiles/bucketSort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bucketSort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bucketSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bucketSort.dir/flags.make

CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o: CMakeFiles/bucketSort.dir/flags.make
CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o: /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Sorting/bucketSort.cpp
CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o: CMakeFiles/bucketSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o -MF CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o.d -o CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o -c /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Sorting/bucketSort.cpp

CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Sorting/bucketSort.cpp > CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.i

CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Sorting/bucketSort.cpp -o CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.s

# Object files for target bucketSort
bucketSort_OBJECTS = \
"CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o"

# External object files for target bucketSort
bucketSort_EXTERNAL_OBJECTS =

bucketSort: CMakeFiles/bucketSort.dir/src/Sorting/bucketSort.cpp.o
bucketSort: CMakeFiles/bucketSort.dir/build.make
bucketSort: CMakeFiles/bucketSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bucketSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bucketSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bucketSort.dir/build: bucketSort
.PHONY : CMakeFiles/bucketSort.dir/build

CMakeFiles/bucketSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bucketSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bucketSort.dir/clean

CMakeFiles/bucketSort.dir/depend:
	cd /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles/bucketSort.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bucketSort.dir/depend

