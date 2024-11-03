# Compiler
CC = gcc

# Compiler and linker flags
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lcrypto

# Target executable
TARGET = build/main

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source and object files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/table.c $(SRC_DIR)/persistence.c
OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/table.o $(BUILD_DIR)/persistence.o

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up generated files
clean:
	rm -rf $(BUILD_DIR)
