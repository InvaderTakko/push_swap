# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sruff <sruff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:34:25 by sruff             #+#    #+#              #
#    Updated: 2024/04/10 11:44:36 by sruff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SHAREDSRC =	free_error.c parse_innit.c push_moves.c rotate.c reverse_rotate.c push.c swap.c utils.c sort_utils.c brain.c
SHAREDOBJ = $(SRC:%.c=%.o)
SRC = $(SHAREDSRC) main.c
OBJ = $(SRC:%.c=%.o)
SRCBON = $(SHAREDSRC) checker.c 
OBJBON = $(SRCBON:%.c=%.o)

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
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
	$(CC) $(CFLAGS) $^ -o checker $(INC) -L libft -lft

ipsv:
	git clone https://github.com/o-reo/push_swap_visualizer
	mkdir push_swap_visualizer/build
	cd push_swap_visualizer/build && cmake .. && make

psv: push_swap_visualizer
	./push_swap_visualizer/build/bin/visualizer

test1:
	git clone git@github.com:julien-ctx/push-swap-tester.git && mv push-swap-tester/tester.py . 
	&& mv push-swap-tester/checker_Mac . && rm -rf push-swap-tester && chmod 777 checker_Mac && make && python3 tester.py
	
test2:
	curl https://raw.githubusercontent.com/hu8813/tester_push_swap/main/pstester.py | python3 -	
	
.PHONY: all clean fclean re bonus ipsv psv test1 test2