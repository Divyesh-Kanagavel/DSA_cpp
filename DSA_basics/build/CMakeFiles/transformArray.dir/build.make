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
include CMakeFiles/transformArray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/transformArray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/transformArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/transformArray.dir/flags.make

CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o: CMakeFiles/transformArray.dir/flags.make
CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o: /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/transformArray.cpp
CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o: CMakeFiles/transformArray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o -MF CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o.d -o CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o -c /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/transformArray.cpp

CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/transformArray.cpp > CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.i

CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/transformArray.cpp -o CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.s

# Object files for target transformArray
transformArray_OBJECTS = \
"CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o"

# External object files for target transformArray
transformArray_EXTERNAL_OBJECTS =

transformArray: CMakeFiles/transformArray.dir/src/Searching/transformArray.cpp.o
transformArray: CMakeFiles/transformArray.dir/build.make
transformArray: CMakeFiles/transformArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable transformArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/transformArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/transformArray.dir/build: transformArray
.PHONY : CMakeFiles/transformArray.dir/build

CMakeFiles/transformArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/transformArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/transformArray.dir/clean

CMakeFiles/transformArray.dir/depend:
	cd /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles/transformArray.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/transformArray.dir/depend

