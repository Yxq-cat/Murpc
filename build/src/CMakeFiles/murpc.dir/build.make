# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tony/projects/murpc_bk/murpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony/projects/murpc_bk/murpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/murpc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/murpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/murpc.dir/flags.make

src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o: src/CMakeFiles/murpc.dir/flags.make
src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o: ../src/loadxmlconfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/projects/murpc_bk/murpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/murpc.dir/loadxmlconfig.cpp.o -c /home/tony/projects/murpc_bk/murpc/src/loadxmlconfig.cpp

src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/murpc.dir/loadxmlconfig.cpp.i"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/projects/murpc_bk/murpc/src/loadxmlconfig.cpp > CMakeFiles/murpc.dir/loadxmlconfig.cpp.i

src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/murpc.dir/loadxmlconfig.cpp.s"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/projects/murpc_bk/murpc/src/loadxmlconfig.cpp -o CMakeFiles/murpc.dir/loadxmlconfig.cpp.s

src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.requires:

.PHONY : src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.requires

src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.provides: src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/murpc.dir/build.make src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.provides.build
.PHONY : src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.provides

src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.provides.build: src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o


src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o: src/CMakeFiles/murpc.dir/flags.make
src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o: ../src/rpc_meta.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/projects/murpc_bk/murpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/murpc.dir/rpc_meta.pb.cc.o -c /home/tony/projects/murpc_bk/murpc/src/rpc_meta.pb.cc

src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/murpc.dir/rpc_meta.pb.cc.i"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/projects/murpc_bk/murpc/src/rpc_meta.pb.cc > CMakeFiles/murpc.dir/rpc_meta.pb.cc.i

src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/murpc.dir/rpc_meta.pb.cc.s"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/projects/murpc_bk/murpc/src/rpc_meta.pb.cc -o CMakeFiles/murpc.dir/rpc_meta.pb.cc.s

src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.requires:

.PHONY : src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.requires

src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.provides: src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.requires
	$(MAKE) -f src/CMakeFiles/murpc.dir/build.make src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.provides.build
.PHONY : src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.provides

src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.provides.build: src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o


src/CMakeFiles/murpc.dir/rpcclient.cpp.o: src/CMakeFiles/murpc.dir/flags.make
src/CMakeFiles/murpc.dir/rpcclient.cpp.o: ../src/rpcclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/projects/murpc_bk/murpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/murpc.dir/rpcclient.cpp.o"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/murpc.dir/rpcclient.cpp.o -c /home/tony/projects/murpc_bk/murpc/src/rpcclient.cpp

src/CMakeFiles/murpc.dir/rpcclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/murpc.dir/rpcclient.cpp.i"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/projects/murpc_bk/murpc/src/rpcclient.cpp > CMakeFiles/murpc.dir/rpcclient.cpp.i

src/CMakeFiles/murpc.dir/rpcclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/murpc.dir/rpcclient.cpp.s"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/projects/murpc_bk/murpc/src/rpcclient.cpp -o CMakeFiles/murpc.dir/rpcclient.cpp.s

src/CMakeFiles/murpc.dir/rpcclient.cpp.o.requires:

.PHONY : src/CMakeFiles/murpc.dir/rpcclient.cpp.o.requires

src/CMakeFiles/murpc.dir/rpcclient.cpp.o.provides: src/CMakeFiles/murpc.dir/rpcclient.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/murpc.dir/build.make src/CMakeFiles/murpc.dir/rpcclient.cpp.o.provides.build
.PHONY : src/CMakeFiles/murpc.dir/rpcclient.cpp.o.provides

src/CMakeFiles/murpc.dir/rpcclient.cpp.o.provides.build: src/CMakeFiles/murpc.dir/rpcclient.cpp.o


src/CMakeFiles/murpc.dir/rpcserver.cpp.o: src/CMakeFiles/murpc.dir/flags.make
src/CMakeFiles/murpc.dir/rpcserver.cpp.o: ../src/rpcserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/projects/murpc_bk/murpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/murpc.dir/rpcserver.cpp.o"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/murpc.dir/rpcserver.cpp.o -c /home/tony/projects/murpc_bk/murpc/src/rpcserver.cpp

src/CMakeFiles/murpc.dir/rpcserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/murpc.dir/rpcserver.cpp.i"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/projects/murpc_bk/murpc/src/rpcserver.cpp > CMakeFiles/murpc.dir/rpcserver.cpp.i

