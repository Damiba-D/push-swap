# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 16:37:48 by ddamiba           #+#    #+#              #
#    Updated: 2025/06/09 18:24:02 by ddamiba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME = push_swap.a

# Compiler & Tools
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
LIBFT_DIR = libft
GNL_DIR = $(LIBFT_DIR)/get_next_line
PRINTF_DIR = $(LIBFT_DIR)/ft_printf

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/get_next_line.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Sources and Objects
SRC = revrotoperations.c rotateoperations.c swapoperations.c pushoperations.c check_error.c populate_list.c print_list.c push_swap.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h

# Default Rule
all: libs $(NAME)

# Build static library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

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
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re libs
