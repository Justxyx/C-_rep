# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p7.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/p7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p7.dir/flags.make

CMakeFiles/p7.dir/main.cpp.o: CMakeFiles/p7.dir/flags.make
CMakeFiles/p7.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p7.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p7.dir/main.cpp.o -c /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/main.cpp

CMakeFiles/p7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p7.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/main.cpp > CMakeFiles/p7.dir/main.cpp.i

CMakeFiles/p7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p7.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/main.cpp -o CMakeFiles/p7.dir/main.cpp.s

CMakeFiles/p7.dir/p7.1.cpp.o: CMakeFiles/p7.dir/flags.make
CMakeFiles/p7.dir/p7.1.cpp.o: ../p7.1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p7.dir/p7.1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p7.dir/p7.1.cpp.o -c /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/p7.1.cpp

CMakeFiles/p7.dir/p7.1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p7.dir/p7.1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/p7.1.cpp > CMakeFiles/p7.dir/p7.1.cpp.i

CMakeFiles/p7.dir/p7.1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p7.dir/p7.1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/p7.1.cpp -o CMakeFiles/p7.dir/p7.1.cpp.s

# Object files for target p7
p7_OBJECTS = \
"CMakeFiles/p7.dir/main.cpp.o" \
"CMakeFiles/p7.dir/p7.1.cpp.o"

# External object files for target p7
p7_EXTERNAL_OBJECTS =

p7: CMakeFiles/p7.dir/main.cpp.o
p7: CMakeFiles/p7.dir/p7.1.cpp.o
p7: CMakeFiles/p7.dir/build.make
p7: CMakeFiles/p7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable p7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p7.dir/build: p7
.PHONY : CMakeFiles/p7.dir/build

CMakeFiles/p7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p7.dir/clean

CMakeFiles/p7.dir/depend:
	cd /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类 /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类 /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug /Users/xiaoyingxiong/projects/ClionProjects/Cpp_rep/C++Primer/p7类/cmake-build-debug/CMakeFiles/p7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p7.dir/depend

