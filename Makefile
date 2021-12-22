# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 20:11:29 by nprimo            #+#    #+#              #
#    Updated: 2021/12/22 14:11:04 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

INC_D = ./inc
INC = ./inc/push_swap.h

LIBFT_D = ./libft/
LIBFT = ./libft/libft.a

NAME = push_swap

RM = rm -f

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)

$(OBJ):
	mkdir $@

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
