# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mohammed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mohammed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohammed/Me/Mohammed/projects/goRequest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohammed/Me/Mohammed/projects/goRequest/build

# Include any dependencies generated for this target.
include CMakeFiles/SFMLGoRequest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SFMLGoRequest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SFMLGoRequest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFMLGoRequest.dir/flags.make

CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o: CMakeFiles/SFMLGoRequest.dir/flags.make
CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o: /home/mohammed/Me/Mohammed/projects/goRequest/src/main.cpp
CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o: CMakeFiles/SFMLGoRequest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mohammed/Me/Mohammed/projects/goRequest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o -MF CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o.d -o CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o -c /home/mohammed/Me/Mohammed/projects/goRequest/src/main.cpp

CMakeFiles/SFMLGoRequest.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLGoRequest.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohammed/Me/Mohammed/projects/goRequest/src/main.cpp > CMakeFiles/SFMLGoRequest.dir/src/main.cpp.i

CMakeFiles/SFMLGoRequest.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLGoRequest.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohammed/Me/Mohammed/projects/goRequest/src/main.cpp -o CMakeFiles/SFMLGoRequest.dir/src/main.cpp.s

# Object files for target SFMLGoRequest
SFMLGoRequest_OBJECTS = \
"CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o"

# External object files for target SFMLGoRequest
SFMLGoRequest_EXTERNAL_OBJECTS =

/home/mohammed/Me/Mohammed/projects/goRequest/SFMLGoRequest: CMakeFiles/SFMLGoRequest.dir/src/main.cpp.o
/home/mohammed/Me/Mohammed/projects/goRequest/SFMLGoRequest: CMakeFiles/SFMLGoRequest.dir/build.make
/home/mohammed/Me/Mohammed/projects/goRequest/SFMLGoRequest: lib/jb/libmyjbhelpers.a
/home/mohammed/Me/Mohammed/projects/goRequest/SFMLGoRequest: CMakeFiles/SFMLGoRequest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mohammed/Me/Mohammed/projects/goRequest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/mohammed/Me/Mohammed/projects/goRequest/SFMLGoRequest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SFMLGoRequest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFMLGoRequest.dir/build: /home/mohammed/Me/Mohammed/projects/goRequest/SFMLGoRequest
.PHONY : CMakeFiles/SFMLGoRequest.dir/build

CMakeFiles/SFMLGoRequest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SFMLGoRequest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SFMLGoRequest.dir/clean

CMakeFiles/SFMLGoRequest.dir/depend:
	cd /home/mohammed/Me/Mohammed/projects/goRequest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohammed/Me/Mohammed/projects/goRequest /home/mohammed/Me/Mohammed/projects/goRequest /home/mohammed/Me/Mohammed/projects/goRequest/build /home/mohammed/Me/Mohammed/projects/goRequest/build /home/mohammed/Me/Mohammed/projects/goRequest/build/CMakeFiles/SFMLGoRequest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFMLGoRequest.dir/depend

