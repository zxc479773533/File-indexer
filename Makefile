# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/panyue/code/my_github/File-indexer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/panyue/code/my_github/File-indexer

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/panyue/code/my_github/File-indexer/CMakeFiles /home/panyue/code/my_github/File-indexer/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/panyue/code/my_github/File-indexer/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named make_index

# Build rule for target.
make_index: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 make_index
.PHONY : make_index

# fast build rule for target.
make_index/fast:
	$(MAKE) -f CMakeFiles/make_index.dir/build.make CMakeFiles/make_index.dir/build
.PHONY : make_index/fast

#=============================================================================
# Target rules for targets named indexed_search

# Build rule for target.
indexed_search: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 indexed_search
.PHONY : indexed_search

# fast build rule for target.
indexed_search/fast:
	$(MAKE) -f CMakeFiles/indexed_search.dir/build.make CMakeFiles/indexed_search.dir/build
.PHONY : indexed_search/fast

indexed_search.o: indexed_search.c.o

.PHONY : indexed_search.o

# target to build an object file
indexed_search.c.o:
	$(MAKE) -f CMakeFiles/indexed_search.dir/build.make CMakeFiles/indexed_search.dir/indexed_search.c.o
.PHONY : indexed_search.c.o

indexed_search.i: indexed_search.c.i

.PHONY : indexed_search.i

# target to preprocess a source file
indexed_search.c.i:
	$(MAKE) -f CMakeFiles/indexed_search.dir/build.make CMakeFiles/indexed_search.dir/indexed_search.c.i
.PHONY : indexed_search.c.i

indexed_search.s: indexed_search.c.s

.PHONY : indexed_search.s

# target to generate assembly for a file
indexed_search.c.s:
	$(MAKE) -f CMakeFiles/indexed_search.dir/build.make CMakeFiles/indexed_search.dir/indexed_search.c.s
.PHONY : indexed_search.c.s

make_index.o: make_index.c.o

.PHONY : make_index.o

# target to build an object file
make_index.c.o:
	$(MAKE) -f CMakeFiles/make_index.dir/build.make CMakeFiles/make_index.dir/make_index.c.o
.PHONY : make_index.c.o

make_index.i: make_index.c.i

.PHONY : make_index.i

# target to preprocess a source file
make_index.c.i:
	$(MAKE) -f CMakeFiles/make_index.dir/build.make CMakeFiles/make_index.dir/make_index.c.i
.PHONY : make_index.c.i

make_index.s: make_index.c.s

.PHONY : make_index.s

# target to generate assembly for a file
make_index.c.s:
	$(MAKE) -f CMakeFiles/make_index.dir/build.make CMakeFiles/make_index.dir/make_index.c.s
.PHONY : make_index.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... make_index"
	@echo "... indexed_search"
	@echo "... indexed_search.o"
	@echo "... indexed_search.i"
	@echo "... indexed_search.s"
	@echo "... make_index.o"
	@echo "... make_index.i"
	@echo "... make_index.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
