# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 20:11:29 by nprimo            #+#    #+#              #
#    Updated: 2021/12/20 19:51:01 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

INC_D = ./inc
INC = ./inc/push_swap.h

LIBFT_D = ./libft/
LIBFT = ./libft/libft.a

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)

.PHONY: all re clean fclean

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft/
	$(MAKE) bonus -C ./libft/

clean:
	$(MAKE) clean -C ./libft/
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all
