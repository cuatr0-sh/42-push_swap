# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 00:45:08 by asoria            #+#    #+#              #
#    Updated: 2025/07/24 21:18:45 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -Ilibft #-O3 -march=native

SRC_DIR		:= src/push_swap
SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	:= $(SRC_FILES:.c=.o)

# Libraries
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

PRINTF_DIR	:= $(LIBFT_DIR)/ft_printf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a

# Targets
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
