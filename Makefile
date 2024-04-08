# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sruff <sruff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:34:25 by sruff             #+#    #+#              #
#    Updated: 2024/04/08 17:23:19 by sruff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SHAREDSRC =	push_swap.c push_moves.c rotate.c reverse_rotate.c push.c swap.c utils.c brain.c
SHAREDOBJ = $(SRC:%.c=%.o)
SRC = $(SHAREDSRC) main.c
OBJ = $(SRC:%.c=%.o)
SRCBON = $(SHAREDSRC) checker.c 
OBJBON = $(SRCBON:%.c=%.o)

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I . -I libft 
LIB = libft/libft.a



all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $(NAME) $(INC) -L libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJBON)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) checker

re: fclean all

bonus: $(OBJBON)
	make -C libft
	$(CC) $(CFLAGS) $(LIB) $^ -o checker $(INC)

ipsv:
	git clone https://github.com/o-reo/push_swap_visualizer
	mkdir push_swap_visualizer/build
	cd push_swap_visualizer/build && cmake .. && make

psv: push_swap_visualizer
	./push_swap_visualizer/build/bin/visualizer

.PHONY: all clean fclean re bonus ipsv psv