# Makefile

# Macro
CC = gcc                         # Compiler
CFLAGS = -Wall -Wextra -Werror   # Compile options
NAME = pr02_02                   # Executable file name 
OBJS = pr02_02.o subnum.o        # Object files
SRCS = pr02_02.c subnum.c        # Source files. It could be replaced to SRCS = $(OBJS:.o=.c)

# Basic target
all: $(NAME)

# Targer building rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@     # $@: target, $<: the leftmost dependency, $^: all dependencies

# Each file compiling rule
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@  # %: Any files end with following extension
	                             # For example, if 'hello.c' file exists, this command will run for making 'hello.o' file

# Cleaning rule
clean:
	$(RM) $(OBJS) # Remove object files

fclean: clean
	$(RM) $(NAME) # Remove object files and executable file

# Clean files and re-compile
re: fclean all

# To make sure it is the target
# Eventhough the file named below is existing, the Makefile will recognize it as a target, Not a file
.PHONY: all, clean, fclean, re

