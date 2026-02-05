# Maths Library

A custom C library structure for mathematical operations, focusing on linear algebra and number theory.

## Project Structure

```
maths_library/
├── include/              # Header files (.h)
│   ├── linear_algebra/   # Linear algebra headers
│   └── number_theory/    # Number theory headers
├── src/                  # Source files (.c)
│   ├── linear_algebra/   # Linear algebra implementations
│   └── number_theory/    # Number theory implementations
├── examples/             # Example programs
├── tests/                # Test files
├── Makefile              # Build configuration
├── .gitignore            # Git ignore rules
└── README.md             # This file
```

## Getting Started

### Prerequisites

**Linux:**
- GCC compiler
- Make utility
- Git

**Windows:**
- MinGW-w64 or MSYS2 (includes GCC and Make)
- Git for Windows

### Clone and Initialize the Repository

#### Linux

```bash
# Clone the repository
git clone https://github.com/Ret2skillz/maths_library.git

# Navigate to the directory
cd maths_library

# Check the structure
ls -la

# Build the library (once you add your .c and .h files)
make
```

#### Windows (with MinGW/MSYS2)

```cmd
REM Clone the repository
git clone https://github.com/Ret2skillz/maths_library.git

REM Navigate to the directory
cd maths_library

REM Check the structure
dir

REM Build the library (once you add your .c and .h files)
make
```

**Note for Windows users:** If you don't have MinGW/MSYS2 installed:
1. Download and install MSYS2 from https://www.msys2.org/
2. Open MSYS2 terminal and run: `pacman -S mingw-w64-x86_64-gcc make git`
3. Add MinGW bin directory to your PATH (e.g., C:\msys64\mingw64\bin)

### Building on Windows without Make (Manual Commands)

If you prefer not to use Make on Windows, you can build manually with these commands:

```cmd
REM Create build directories
mkdir build
mkdir build\linear_algebra
mkdir build\number_theory
mkdir lib

REM Compile your linear algebra sources (example)
gcc -Wall -Wextra -std=c11 -O2 -Iinclude -c src/linear_algebra/your_file.c -o build/linear_algebra/your_file.o

REM Compile your number theory sources (example)
gcc -Wall -Wextra -std=c11 -O2 -Iinclude -c src/number_theory/your_file.c -o build/number_theory/your_file.o

REM Create static library
ar rcs lib/libmaths.a build/linear_algebra/*.o build/number_theory/*.o

REM Link with your program
gcc -Iinclude your_program.c -Llib -lmaths -lm -o your_program.exe
```

## Makefile Targets

The included Makefile provides the following targets:

- `make` or `make all` - Build the static library from all .c files in src/
- `make lib` - Build the static library
- `make clean` - Remove all build artifacts (build/, lib/, bin/)
- `make help` - Display help information

The Makefile automatically detects:
- Operating system (Linux/Windows)
- All .c files in src/linear_algebra/ and src/number_theory/
- Compiles them to .o files in build/
- Creates a static library: lib/libmaths.a

## Development Workflow

1. **Add header files** in `include/linear_algebra/` or `include/number_theory/`
2. **Add implementation files** in `src/linear_algebra/` or `src/number_theory/`
3. **Run `make`** to build the library
4. **Link your programs** with the library using: `-Llib -lmaths -lm`

### Example: Adding a New Module

```bash
# Create header
touch include/linear_algebra/vector.h

# Create implementation
touch src/linear_algebra/vector.c

# Build (Makefile will automatically find and compile it)
make

# Clean build artifacts
make clean
```

## .gitignore

The repository includes a .gitignore file that excludes:
- Build artifacts (*.o, *.a, build/, lib/, bin/)
- VS Code files (.vscode/)
- Visual Studio files (.vs/)
- IDE files (.idea/)
- OS-specific files (.DS_Store, Thumbs.db)
- Temporary files (*.tmp, *.log)

## License

See LICENSE file for details.
