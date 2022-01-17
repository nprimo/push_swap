# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 20:11:29 by nprimo            #+#    #+#              #
#    Updated: 2022/01/17 15:31:57 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = src
OBJ = obj
COMM = comm
SRCS = $(wildcard $(SRC)/*.c)
COMMS = $(wildcard $(COMM)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
C_OBJS = $(patsubst $(COMM)/%.c, $(OBJ)/%.o, $(COMMS))

INC_D = ./inc
INC = ./inc/push_swap.h

LIBFT_D = ./libft/
LIBFT = ./libft/libft.a

NAME = push_swap

RM = rm -f

$(OBJ)/%.o: $(SRC)/%.c 
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(OBJ)/%.o: $(COMM)/%.c 
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(NAME): $(OBJS) $(C_OBJS) $(LIBFT) $(INC) 
	$(CC) $(CLFAGS) -o $@ $^ -I $(INC_D) $(LIBFT)

$(OBJ):
	mkdir $@

.PHONY: all re clean fclean

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft/
	$(MAKE) bonus -C ./libft/

clean:
	$(MAKE) clean -C ./libft/
	$(RM) $(wildcard $(OBJ)/*.o) 

fclean: clean
	$(RM) $(LIBFT) $(NAME) 

re: fclean all
