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
include CMakeFiles/stockPurchase.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stockPurchase.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stockPurchase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stockPurchase.dir/flags.make

CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o: CMakeFiles/stockPurchase.dir/flags.make
CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o: /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/stockPurchase.cpp
CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o: CMakeFiles/stockPurchase.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o -MF CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o.d -o CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o -c /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/stockPurchase.cpp

CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/stockPurchase.cpp > CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.i

CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/src/Searching/stockPurchase.cpp -o CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.s

# Object files for target stockPurchase
stockPurchase_OBJECTS = \
"CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o"

# External object files for target stockPurchase
stockPurchase_EXTERNAL_OBJECTS =

stockPurchase: CMakeFiles/stockPurchase.dir/src/Searching/stockPurchase.cpp.o
stockPurchase: CMakeFiles/stockPurchase.dir/build.make
stockPurchase: CMakeFiles/stockPurchase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stockPurchase"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stockPurchase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stockPurchase.dir/build: stockPurchase
.PHONY : CMakeFiles/stockPurchase.dir/build

CMakeFiles/stockPurchase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stockPurchase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stockPurchase.dir/clean

CMakeFiles/stockPurchase.dir/depend:
	cd /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build /Users/divyeshkanagavel/Desktop/DSA_cpp/CP_programming/build/CMakeFiles/stockPurchase.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/stockPurchase.dir/depend

