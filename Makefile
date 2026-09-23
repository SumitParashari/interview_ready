# 1. Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# 2. Target Executable Name
TARGET = my_program

# 3. List the directories where your .c files are located
# Add or change these to match your folder structure
SRC_DIRS = linked_list array

# 4. Automatically find all .c files in the specified directories
SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

# 5. Automatically include current directory if you have .c files there too
SRCS += $(wildcard *.c)

# 6. Generate corresponding .o files (kept in the same folder as their .c files)
OBJS = $(SRCS:.c=.o)

# 7. Add Include flags so the compiler can find your header (.h) files
# This tells GCC to look for headers in all of your source directories
INC_FLAGS = $(addprefix -I, $(SRC_DIRS))
CFLAGS += $(INC_FLAGS)

# --- Rules ---

# Default rule
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile individual .c files into .o files (works across subdirectories)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up all generated files across all directories
clean:
	rm -f $(TARGET) $(OBJS)
