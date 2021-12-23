# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 20:11:29 by nprimo            #+#    #+#              #
#    Updated: 2021/12/23 15:05:13 by nprimo           ###   ########.fr        #
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

$(NAME): $(OBJS) $(LIBFT) $(INC) 
	$(CC) $(CLFAGS) -o $@ $^ -I $(INC_D) $(LIBFT)

test: $(LIBFT)
	$(CC) $(CFLAGS) -g $(SRCS) $(wildcard ./tests/*.c) -I $(INC_D) $(LIBFT) 
	@./a.out

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
