# C_course
Repository with all projects from the C course from Jason Fedin
- Base course: https://www.udemy.com/course/c-programming-for-beginners-/
- Advanced course: https://www.udemy.com/course/advanced-c-programming-course/

> [!NOTE]
> The Tic Tac Toe game has become it's own separate project https://github.com/CodeByAlejandro/C_TicTacToe

> [!IMPORTANT]
> This repository uses `GNU make` as build tool and `GNU gcc` as compiler. It's to be used on a `GNU/Linux` machine. On Windows it's recommended to use `WSL` (version 2).

## Repository setup
The repository contains a list of C projects as well as the following files:
| Directory / File     | Description                                               |
|----------------------|-----------------------------------------------------------|
| `.vscode-workspace/` | Contains Visual Studio Code workspace                     |
| `.templates/`        | Contains template files to automate setup of new projects |
| `Makefile`           | Workspace level Makefile to automate project management   |
| `.gitignore`         | Defines files and directories to be ignored by Git        |
| `README.md`          | This README file                                          |

## Project setup
Each project is setup using 5 directories:
| Directory  | Description                                                          |
|------------|----------------------------------------------------------------------|
| `.vscode/` | Contains Visual Studio Code project configuration (see below)        |
| `src/`     | Contains C/C++ source code                                           |
| `include/` | Contains C/C++ header files                                          |
| `build/`   | Contains build files (compiler output)                               |
| `bin/`     | Contains a symlink to the final executable in the `build/` directory |

## Visual Studio Code Workspace setup
Configuration for development with Visual Studio Code is provided on 2 levels:
- for each project
- for the top level workspace

### Project configuration
Each project comes with a `.vscode` directory that sets it up as a VS Code project. This directory includes C/C++ intellisense configuration, build tasks and a launch configuration.

The C/C++ intellisense configuration is included in the `c_cpp_properties.json` file. It sets `GNU gcc` as the compiler and specifies `C99` as default C standard. Furthermore it directs intellisense to recursively scan the `include/` directory for header files and browse both the `src/` and `include/` directories for source code declarations/definitions.

A launch configuration for running and debugging the program with `GNU gdb` has been added in `launch.json`. It uses the binary symlinked in the `bin/` directory and runs from inside the project root directory. It specifies a `preLaunchTask` to automatically rebuild the project if changes have been made.

The `task.json` file contains the following build tasks:
| Task                                        | Description                                                                                                    |
|---------------------------------------------|----------------------------------------------------------------------------------------------------------------|
| GNU make: Build project (debug mode)        | Builds the project using `GNU make` and appends the debug flags `-g` and `-O0` to the generated `gcc` commands |
| GNU make: Build project (optimization mode) | Builds the project using `GNU make` and appends the optimization flag `-O3` to the generated `gcc` commands    |
| GNU make: Clean project                     | Cleans the project by deleting both the `build/` and `bin/` directories                                        |

### Workspace configuration
There is also a `.vscode-workspace` directory that sets up the Visual Studio Code multi-root workspace. This directory contains the workspace configuration, which is defined in the `C_course.code-workspace` file.
It defines workspace level settings, build tasks and a list of workspace folders (i.e. projects).

This directory also contains a `generate_workspace_projects.sh` script, which when run will automatically regenerate the `C_course.code-workspace` file with an updated list of workspace folders based on the directories in the top level of the repository. This script is also used in the top-level `Makefile` to automatically refresh the workspace after creating or removing projects. See below for more info on `GNU make` setup.

Finally the Visual Studio Code workspace directory also contains symlinks to all non-project directories and other files in the top level. This is useful to allow editing these files from within Visual Studio Code since the workspace is defined within the `.vscode-workspace` directory.

> [!TIP]
> The reason the workspace (represented by the `C_course.code-workspace` file) is not in the top level of the repository (which would automatically show all top-level files) is because this creates duplicate directories for all projects in the Visual Studio Code project explorer pane. This happens because the workspace itself can see all files from the perspective of the directory it itself is defined in (which would contain all projects) as well as all the workspace folders defined as roots in the workspace, as per the configuration in the workspace `C_course.code-workspace` file. Note that it's important that the projects be defined as such workspace roots to for example clearly distinguish between workspace search results for similar named files in different projects. Visual Studio Code's featureset works best with such roots or `workspace folders` as Visual Studio Code calls them.

The following workspace level tasks are defined:
| Task                                                  | Description                                                                                                                                            |
|-------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| GNU make: Build all projects (debug mode)             | Builds all projects using `GNU make` and appends the debug flags `-g` and `-O0` to the generated `gcc` commands                                        |
| GNU make: Build all projects (optimization mode)      | Builds all projects using `GNU make` and appends the optimization flag `-O3` to the generated `gcc` commands                                           |
| GNU make: Clean all projects                          | Cleans all projects by deleting both the `build/` and `bin/` directories for each one of them                                                          |
| GNU make: Update VS Code config files in all projects | Updates the project configuration files in the `.vscode` directory for all projects based on the template `template-vscode` directory in the workspace |
| GNU make: Update Makefile in all projects             | Updates the `Makefile` in all projects based on the template `template-makefile.mk` file in the workspace                                              |
| GNU make: Create new project                          | Creates a new project and adds a new workspace folder to the workspace configuration                                                                   |
| GNU make: Delete existing project                     | Deletes an existing project and removes the workspace folder from the workspace configuration                                                          |

## Building the project wit `GNU make`
The projects are build using `GNU make`. There is a top-level makefile at the level of the workspace, as well as a makefile for each individual project. The Visual Studio Code build tasks mentioned above are all wrappers around make targets.

### Top-level makefile
TODO

### Project makefiles
TODO

## Cross-compilation for Windows
The Makefiles can be re-used for cross-compiling Windows binaries, using a different compilation toolchain with the ability to cross compile (e.g. [mingw-w64](https://www.mingw-w64.org/)).

The following instructions work for `mingw-w64`:

1. Install `mingw-w64` toolchain on GNU/Linux machine:

   ```shell
   sudo apt update && sudo apt install mingw-w64
   ```
2. Run make while overriding variables for compiler and build target:

   ```shell
   make CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++ TARGET_EXEC=Windows.exe
   ```
   > **Note:** Change the name of the target executable to your project's name.

### Verify with `file`-command
To check the output binary format you can use the `file`-command:
```
alejo@c-course:~/C_course/Challenge1$ file ./build/Challenge1
./build/Challenge1: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=2ce76b9678da756c677cf261686a243db410dacd, for GNU/Linux 3.2.0, with debug_info, not stripped
alejo@c-course:~/C_course/Challenge1$ file ./build/Challenge1.exe
./build/Challenge1.exe: PE32+ executable (console) x86-64, for MS Windows, 19 sections
```
