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
include src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/depend.make

# Include the progress variables for this target.
include src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/progress.make

# Include the compile flags for this target's objects.
include src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/flags.make

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/flags.make
src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o: src/Ch2/sub_buffers/sub_buffer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/tayboonl/PACKT_OpenCL_Book/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SubBuffer.dir/sub_buffer.c.o   -c /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers/sub_buffer.c

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SubBuffer.dir/sub_buffer.c.i"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers/sub_buffer.c > CMakeFiles/SubBuffer.dir/sub_buffer.c.i

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SubBuffer.dir/sub_buffer.c.s"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers/sub_buffer.c -o CMakeFiles/SubBuffer.dir/sub_buffer.c.s

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.requires:
.PHONY : src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.requires

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.provides: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.requires
	$(MAKE) -f src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/build.make src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.provides.build
.PHONY : src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.provides

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.provides.build: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o

# Object files for target SubBuffer
SubBuffer_OBJECTS = \
"CMakeFiles/SubBuffer.dir/sub_buffer.c.o"

# External object files for target SubBuffer
SubBuffer_EXTERNAL_OBJECTS =

src/Ch2/sub_buffers/SubBuffer: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o
src/Ch2/sub_buffers/SubBuffer: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/build.make
src/Ch2/sub_buffers/SubBuffer: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable SubBuffer"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SubBuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/build: src/Ch2/sub_buffers/SubBuffer
.PHONY : src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/build

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/requires: src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/sub_buffer.c.o.requires
.PHONY : src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/requires

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/clean:
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers && $(CMAKE_COMMAND) -P CMakeFiles/SubBuffer.dir/cmake_clean.cmake
.PHONY : src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/clean

src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/depend:
	cd /Users/tayboonl/PACKT_OpenCL_Book && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers /Users/tayboonl/PACKT_OpenCL_Book/src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Ch2/sub_buffers/CMakeFiles/SubBuffer.dir/depend

