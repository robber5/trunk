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
include src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/depend.make

# Include the progress variables for this target.
include src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/progress.make

# Include the compile flags for this target's objects.
include src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/flags.make

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/flags.make
src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o: src/Ch4/simple_select_filter/select_filter.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/tayboonl/PACKT_OpenCL_Book/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SelectFilter.dir/select_filter.c.o   -c /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter/select_filter.c

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SelectFilter.dir/select_filter.c.i"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter/select_filter.c > CMakeFiles/SelectFilter.dir/select_filter.c.i

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SelectFilter.dir/select_filter.c.s"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter/select_filter.c -o CMakeFiles/SelectFilter.dir/select_filter.c.s

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.requires:
.PHONY : src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.requires

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.provides: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.requires
	$(MAKE) -f src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/build.make src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.provides.build
.PHONY : src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.provides

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.provides.build: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o

# Object files for target SelectFilter
SelectFilter_OBJECTS = \
"CMakeFiles/SelectFilter.dir/select_filter.c.o"

# External object files for target SelectFilter
SelectFilter_EXTERNAL_OBJECTS =

src/Ch4/simple_select_filter/SelectFilter: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o
src/Ch4/simple_select_filter/SelectFilter: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/build.make
src/Ch4/simple_select_filter/SelectFilter: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable SelectFilter"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SelectFilter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/build: src/Ch4/simple_select_filter/SelectFilter
.PHONY : src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/build

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/requires: src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/select_filter.c.o.requires
.PHONY : src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/requires

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/clean:
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter && $(CMAKE_COMMAND) -P CMakeFiles/SelectFilter.dir/cmake_clean.cmake
.PHONY : src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/clean

src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/depend:
	cd /Users/tayboonl/PACKT_OpenCL_Book && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Ch4/simple_select_filter/CMakeFiles/SelectFilter.dir/depend

