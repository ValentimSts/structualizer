# Project Makefile for data-struct-visualizer

TARGET = structualizer

SRC_DIR = .
PREV_DIR = ..

# Raylib version
RAYLIB_VERSION = 5.0

# Raylib directories
RAYLIB_BASE_DIR = $(PREV_DIR)/raylib
RAYLIB_DIR = $(RAYLIB_BASE_DIR)/raylib-$(RAYLIB_VERSION)
RAYLIB_INCLUDE_DIR = $(RAYLIB_DIR)/include
RAYLIB_LIB_DIR = $(RAYLIB_DIR)/lib


# ---------------------------------
# Structs
# ---------------------------------

# Directories
STRUCTS_DIR = $(SRC_DIR)/structs
HASH_MAP_DIR = $(STRUCTS_DIR)/hash-map
TREE_MAP_DIR = $(STRUCTS_DIR)/tree-map

# Sources
STRUCTS_SRCS = $(STRUCTS_DIR)/data.c \
			   $(HASH_MAP_DIR)/hash_map.c \
			   $(TREE_MAP_DIR)/tree_map.c

# ---------------------------------


# ---------------------------------
# Screens
# ---------------------------------

# Directories
SCREENS_DIR = $(SRC_DIR)/screens

# Sources
SCREENS_SRCS = $(SCREENS_DIR)/screen.c

# ---------------------------------


# ---------------------------------
# Utils
# ---------------------------------

# Directories
UTILS_DIR = $(SRC_DIR)/utils
# Sources
UTILS_SRCS = $(UTILS_DIR)/button.c

# ---------------------------------


CC = gcc
CFLAGS = -O1 -std=c99 -Wno-missing-braces -Wall -Wextra -D_DEFAULT_SOURCE
INCLUDES = -I$(RAYLIB_INCLUDE_DIR)
LIBS = -L$(RAYLIB_LIB_DIR) -lraylib

# Source files
SRCS = $(SRC_DIR)/structualizer.c \
       $(STRUCTS_SRCS) \
	   $(SCREENS_SRCS) \
	   $(UTILS_SRCS)

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $@

run: $(TARGET)
	LD_LIBRARY_PATH=$(RAYLIB_LIB_DIR):$$LD_LIBRARY_PATH ./$(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run
