# Maths Library Makefile
# Works on Linux and Windows (with MinGW/MSYS2)

# Detect OS
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
    RM := del /Q
    RMDIR := rmdir /S /Q
    MKDIR := mkdir
    EXE_EXT := .exe
    PATH_SEP := \\
else
    DETECTED_OS := $(shell uname -s)
    RM := rm -f
    RMDIR := rm -rf
    MKDIR := mkdir -p
    EXE_EXT :=
    PATH_SEP := /
endif

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -pedantic -O2
INCLUDES := -Iinclude
LDFLAGS := -lm

# Directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN_DIR := bin
LIB_DIR := lib

# Source files
LA_SOURCES := $(wildcard $(SRC_DIR)/linear_algebra/*.c)
NT_SOURCES := $(wildcard $(SRC_DIR)/number_theory/*.c)
ALL_SOURCES := $(LA_SOURCES) $(NT_SOURCES)

# Object files
LA_OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(LA_SOURCES))
NT_OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(NT_SOURCES))
ALL_OBJECTS := $(LA_OBJECTS) $(NT_OBJECTS)

# Library name
LIB_NAME := libmaths
STATIC_LIB := $(LIB_DIR)/$(LIB_NAME).a

# Phony targets
.PHONY: all clean directories lib help

# Default target
all: directories $(STATIC_LIB)

# Help target
help:
	@echo "Maths Library Makefile"
	@echo "======================"
	@echo "Detected OS: $(DETECTED_OS)"
	@echo ""
	@echo "Available targets:"
	@echo "  all        - Build the static library (default)"
	@echo "  lib        - Build the static library"
	@echo "  clean      - Remove all build artifacts"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Usage:"
	@echo "  make              # Build everything"
	@echo "  make clean        # Clean build files"
	@echo "  make lib          # Build library only"

# Create necessary directories
directories:
ifeq ($(DETECTED_OS),Windows)
	@if not exist "$(BUILD_DIR)" $(MKDIR) $(BUILD_DIR)
	@if not exist "$(BUILD_DIR)\linear_algebra" $(MKDIR) "$(BUILD_DIR)\linear_algebra"
	@if not exist "$(BUILD_DIR)\number_theory" $(MKDIR) "$(BUILD_DIR)\number_theory"
	@if not exist "$(LIB_DIR)" $(MKDIR) $(LIB_DIR)
	@if not exist "$(BIN_DIR)" $(MKDIR) $(BIN_DIR)
else
	@$(MKDIR) $(BUILD_DIR)/linear_algebra
	@$(MKDIR) $(BUILD_DIR)/number_theory
	@$(MKDIR) $(LIB_DIR)
	@$(MKDIR) $(BIN_DIR)
endif

# Build static library
$(STATIC_LIB): $(ALL_OBJECTS)
	@echo Creating static library: $@
	ar rcs $@ $^

# Compile linear algebra sources
$(BUILD_DIR)/linear_algebra/%.o: $(SRC_DIR)/linear_algebra/%.c
	@echo Compiling: $<
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile number theory sources
$(BUILD_DIR)/number_theory/%.o: $(SRC_DIR)/number_theory/%.c
	@echo Compiling: $<
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Library target alias
lib: $(STATIC_LIB)

# Clean build artifacts
clean:
ifeq ($(DETECTED_OS),Windows)
	@if exist "$(BUILD_DIR)" $(RMDIR) "$(BUILD_DIR)" 2>nul
	@if exist "$(LIB_DIR)" $(RMDIR) "$(LIB_DIR)" 2>nul
	@if exist "$(BIN_DIR)" $(RMDIR) "$(BIN_DIR)" 2>nul
else
	$(RMDIR) $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR)
endif
	@echo Cleaned all build artifacts
