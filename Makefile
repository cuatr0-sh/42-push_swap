#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 23:41:23 by asoria            #+#    #+#              #
#    Updated: 2025/06/24 04:22:28 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := output
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Ilibft
SRCS    := $(wildcard *.c)
OBJS    := $(SRCS:.c=.o)
LIBFT   := libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
