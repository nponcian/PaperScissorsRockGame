# This is a manually written Makefile. If possible, consider using CMake instead which is also
# available in this project. CMake would be easier to maintain as the project grows larger.

# Variables
BUILD_DIR = ./build_manual
BIN_DIR = ./bin_manual
SRC_DIR = ./src

CPP =  \
 $(wildcard src/*.cpp) \
 $(wildcard src/Common/*.cpp) \
 $(wildcard src/Game/*.cpp) \
 $(wildcard src/Game/Level/*.cpp) \
 $(wildcard src/Game/Output/*.cpp) \
 $(wildcard src/Game/Random/*.cpp) \
 $(wildcard src/Game/Symbols/*.cpp) \
 $(wildcard src/Help/*.cpp)
OBJ = $(CPP:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)
TARGET = a.out

CC = g++
CFLAGS = -I$(SRC_DIR) -g -Wall -Wextra -Werror -pedantic -std=c++17

# Artificial targets
.PHONY : all clean

# Primary rule
all : $(BIN_DIR)/$(TARGET)

# Setup target executable
$(BIN_DIR)/$(TARGET) : $(OBJ)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

# Setup object files
$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Clean rule
clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# include
-include $(DEP)
