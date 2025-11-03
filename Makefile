# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 00:45:08 by asoria            #+#    #+#              #
#    Updated: 2025/11/03 20:16:15 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -Ilibft -g3 # -O3 -march=native -flto -pipe

SRC_DIR		:= src
SRC_FILES	:= chunk_sort.c \
		ft_algorithm.c \
		ft_parse_args.c \
		push.c \
		push_swap.c \
		radix_sort.c \
		reverse_rotate.c \
		rotate.c \
		sort_five.c \
		stack.c \
		swap.c \
		utils.c

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES	:= $(SRCS:.c=.o)

LIBFT_DIR	:= includes/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "\033[32m[✔] Built $(NAME)\033[0m"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	$()

re: fclean all

.PHONY: all clean fclean re
