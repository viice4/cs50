# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "U:\Programs\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "U:\Programs\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = U:\Projects\C\cs50\cash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = U:\Projects\C\cs50\cash\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cash.dir/flags.make

CMakeFiles/cash.dir/main.c.obj: CMakeFiles/cash.dir/flags.make
CMakeFiles/cash.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=U:\Projects\C\cs50\cash\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cash.dir/main.c.obj"
	U:\Programs\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cash.dir\main.c.obj   -c U:\Projects\C\cs50\cash\main.c

CMakeFiles/cash.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cash.dir/main.c.i"
	U:\Programs\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E U:\Projects\C\cs50\cash\main.c > CMakeFiles\cash.dir\main.c.i

CMakeFiles/cash.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cash.dir/main.c.s"
	U:\Programs\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S U:\Projects\C\cs50\cash\main.c -o CMakeFiles\cash.dir\main.c.s

# Object files for target cash
cash_OBJECTS = \
"CMakeFiles/cash.dir/main.c.obj"

# External object files for target cash
cash_EXTERNAL_OBJECTS =

cash.exe: CMakeFiles/cash.dir/main.c.obj
cash.exe: CMakeFiles/cash.dir/build.make
cash.exe: CMakeFiles/cash.dir/linklibs.rsp
cash.exe: CMakeFiles/cash.dir/objects1.rsp
cash.exe: CMakeFiles/cash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=U:\Projects\C\cs50\cash\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cash.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cash.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cash.dir/build: cash.exe

.PHONY : CMakeFiles/cash.dir/build

CMakeFiles/cash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cash.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cash.dir/clean

CMakeFiles/cash.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" U:\Projects\C\cs50\cash U:\Projects\C\cs50\cash U:\Projects\C\cs50\cash\cmake-build-debug U:\Projects\C\cs50\cash\cmake-build-debug U:\Projects\C\cs50\cash\cmake-build-debug\CMakeFiles\cash.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cash.dir/depend

