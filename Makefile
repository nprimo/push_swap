# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 20:11:29 by nprimo            #+#    #+#              #
#    Updated: 2021/12/20 16:55:25 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard src/*.c)
OBJS = $(SRCRS:.c=.o)

INC_D = ./inc
INC = ./inc/push_swap.h

LIBFT_D = ./libft/
LIBFT = ./libft/libft.a

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_D) $(LIBFT) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $?

.PHONY: all re clean fclean

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft/
	$(MAKE) bonus -C ./libft/

clean:
	$(MAKE) clean -C ./libft/

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all
