# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "D:\applications\jetbrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\applications\jetbrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\git\waterloop_projects\control

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\git\waterloop_projects\control\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/control.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/control.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/control.dir/flags.make

CMakeFiles/control.dir/src/Control.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Control.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Control.cpp.obj: ../src/Control.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/control.dir/src/Control.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Control.cpp.obj -c D:\git\waterloop_projects\control\src\Control.cpp

CMakeFiles/control.dir/src/Control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Control.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Control.cpp > CMakeFiles\control.dir\src\Control.cpp.i

CMakeFiles/control.dir/src/Control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Control.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Control.cpp -o CMakeFiles\control.dir\src\Control.cpp.s

CMakeFiles/control.dir/src/Control.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Control.cpp.obj.requires

CMakeFiles/control.dir/src/Control.cpp.obj.provides: CMakeFiles/control.dir/src/Control.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Control.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Control.cpp.obj.provides

CMakeFiles/control.dir/src/Control.cpp.obj.provides.build: CMakeFiles/control.dir/src/Control.cpp.obj


CMakeFiles/control.dir/src/main.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/main.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/control.dir/src/main.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\main.cpp.obj -c D:\git\waterloop_projects\control\src\main.cpp

CMakeFiles/control.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/main.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\main.cpp > CMakeFiles\control.dir\src\main.cpp.i

CMakeFiles/control.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/main.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\main.cpp -o CMakeFiles\control.dir\src\main.cpp.s

CMakeFiles/control.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/main.cpp.obj.requires

CMakeFiles/control.dir/src/main.cpp.obj.provides: CMakeFiles/control.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/main.cpp.obj.provides

CMakeFiles/control.dir/src/main.cpp.obj.provides.build: CMakeFiles/control.dir/src/main.cpp.obj


# Object files for target control
control_OBJECTS = \
"CMakeFiles/control.dir/src/Control.cpp.obj" \
"CMakeFiles/control.dir/src/main.cpp.obj"

# External object files for target control
control_EXTERNAL_OBJECTS =

control.exe: CMakeFiles/control.dir/src/Control.cpp.obj
control.exe: CMakeFiles/control.dir/src/main.cpp.obj
control.exe: CMakeFiles/control.dir/build.make
control.exe: CMakeFiles/control.dir/linklibs.rsp
control.exe: CMakeFiles/control.dir/objects1.rsp
control.exe: CMakeFiles/control.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable control.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\control.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/control.dir/build: control.exe

.PHONY : CMakeFiles/control.dir/build

CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Control.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/main.cpp.obj.requires

.PHONY : CMakeFiles/control.dir/requires

CMakeFiles/control.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\control.dir\cmake_clean.cmake
.PHONY : CMakeFiles/control.dir/clean

CMakeFiles/control.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git\waterloop_projects\control D:\git\waterloop_projects\control D:\git\waterloop_projects\control\cmake-build-debug D:\git\waterloop_projects\control\cmake-build-debug D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles\control.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/control.dir/depend
