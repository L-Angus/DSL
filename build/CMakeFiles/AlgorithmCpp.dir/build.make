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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/lishundong/Desktop/2023/DataStructure&Algorithm"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build"

# Include any dependencies generated for this target.
include CMakeFiles/AlgorithmCpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AlgorithmCpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgorithmCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgorithmCpp.dir/flags.make

CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o: CMakeFiles/AlgorithmCpp.dir/flags.make
CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o: ../src/ProcessRawData.cpp
CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o: CMakeFiles/AlgorithmCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o -MF CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o.d -o CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o -c "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/src/ProcessRawData.cpp"

CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/src/ProcessRawData.cpp" > CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.i

CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/src/ProcessRawData.cpp" -o CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.s

CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o: CMakeFiles/AlgorithmCpp.dir/flags.make
CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o: CMakeFiles/AlgorithmCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o -MF CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o.d -o CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o -c "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/src/main.cpp"

CMakeFiles/AlgorithmCpp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmCpp.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/src/main.cpp" > CMakeFiles/AlgorithmCpp.dir/src/main.cpp.i

CMakeFiles/AlgorithmCpp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmCpp.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/src/main.cpp" -o CMakeFiles/AlgorithmCpp.dir/src/main.cpp.s

# Object files for target AlgorithmCpp
AlgorithmCpp_OBJECTS = \
"CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o" \
"CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o"

# External object files for target AlgorithmCpp
AlgorithmCpp_EXTERNAL_OBJECTS =

AlgorithmCpp: CMakeFiles/AlgorithmCpp.dir/src/ProcessRawData.cpp.o
AlgorithmCpp: CMakeFiles/AlgorithmCpp.dir/src/main.cpp.o
AlgorithmCpp: CMakeFiles/AlgorithmCpp.dir/build.make
AlgorithmCpp: CMakeFiles/AlgorithmCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AlgorithmCpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AlgorithmCpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgorithmCpp.dir/build: AlgorithmCpp
.PHONY : CMakeFiles/AlgorithmCpp.dir/build

CMakeFiles/AlgorithmCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AlgorithmCpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AlgorithmCpp.dir/clean

CMakeFiles/AlgorithmCpp.dir/depend:
	cd "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/lishundong/Desktop/2023/DataStructure&Algorithm" "/Users/lishundong/Desktop/2023/DataStructure&Algorithm" "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build" "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build" "/Users/lishundong/Desktop/2023/DataStructure&Algorithm/build/CMakeFiles/AlgorithmCpp.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AlgorithmCpp.dir/depend

