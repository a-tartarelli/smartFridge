# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/peppe/Desktop/proj/SmartFridge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mySmartFridge.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mySmartFridge.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mySmartFridge.dir/flags.make

src/CMakeFiles/mySmartFridge.dir/main.c.o: src/CMakeFiles/mySmartFridge.dir/flags.make
src/CMakeFiles/mySmartFridge.dir/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/mySmartFridge.dir/main.c.o"
	cd /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mySmartFridge.dir/main.c.o   -c /mnt/c/Users/peppe/Desktop/proj/SmartFridge/src/main.c

src/CMakeFiles/mySmartFridge.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mySmartFridge.dir/main.c.i"
	cd /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/peppe/Desktop/proj/SmartFridge/src/main.c > CMakeFiles/mySmartFridge.dir/main.c.i

src/CMakeFiles/mySmartFridge.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mySmartFridge.dir/main.c.s"
	cd /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/peppe/Desktop/proj/SmartFridge/src/main.c -o CMakeFiles/mySmartFridge.dir/main.c.s

# Object files for target mySmartFridge
mySmartFridge_OBJECTS = \
"CMakeFiles/mySmartFridge.dir/main.c.o"

# External object files for target mySmartFridge
mySmartFridge_EXTERNAL_OBJECTS =

bin/mySmartFridge: src/CMakeFiles/mySmartFridge.dir/main.c.o
bin/mySmartFridge: src/CMakeFiles/mySmartFridge.dir/build.make
bin/mySmartFridge: lib/libsmartfridge.a
bin/mySmartFridge: src/CMakeFiles/mySmartFridge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/mySmartFridge"
	cd /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mySmartFridge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mySmartFridge.dir/build: bin/mySmartFridge

.PHONY : src/CMakeFiles/mySmartFridge.dir/build

src/CMakeFiles/mySmartFridge.dir/clean:
	cd /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mySmartFridge.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mySmartFridge.dir/clean

src/CMakeFiles/mySmartFridge.dir/depend:
	cd /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/peppe/Desktop/proj/SmartFridge /mnt/c/Users/peppe/Desktop/proj/SmartFridge/src /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src /mnt/c/Users/peppe/Desktop/proj/SmartFridge/build/src/CMakeFiles/mySmartFridge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mySmartFridge.dir/depend

