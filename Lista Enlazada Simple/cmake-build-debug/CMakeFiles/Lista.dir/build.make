# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lista.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lista.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lista.dir/flags.make

CMakeFiles/Lista.dir/main.cpp.obj: CMakeFiles/Lista.dir/flags.make
CMakeFiles/Lista.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lista.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lista.dir\main.cpp.obj -c C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\main.cpp

CMakeFiles/Lista.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\main.cpp > CMakeFiles\Lista.dir\main.cpp.i

CMakeFiles/Lista.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\main.cpp -o CMakeFiles\Lista.dir\main.cpp.s

CMakeFiles/Lista.dir/GestionLista.cpp.obj: CMakeFiles/Lista.dir/flags.make
CMakeFiles/Lista.dir/GestionLista.cpp.obj: ../GestionLista.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lista.dir/GestionLista.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lista.dir\GestionLista.cpp.obj -c C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\GestionLista.cpp

CMakeFiles/Lista.dir/GestionLista.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista.dir/GestionLista.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\GestionLista.cpp > CMakeFiles\Lista.dir\GestionLista.cpp.i

CMakeFiles/Lista.dir/GestionLista.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista.dir/GestionLista.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\GestionLista.cpp -o CMakeFiles\Lista.dir\GestionLista.cpp.s

# Object files for target Lista
Lista_OBJECTS = \
"CMakeFiles/Lista.dir/main.cpp.obj" \
"CMakeFiles/Lista.dir/GestionLista.cpp.obj"

# External object files for target Lista
Lista_EXTERNAL_OBJECTS =

Lista.exe: CMakeFiles/Lista.dir/main.cpp.obj
Lista.exe: CMakeFiles/Lista.dir/GestionLista.cpp.obj
Lista.exe: CMakeFiles/Lista.dir/build.make
Lista.exe: CMakeFiles/Lista.dir/linklibs.rsp
Lista.exe: CMakeFiles/Lista.dir/objects1.rsp
Lista.exe: CMakeFiles/Lista.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lista.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lista.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lista.dir/build: Lista.exe

.PHONY : CMakeFiles/Lista.dir/build

CMakeFiles/Lista.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lista.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lista.dir/clean

CMakeFiles/Lista.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug C:\Users\marti\Documents\Proyectos\ListaEnlazadaSimple\cmake-build-debug\CMakeFiles\Lista.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lista.dir/depend
