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
include src/Ch1/context_query/CMakeFiles/ContextDetails.dir/depend.make

# Include the progress variables for this target.
include src/Ch1/context_query/CMakeFiles/ContextDetails.dir/progress.make

# Include the compile flags for this target's objects.
include src/Ch1/context_query/CMakeFiles/ContextDetails.dir/flags.make

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/flags.make
src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o: src/Ch1/context_query/context_details.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/tayboonl/PACKT_OpenCL_Book/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ContextDetails.dir/context_details.c.o   -c /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query/context_details.c

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ContextDetails.dir/context_details.c.i"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query/context_details.c > CMakeFiles/ContextDetails.dir/context_details.c.i

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ContextDetails.dir/context_details.c.s"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query/context_details.c -o CMakeFiles/ContextDetails.dir/context_details.c.s

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.requires:
.PHONY : src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.requires

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.provides: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.requires
	$(MAKE) -f src/Ch1/context_query/CMakeFiles/ContextDetails.dir/build.make src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.provides.build
.PHONY : src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.provides

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.provides.build: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o

# Object files for target ContextDetails
ContextDetails_OBJECTS = \
"CMakeFiles/ContextDetails.dir/context_details.c.o"

# External object files for target ContextDetails
ContextDetails_EXTERNAL_OBJECTS =

src/Ch1/context_query/ContextDetails: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o
src/Ch1/context_query/ContextDetails: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/build.make
src/Ch1/context_query/ContextDetails: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ContextDetails"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ContextDetails.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Ch1/context_query/CMakeFiles/ContextDetails.dir/build: src/Ch1/context_query/ContextDetails
.PHONY : src/Ch1/context_query/CMakeFiles/ContextDetails.dir/build

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/requires: src/Ch1/context_query/CMakeFiles/ContextDetails.dir/context_details.c.o.requires
.PHONY : src/Ch1/context_query/CMakeFiles/ContextDetails.dir/requires

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/clean:
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query && $(CMAKE_COMMAND) -P CMakeFiles/ContextDetails.dir/cmake_clean.cmake
.PHONY : src/Ch1/context_query/CMakeFiles/ContextDetails.dir/clean

src/Ch1/context_query/CMakeFiles/ContextDetails.dir/depend:
	cd /Users/tayboonl/PACKT_OpenCL_Book && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/context_query/CMakeFiles/ContextDetails.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Ch1/context_query/CMakeFiles/ContextDetails.dir/depend

