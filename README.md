# C_course
Repository with all projects from the C course from Jason Fedin
- Base course: https://www.udemy.com/course/c-programming-for-beginners-/
- Advanced course: https://www.udemy.com/course/advanced-c-programming-course/

> [!NOTE]
> The Tic Tac Toe game has become it's own separate project https://github.com/CodeByAlejandro/C_TicTacToe

> [!IMPORTANT]
> This repository uses GNU make as build tool and GNU gcc as compiler. It's supposed to be used on a GNU/Linux machine. On Windows it's recommended to use WSL (version 2).

## Visual Studio Code Workspace setup
Each project comes with a `.vscode`-directory that sets it up as a VS Code project. This directory includes C intellisense configuration, build tasks ans launch configurations.
There is also a `.vscode-workspace`-directory that sets up the VS Code multi-root workspace.

TODO

## Building the project wit GNU make
The projects are build using GNU make. There is a top-level makefile at the level of the workspace, as well as a makefile for each individual project.

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
