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

CMakeFiles/control.dir/src/DocMain.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/DocMain.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/DocMain.cpp.obj: ../src/DocMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/control.dir/src/DocMain.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\DocMain.cpp.obj -c D:\git\waterloop_projects\control\src\DocMain.cpp

CMakeFiles/control.dir/src/DocMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/DocMain.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\DocMain.cpp > CMakeFiles\control.dir\src\DocMain.cpp.i

CMakeFiles/control.dir/src/DocMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/DocMain.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\DocMain.cpp -o CMakeFiles\control.dir\src\DocMain.cpp.s

CMakeFiles/control.dir/src/DocMain.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/DocMain.cpp.obj.requires

CMakeFiles/control.dir/src/DocMain.cpp.obj.provides: CMakeFiles/control.dir/src/DocMain.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/DocMain.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/DocMain.cpp.obj.provides

CMakeFiles/control.dir/src/DocMain.cpp.obj.provides.build: CMakeFiles/control.dir/src/DocMain.cpp.obj


CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj: ../src/Listeners/CommandListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Listeners\CommandListener.cpp.obj -c D:\git\waterloop_projects\control\src\Listeners\CommandListener.cpp

CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Listeners\CommandListener.cpp > CMakeFiles\control.dir\src\Listeners\CommandListener.cpp.i

CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Listeners\CommandListener.cpp -o CMakeFiles\control.dir\src\Listeners\CommandListener.cpp.s

CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.requires

CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.provides: CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.provides

CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.provides.build: CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj


CMakeFiles/control.dir/src/Main/Control.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Main/Control.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Main/Control.cpp.obj: ../src/Main/Control.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/control.dir/src/Main/Control.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Main\Control.cpp.obj -c D:\git\waterloop_projects\control\src\Main\Control.cpp

CMakeFiles/control.dir/src/Main/Control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Main/Control.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Main\Control.cpp > CMakeFiles\control.dir\src\Main\Control.cpp.i

CMakeFiles/control.dir/src/Main/Control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Main/Control.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Main\Control.cpp -o CMakeFiles\control.dir\src\Main\Control.cpp.s

CMakeFiles/control.dir/src/Main/Control.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Main/Control.cpp.obj.requires

CMakeFiles/control.dir/src/Main/Control.cpp.obj.provides: CMakeFiles/control.dir/src/Main/Control.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Main/Control.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Main/Control.cpp.obj.provides

CMakeFiles/control.dir/src/Main/Control.cpp.obj.provides.build: CMakeFiles/control.dir/src/Main/Control.cpp.obj


CMakeFiles/control.dir/src/Main/Controller.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Main/Controller.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Main/Controller.cpp.obj: ../src/Main/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/control.dir/src/Main/Controller.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Main\Controller.cpp.obj -c D:\git\waterloop_projects\control\src\Main\Controller.cpp

CMakeFiles/control.dir/src/Main/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Main/Controller.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Main\Controller.cpp > CMakeFiles\control.dir\src\Main\Controller.cpp.i

CMakeFiles/control.dir/src/Main/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Main/Controller.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Main\Controller.cpp -o CMakeFiles\control.dir\src\Main\Controller.cpp.s

CMakeFiles/control.dir/src/Main/Controller.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Main/Controller.cpp.obj.requires

CMakeFiles/control.dir/src/Main/Controller.cpp.obj.provides: CMakeFiles/control.dir/src/Main/Controller.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Main/Controller.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Main/Controller.cpp.obj.provides

CMakeFiles/control.dir/src/Main/Controller.cpp.obj.provides.build: CMakeFiles/control.dir/src/Main/Controller.cpp.obj


CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj: ../src/Shared/DataHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Shared\DataHandler.cpp.obj -c D:\git\waterloop_projects\control\src\Shared\DataHandler.cpp

CMakeFiles/control.dir/src/Shared/DataHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Shared/DataHandler.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Shared\DataHandler.cpp > CMakeFiles\control.dir\src\Shared\DataHandler.cpp.i

CMakeFiles/control.dir/src/Shared/DataHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Shared/DataHandler.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Shared\DataHandler.cpp -o CMakeFiles\control.dir\src\Shared\DataHandler.cpp.s

CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.requires

CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.provides: CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.provides

CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.provides.build: CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj


CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj: ../src/Subsystems/Lev/BallValve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Subsystems\Lev\BallValve.cpp.obj -c D:\git\waterloop_projects\control\src\Subsystems\Lev\BallValve.cpp

CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Subsystems\Lev\BallValve.cpp > CMakeFiles\control.dir\src\Subsystems\Lev\BallValve.cpp.i

CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Subsystems\Lev\BallValve.cpp -o CMakeFiles\control.dir\src\Subsystems\Lev\BallValve.cpp.s

CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.requires

CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.provides: CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.provides

CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.provides.build: CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj


CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj: ../src/Subsystems/Lev/lev_draft.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Subsystems\Lev\lev_draft.cpp.obj -c D:\git\waterloop_projects\control\src\Subsystems\Lev\lev_draft.cpp

CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Subsystems\Lev\lev_draft.cpp > CMakeFiles\control.dir\src\Subsystems\Lev\lev_draft.cpp.i

CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Subsystems\Lev\lev_draft.cpp -o CMakeFiles\control.dir\src\Subsystems\Lev\lev_draft.cpp.s

CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.requires

CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.provides: CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.provides

CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.provides.build: CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj


CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj: ../src/Subsystems/LevDPR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Subsystems\LevDPR.cpp.obj -c D:\git\waterloop_projects\control\src\Subsystems\LevDPR.cpp

CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Subsystems\LevDPR.cpp > CMakeFiles\control.dir\src\Subsystems\LevDPR.cpp.i

CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Subsystems\LevDPR.cpp -o CMakeFiles\control.dir\src\Subsystems\LevDPR.cpp.s

CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.requires

CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.provides: CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.provides

CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.provides.build: CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj


CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj: ../src/Timer/TimerPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Timer\TimerPool.cpp.obj -c D:\git\waterloop_projects\control\src\Timer\TimerPool.cpp

CMakeFiles/control.dir/src/Timer/TimerPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Timer/TimerPool.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Timer\TimerPool.cpp > CMakeFiles\control.dir\src\Timer\TimerPool.cpp.i

CMakeFiles/control.dir/src/Timer/TimerPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Timer/TimerPool.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Timer\TimerPool.cpp -o CMakeFiles\control.dir\src\Timer\TimerPool.cpp.s

CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.requires

CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.provides: CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.provides

CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.provides.build: CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj


CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj: CMakeFiles/control.dir/flags.make
CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj: CMakeFiles/control.dir/includes_CXX.rsp
CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj: ../src/Watchdog/Watchdog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\control.dir\src\Watchdog\Watchdog.cpp.obj -c D:\git\waterloop_projects\control\src\Watchdog\Watchdog.cpp

CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.i"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\waterloop_projects\control\src\Watchdog\Watchdog.cpp > CMakeFiles\control.dir\src\Watchdog\Watchdog.cpp.i

CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.s"
	C:\Users\Deep6\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\waterloop_projects\control\src\Watchdog\Watchdog.cpp -o CMakeFiles\control.dir\src\Watchdog\Watchdog.cpp.s

CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.requires:

.PHONY : CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.requires

CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.provides: CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.requires
	$(MAKE) -f CMakeFiles\control.dir\build.make CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.provides.build
.PHONY : CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.provides

CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.provides.build: CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj


# Object files for target control
control_OBJECTS = \
"CMakeFiles/control.dir/src/DocMain.cpp.obj" \
"CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj" \
"CMakeFiles/control.dir/src/Main/Control.cpp.obj" \
"CMakeFiles/control.dir/src/Main/Controller.cpp.obj" \
"CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj" \
"CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj" \
"CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj" \
"CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj" \
"CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj" \
"CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj"

# External object files for target control
control_EXTERNAL_OBJECTS =

control.exe: CMakeFiles/control.dir/src/DocMain.cpp.obj
control.exe: CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj
control.exe: CMakeFiles/control.dir/src/Main/Control.cpp.obj
control.exe: CMakeFiles/control.dir/src/Main/Controller.cpp.obj
control.exe: CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj
control.exe: CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj
control.exe: CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj
control.exe: CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj
control.exe: CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj
control.exe: CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj
control.exe: CMakeFiles/control.dir/build.make
control.exe: CMakeFiles/control.dir/linklibs.rsp
control.exe: CMakeFiles/control.dir/objects1.rsp
control.exe: CMakeFiles/control.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable control.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\control.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/control.dir/build: control.exe

.PHONY : CMakeFiles/control.dir/build

CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/DocMain.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Listeners/CommandListener.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Main/Control.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Main/Controller.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Shared/DataHandler.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Subsystems/Lev/BallValve.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Subsystems/Lev/lev_draft.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Subsystems/LevDPR.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Timer/TimerPool.cpp.obj.requires
CMakeFiles/control.dir/requires: CMakeFiles/control.dir/src/Watchdog/Watchdog.cpp.obj.requires

.PHONY : CMakeFiles/control.dir/requires

CMakeFiles/control.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\control.dir\cmake_clean.cmake
.PHONY : CMakeFiles/control.dir/clean

CMakeFiles/control.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git\waterloop_projects\control D:\git\waterloop_projects\control D:\git\waterloop_projects\control\cmake-build-debug D:\git\waterloop_projects\control\cmake-build-debug D:\git\waterloop_projects\control\cmake-build-debug\CMakeFiles\control.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/control.dir/depend

