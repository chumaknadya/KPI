# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ziom/progbase2/tasks/xml1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziom/progbase2/tasks/xml1/build

# Include any dependencies generated for this target.
include CMakeFiles/proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj.dir/flags.make

CMakeFiles/proj.dir/main.c.o: CMakeFiles/proj.dir/flags.make
CMakeFiles/proj.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziom/progbase2/tasks/xml1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/proj.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/proj.dir/main.c.o   -c /home/ziom/progbase2/tasks/xml1/main.c

CMakeFiles/proj.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziom/progbase2/tasks/xml1/main.c > CMakeFiles/proj.dir/main.c.i

CMakeFiles/proj.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziom/progbase2/tasks/xml1/main.c -o CMakeFiles/proj.dir/main.c.s

CMakeFiles/proj.dir/main.c.o.requires:

.PHONY : CMakeFiles/proj.dir/main.c.o.requires

CMakeFiles/proj.dir/main.c.o.provides: CMakeFiles/proj.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/proj.dir/build.make CMakeFiles/proj.dir/main.c.o.provides.build
.PHONY : CMakeFiles/proj.dir/main.c.o.provides

CMakeFiles/proj.dir/main.c.o.provides.build: CMakeFiles/proj.dir/main.c.o


# Object files for target proj
proj_OBJECTS = \
"CMakeFiles/proj.dir/main.c.o"

# External object files for target proj
proj_EXTERNAL_OBJECTS =

proj: CMakeFiles/proj.dir/main.c.o
proj: CMakeFiles/proj.dir/build.make
proj: CMakeFiles/proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziom/progbase2/tasks/xml1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable proj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj.dir/build: proj

.PHONY : CMakeFiles/proj.dir/build

CMakeFiles/proj.dir/requires: CMakeFiles/proj.dir/main.c.o.requires

.PHONY : CMakeFiles/proj.dir/requires

CMakeFiles/proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj.dir/clean

CMakeFiles/proj.dir/depend:
	cd /home/ziom/progbase2/tasks/xml1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziom/progbase2/tasks/xml1 /home/ziom/progbase2/tasks/xml1 /home/ziom/progbase2/tasks/xml1/build /home/ziom/progbase2/tasks/xml1/build /home/ziom/progbase2/tasks/xml1/build/CMakeFiles/proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj.dir/depend

