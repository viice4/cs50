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
CMAKE_SOURCE_DIR = U:\Projects\C\cs50\caesar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = U:\Projects\C\cs50\caesar\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/caesar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/caesar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/caesar.dir/flags.make

CMakeFiles/caesar.dir/main.c.obj: CMakeFiles/caesar.dir/flags.make
CMakeFiles/caesar.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=U:\Projects\C\cs50\caesar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/caesar.dir/main.c.obj"
	U:\Programs\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\caesar.dir\main.c.obj   -c U:\Projects\C\cs50\caesar\main.c

CMakeFiles/caesar.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/caesar.dir/main.c.i"
	U:\Programs\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E U:\Projects\C\cs50\caesar\main.c > CMakeFiles\caesar.dir\main.c.i

CMakeFiles/caesar.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/caesar.dir/main.c.s"
	U:\Programs\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S U:\Projects\C\cs50\caesar\main.c -o CMakeFiles\caesar.dir\main.c.s

# Object files for target caesar
caesar_OBJECTS = \
"CMakeFiles/caesar.dir/main.c.obj"

# External object files for target caesar
caesar_EXTERNAL_OBJECTS =

caesar.exe: CMakeFiles/caesar.dir/main.c.obj
caesar.exe: CMakeFiles/caesar.dir/build.make
caesar.exe: CMakeFiles/caesar.dir/linklibs.rsp
caesar.exe: CMakeFiles/caesar.dir/objects1.rsp
caesar.exe: CMakeFiles/caesar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=U:\Projects\C\cs50\caesar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable caesar.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\caesar.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/caesar.dir/build: caesar.exe

.PHONY : CMakeFiles/caesar.dir/build

CMakeFiles/caesar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\caesar.dir\cmake_clean.cmake
.PHONY : CMakeFiles/caesar.dir/clean

CMakeFiles/caesar.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" U:\Projects\C\cs50\caesar U:\Projects\C\cs50\caesar U:\Projects\C\cs50\caesar\cmake-build-debug U:\Projects\C\cs50\caesar\cmake-build-debug U:\Projects\C\cs50\caesar\cmake-build-debug\CMakeFiles\caesar.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/caesar.dir/depend