src/CMakeFiles/murpc.dir/rpcserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/murpc.dir/rpcserver.cpp.s"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/projects/murpc_bk/murpc/src/rpcserver.cpp -o CMakeFiles/murpc.dir/rpcserver.cpp.s

src/CMakeFiles/murpc.dir/rpcserver.cpp.o.requires:

.PHONY : src/CMakeFiles/murpc.dir/rpcserver.cpp.o.requires

src/CMakeFiles/murpc.dir/rpcserver.cpp.o.provides: src/CMakeFiles/murpc.dir/rpcserver.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/murpc.dir/build.make src/CMakeFiles/murpc.dir/rpcserver.cpp.o.provides.build
.PHONY : src/CMakeFiles/murpc.dir/rpcserver.cpp.o.provides

src/CMakeFiles/murpc.dir/rpcserver.cpp.o.provides.build: src/CMakeFiles/murpc.dir/rpcserver.cpp.o


src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o: src/CMakeFiles/murpc.dir/flags.make
src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o: ../src/zookeeperutils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/projects/murpc_bk/murpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/murpc.dir/zookeeperutils.cpp.o -c /home/tony/projects/murpc_bk/murpc/src/zookeeperutils.cpp

src/CMakeFiles/murpc.dir/zookeeperutils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/murpc.dir/zookeeperutils.cpp.i"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/projects/murpc_bk/murpc/src/zookeeperutils.cpp > CMakeFiles/murpc.dir/zookeeperutils.cpp.i

src/CMakeFiles/murpc.dir/zookeeperutils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/murpc.dir/zookeeperutils.cpp.s"
	cd /home/tony/projects/murpc_bk/murpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/projects/murpc_bk/murpc/src/zookeeperutils.cpp -o CMakeFiles/murpc.dir/zookeeperutils.cpp.s

src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.requires:

.PHONY : src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.requires

src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.provides: src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/murpc.dir/build.make src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.provides.build
.PHONY : src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.provides

src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.provides.build: src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o


# Object files for target murpc
murpc_OBJECTS = \
"CMakeFiles/murpc.dir/loadxmlconfig.cpp.o" \
"CMakeFiles/murpc.dir/rpc_meta.pb.cc.o" \
"CMakeFiles/murpc.dir/rpcclient.cpp.o" \
"CMakeFiles/murpc.dir/rpcserver.cpp.o" \
"CMakeFiles/murpc.dir/zookeeperutils.cpp.o"

# External object files for target murpc
murpc_EXTERNAL_OBJECTS =

../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o
../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o
../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/rpcclient.cpp.o
../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/rpcserver.cpp.o
../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o
../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/build.make
../lib/murpc/libmurpc.a: src/CMakeFiles/murpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tony/projects/murpc_bk/murpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library ../../lib/murpc/libmurpc.a"
	cd /home/tony/projects/murpc_bk/murpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/murpc.dir/cmake_clean_target.cmake
	cd /home/tony/projects/murpc_bk/murpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/murpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/murpc.dir/build: ../lib/murpc/libmurpc.a

.PHONY : src/CMakeFiles/murpc.dir/build

src/CMakeFiles/murpc.dir/requires: src/CMakeFiles/murpc.dir/loadxmlconfig.cpp.o.requires
src/CMakeFiles/murpc.dir/requires: src/CMakeFiles/murpc.dir/rpc_meta.pb.cc.o.requires
src/CMakeFiles/murpc.dir/requires: src/CMakeFiles/murpc.dir/rpcclient.cpp.o.requires
src/CMakeFiles/murpc.dir/requires: src/CMakeFiles/murpc.dir/rpcserver.cpp.o.requires
src/CMakeFiles/murpc.dir/requires: src/CMakeFiles/murpc.dir/zookeeperutils.cpp.o.requires

.PHONY : src/CMakeFiles/murpc.dir/requires

src/CMakeFiles/murpc.dir/clean:
	cd /home/tony/projects/murpc_bk/murpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/murpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/murpc.dir/clean

src/CMakeFiles/murpc.dir/depend:
	cd /home/tony/projects/murpc_bk/murpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony/projects/murpc_bk/murpc /home/tony/projects/murpc_bk/murpc/src /home/tony/projects/murpc_bk/murpc/build /home/tony/projects/murpc_bk/murpc/build/src /home/tony/projects/murpc_bk/murpc/build/src/CMakeFiles/murpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/murpc.dir/depend
