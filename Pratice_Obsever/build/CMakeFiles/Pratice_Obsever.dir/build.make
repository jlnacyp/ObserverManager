# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yang/桌面/Pratice_Obsever

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yang/桌面/Pratice_Obsever/build

# Include any dependencies generated for this target.
include CMakeFiles/Pratice_Obsever.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pratice_Obsever.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pratice_Obsever.dir/flags.make

CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o: CMakeFiles/Pratice_Obsever.dir/flags.make
CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/桌面/Pratice_Obsever/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o -c /home/yang/桌面/Pratice_Obsever/src/main.cpp

CMakeFiles/Pratice_Obsever.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pratice_Obsever.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yang/桌面/Pratice_Obsever/src/main.cpp > CMakeFiles/Pratice_Obsever.dir/src/main.cpp.i

CMakeFiles/Pratice_Obsever.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pratice_Obsever.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yang/桌面/Pratice_Obsever/src/main.cpp -o CMakeFiles/Pratice_Obsever.dir/src/main.cpp.s

CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.requires

CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.provides: CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Pratice_Obsever.dir/build.make CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.provides

CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.provides.build: CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o


# Object files for target Pratice_Obsever
Pratice_Obsever_OBJECTS = \
"CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o"

# External object files for target Pratice_Obsever
Pratice_Obsever_EXTERNAL_OBJECTS =

Pratice_Obsever: CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o
Pratice_Obsever: CMakeFiles/Pratice_Obsever.dir/build.make
Pratice_Obsever: CMakeFiles/Pratice_Obsever.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yang/桌面/Pratice_Obsever/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pratice_Obsever"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pratice_Obsever.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pratice_Obsever.dir/build: Pratice_Obsever

.PHONY : CMakeFiles/Pratice_Obsever.dir/build

CMakeFiles/Pratice_Obsever.dir/requires: CMakeFiles/Pratice_Obsever.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Pratice_Obsever.dir/requires

CMakeFiles/Pratice_Obsever.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pratice_Obsever.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pratice_Obsever.dir/clean

CMakeFiles/Pratice_Obsever.dir/depend:
	cd /home/yang/桌面/Pratice_Obsever/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yang/桌面/Pratice_Obsever /home/yang/桌面/Pratice_Obsever /home/yang/桌面/Pratice_Obsever/build /home/yang/桌面/Pratice_Obsever/build /home/yang/桌面/Pratice_Obsever/build/CMakeFiles/Pratice_Obsever.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pratice_Obsever.dir/depend

