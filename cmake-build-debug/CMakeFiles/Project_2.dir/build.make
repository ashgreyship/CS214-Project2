# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "/Users/gabriel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/gabriel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_2.dir/flags.make

CMakeFiles/Project_2.dir/main.c.o: CMakeFiles/Project_2.dir/flags.make
CMakeFiles/Project_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Project_2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Project_2.dir/main.c.o   -c "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/main.c"

CMakeFiles/Project_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project_2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/main.c" > CMakeFiles/Project_2.dir/main.c.i

CMakeFiles/Project_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project_2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/main.c" -o CMakeFiles/Project_2.dir/main.c.s

CMakeFiles/Project_2.dir/main.c.o.requires:

.PHONY : CMakeFiles/Project_2.dir/main.c.o.requires

CMakeFiles/Project_2.dir/main.c.o.provides: CMakeFiles/Project_2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Project_2.dir/build.make CMakeFiles/Project_2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Project_2.dir/main.c.o.provides

CMakeFiles/Project_2.dir/main.c.o.provides.build: CMakeFiles/Project_2.dir/main.c.o


CMakeFiles/Project_2.dir/mergesort.c.o: CMakeFiles/Project_2.dir/flags.make
CMakeFiles/Project_2.dir/mergesort.c.o: ../mergesort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Project_2.dir/mergesort.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Project_2.dir/mergesort.c.o   -c "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/mergesort.c"

CMakeFiles/Project_2.dir/mergesort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project_2.dir/mergesort.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/mergesort.c" > CMakeFiles/Project_2.dir/mergesort.c.i

CMakeFiles/Project_2.dir/mergesort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project_2.dir/mergesort.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/mergesort.c" -o CMakeFiles/Project_2.dir/mergesort.c.s

CMakeFiles/Project_2.dir/mergesort.c.o.requires:

.PHONY : CMakeFiles/Project_2.dir/mergesort.c.o.requires

CMakeFiles/Project_2.dir/mergesort.c.o.provides: CMakeFiles/Project_2.dir/mergesort.c.o.requires
	$(MAKE) -f CMakeFiles/Project_2.dir/build.make CMakeFiles/Project_2.dir/mergesort.c.o.provides.build
.PHONY : CMakeFiles/Project_2.dir/mergesort.c.o.provides

CMakeFiles/Project_2.dir/mergesort.c.o.provides.build: CMakeFiles/Project_2.dir/mergesort.c.o


CMakeFiles/Project_2.dir/sorter.c.o: CMakeFiles/Project_2.dir/flags.make
CMakeFiles/Project_2.dir/sorter.c.o: ../sorter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Project_2.dir/sorter.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Project_2.dir/sorter.c.o   -c "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/sorter.c"

CMakeFiles/Project_2.dir/sorter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project_2.dir/sorter.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/sorter.c" > CMakeFiles/Project_2.dir/sorter.c.i

CMakeFiles/Project_2.dir/sorter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project_2.dir/sorter.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/sorter.c" -o CMakeFiles/Project_2.dir/sorter.c.s

CMakeFiles/Project_2.dir/sorter.c.o.requires:

.PHONY : CMakeFiles/Project_2.dir/sorter.c.o.requires

CMakeFiles/Project_2.dir/sorter.c.o.provides: CMakeFiles/Project_2.dir/sorter.c.o.requires
	$(MAKE) -f CMakeFiles/Project_2.dir/build.make CMakeFiles/Project_2.dir/sorter.c.o.provides.build
.PHONY : CMakeFiles/Project_2.dir/sorter.c.o.provides

CMakeFiles/Project_2.dir/sorter.c.o.provides.build: CMakeFiles/Project_2.dir/sorter.c.o


CMakeFiles/Project_2.dir/test.c.o: CMakeFiles/Project_2.dir/flags.make
CMakeFiles/Project_2.dir/test.c.o: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Project_2.dir/test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Project_2.dir/test.c.o   -c "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/test.c"

CMakeFiles/Project_2.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project_2.dir/test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/test.c" > CMakeFiles/Project_2.dir/test.c.i

CMakeFiles/Project_2.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project_2.dir/test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/test.c" -o CMakeFiles/Project_2.dir/test.c.s

CMakeFiles/Project_2.dir/test.c.o.requires:

.PHONY : CMakeFiles/Project_2.dir/test.c.o.requires

CMakeFiles/Project_2.dir/test.c.o.provides: CMakeFiles/Project_2.dir/test.c.o.requires
	$(MAKE) -f CMakeFiles/Project_2.dir/build.make CMakeFiles/Project_2.dir/test.c.o.provides.build
.PHONY : CMakeFiles/Project_2.dir/test.c.o.provides

CMakeFiles/Project_2.dir/test.c.o.provides.build: CMakeFiles/Project_2.dir/test.c.o


# Object files for target Project_2
Project_2_OBJECTS = \
"CMakeFiles/Project_2.dir/main.c.o" \
"CMakeFiles/Project_2.dir/mergesort.c.o" \
"CMakeFiles/Project_2.dir/sorter.c.o" \
"CMakeFiles/Project_2.dir/test.c.o"

# External object files for target Project_2
Project_2_EXTERNAL_OBJECTS =

Project_2: CMakeFiles/Project_2.dir/main.c.o
Project_2: CMakeFiles/Project_2.dir/mergesort.c.o
Project_2: CMakeFiles/Project_2.dir/sorter.c.o
Project_2: CMakeFiles/Project_2.dir/test.c.o
Project_2: CMakeFiles/Project_2.dir/build.make
Project_2: CMakeFiles/Project_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Project_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_2.dir/build: Project_2

.PHONY : CMakeFiles/Project_2.dir/build

CMakeFiles/Project_2.dir/requires: CMakeFiles/Project_2.dir/main.c.o.requires
CMakeFiles/Project_2.dir/requires: CMakeFiles/Project_2.dir/mergesort.c.o.requires
CMakeFiles/Project_2.dir/requires: CMakeFiles/Project_2.dir/sorter.c.o.requires
CMakeFiles/Project_2.dir/requires: CMakeFiles/Project_2.dir/test.c.o.requires

.PHONY : CMakeFiles/Project_2.dir/requires

CMakeFiles/Project_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_2.dir/clean

CMakeFiles/Project_2.dir/depend:
	cd "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2" "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2" "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug" "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug" "/Users/gabriel/Onedrive/Education/RU/5th semester/Systems Programming/Project 2/cmake-build-debug/CMakeFiles/Project_2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project_2.dir/depend

