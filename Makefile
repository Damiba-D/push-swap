# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 16:37:48 by ddamiba           #+#    #+#              #
#    Updated: 2025/07/03 20:21:11 by ddamiba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME = push_swap.a
EXEC = push_swap

# Compiler & Tools
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
LIBFT_DIR = libft
GNL_DIR = $(LIBFT_DIR)/get_next_line
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
STACK_DIR = stack_funcs
CALC_DIR = Calculations
MOV_DIR = Movement_funcs
STACK_AUX_DIR = OPs_stack_aux
SORT_AUX_DIR = Sorting_aux

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/get_next_line.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Sources and Objects
SRC = algo.c \
	  parsing.c \
	  push_swap.c \
	  $(CALC_DIR)/cost_funcs.c \
	  $(CALC_DIR)/find_min_max.c \
	  $(CALC_DIR)/find_nodes.c \
	  $(MOV_DIR)/movement_funcs.c \
	  $(STACK_AUX_DIR)/populate_stack.c \
	  $(STACK_AUX_DIR)/print_stack.c \
	  $(STACK_AUX_DIR)/pushoperations.c \
	  $(STACK_AUX_DIR)/revrotoperations.c \
	  $(STACK_AUX_DIR)/rotateoperations.c \
	  $(STACK_AUX_DIR)/swapoperations.c \
	  $(SORT_AUX_DIR)/sorting_aux.c \
	  $(STACK_DIR)/ft_stackadd_back.c \
	  $(STACK_DIR)/ft_stackadd_front.c \
	  $(STACK_DIR)/ft_stackclear.c \
	  $(STACK_DIR)/ft_stackdelone.c \
	  $(STACK_DIR)/ft_stackiter.c \
	  $(STACK_DIR)/ft_stacklast.c \
	  $(STACK_DIR)/ft_stackmap.c \
	  $(STACK_DIR)/ft_stacknew.c \
	  $(STACK_DIR)/ft_stacksize.c

OBJ = $(SRC:.c=.o)
HEADER = push_swap.h

# Default Rule
all: libs $(NAME) $(EXEC)

# Build static library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Build executable
$(EXEC): $(NAME)
	$(CC) -Wall -Wextra -Werror push_swap.c $(NAME) $(LIBFT) $(PRINTF) -o $(EXEC)

# Compile object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft and submodules
libs:
	@$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	$(RM) $(NAME) $(EXEC)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re libs
