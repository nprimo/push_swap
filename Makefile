# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 20:11:29 by nprimo            #+#    #+#              #
#    Updated: 2022/01/19 15:25:12 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

PSH = psh
O_PSH = o_psh
PSHS = $(wildcard $(PSH)/*.c)
O_PSHS = $(patsubst $(PSH)/%.c, $(O_PSH)/%.o, $(PSHS))

CHK = chk
O_CHK = o_chk
CHKS = $(wildcard $(CHK)/*.c)
O_CHKS = $(patsubst $(CHK)/%.c, $(O_CHK)/%.o, $(CHKS))

INC_D = ./inc
INC = ./inc/push_swap.h

LIBFT_D = ./libft/
LIBFT = ./libft/libft.a

NAME = push_swap

RM = rm -rf

$(OBJ)/%.o: $(SRC)/%.c
	@ mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(O_PSH)/%.o: $(PSH)/%.c 
	@ mkdir -p $(O_PSH)
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(O_CHK)/%.o: $(CHK)/%.c 
	@ mkdir -p $(O_CHK)
	$(CC) $(CFLAGS) -I $(INC_D) -L $(LIBFT_D) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(O_PSHS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_D) $(LIBFT)

.PHONY: all checker re clean fclean

all: $(NAME) checker

checker: $(LIBFT) $(OBJS) $(O_CHKS) 
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_D) $(LIBFT)

something:
	@ echo $(PSHS)
	@ echo $(CHKS)

$(LIBFT):
	$(MAKE) -C ./libft/
	$(MAKE) bonus -C ./libft/

clean:
	$(MAKE) clean -C ./libft/
	$(RM) $(wildcard $(OBJ)/*.o) 
	$(RM) $(wildcard $(O_CHK)/*.o)

fclean: clean
	$(RM) $(LIBFT) $(NAME) checker

re: fclean all
