# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tayboonl/PACKT_OpenCL_Book

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tayboonl/PACKT_OpenCL_Book

# Include any dependencies generated for this target.
include src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/depend.make

# Include the progress variables for this target.
include src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/progress.make

# Include the compile flags for this target's objects.
include src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/flags.make

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/flags.make
src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o: src/Ch2/user_buffer/user_buffer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/tayboonl/PACKT_OpenCL_Book/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/UserBuffer.dir/user_buffer.c.o   -c /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer/user_buffer.c

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UserBuffer.dir/user_buffer.c.i"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer/user_buffer.c > CMakeFiles/UserBuffer.dir/user_buffer.c.i

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UserBuffer.dir/user_buffer.c.s"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer/user_buffer.c -o CMakeFiles/UserBuffer.dir/user_buffer.c.s

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.requires:
.PHONY : src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.requires

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.provides: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.requires
	$(MAKE) -f src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/build.make src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.provides.build
.PHONY : src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.provides

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.provides.build: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o

# Object files for target UserBuffer
UserBuffer_OBJECTS = \
"CMakeFiles/UserBuffer.dir/user_buffer.c.o"

# External object files for target UserBuffer
UserBuffer_EXTERNAL_OBJECTS =

src/Ch2/user_buffer/UserBuffer: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o
src/Ch2/user_buffer/UserBuffer: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/build.make
src/Ch2/user_buffer/UserBuffer: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable UserBuffer"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UserBuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/build: src/Ch2/user_buffer/UserBuffer
.PHONY : src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/build

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/requires: src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/user_buffer.c.o.requires
.PHONY : src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/requires

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/clean:
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer && $(CMAKE_COMMAND) -P CMakeFiles/UserBuffer.dir/cmake_clean.cmake
.PHONY : src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/clean

src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/depend:
	cd /Users/tayboonl/PACKT_OpenCL_Book && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Ch2/user_buffer/CMakeFiles/UserBuffer.dir/depend

