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
include CMakeFiles/medianArray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/medianArray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/medianArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/medianArray.dir/flags.make

CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o: CMakeFiles/medianArray.dir/flags.make
CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o: /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/medianArray.cpp
CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o: CMakeFiles/medianArray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o -MF CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o.d -o CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o -c /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/medianArray.cpp

CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/medianArray.cpp > CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.i

CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/medianArray.cpp -o CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.s

# Object files for target medianArray
medianArray_OBJECTS = \
"CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o"

# External object files for target medianArray
medianArray_EXTERNAL_OBJECTS =

medianArray: CMakeFiles/medianArray.dir/src/Searching/medianArray.cpp.o
medianArray: CMakeFiles/medianArray.dir/build.make
medianArray: CMakeFiles/medianArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable medianArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/medianArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/medianArray.dir/build: medianArray
.PHONY : CMakeFiles/medianArray.dir/build

CMakeFiles/medianArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/medianArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/medianArray.dir/clean

CMakeFiles/medianArray.dir/depend:
	cd /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles/medianArray.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/medianArray.dir/depend

