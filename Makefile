# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sruff <sruff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:34:25 by sruff             #+#    #+#              #
#    Updated: 2024/04/05 18:31:17 by sruff            ###   ########.fr        #
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

.PHONY: all clean fclean re

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

push_swap_visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer
	mkdir push_swap_visualizer/build
	cd push_swap_visualizer/build && cmake .. && make

visu: push_swap_visualizer
	./push_swap_visualizer/build/bin/visualizer

# # Compiler Variables
# CC		= cc
# CFLAGSS	= -Wall -Wextra -Werror -g
# #CFLAGSS	= 
# INCFLAG	=  -I include -I libft
# # File Variables
# NAME	= push_swap
# SRC		= main.c push_moves.c rotate.c reverse_rotate.c push.c swap.c utils.c brain.c
# # BON		= parse_arguments.c parse_arguments_reduce.c stack.c stack_2.c \
# # 			main_bonus.c commands.c bonus.c
# BON		= checker.c
# OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))
# BONOBJ	= $(addprefix _bin/,$(notdir $(BON:.c=.o)))

# $(NAME): $(OBJ) | libft/libft.a
# 	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

# libft/libft.a :
# 	-(cd libft && make && make clean)
# 	-(cd get_next_line && make && make clean)
# 	-(cd printf && make && make clean)

# _bin :
# 	mkdir _bin

# _bin/%.o : %.c libft/libft.a | _bin
# 	$(CC) -c $(CFLAGSS) -MMD -MP $(INCFLAG) $< -o $@

# clean:
# 	@rm -rf _bin

# fclean:	clean
# 	@rm -f $(NAME)

# re:		fclean all

# all:	$(NAME)

# checker:	$(BONOBJ)
# 	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

# bonus:	checker

# norm:
# 	norminette $(SRC)

# .PHONY: clean fclean re all bonus

# -include $(OBJ:.o=.d)
#NAME	= push_swap.out
#CC = cc
#CFLAGS 	= -Wall -Werror -Wextra
#ARFLAGS = -rcs
#CFILES 	= main.c
		 
#BONUS 	= 

#LIBFT 	= libft/libft.a

#OBJS 	= $(CFILES:.c)
##OBJS 	= $(CFILES:.c=.o)
##BONOBJS  = $(BONUS:.c=.o)

#all: $(NAME)

#$(NAME): $(OBJS) 
#		make -C ./libft
#		ar $(ARFLAGS) $(NAME) $(OBJS) $(LIBFT)


#bonus: $(BONOBJS)
#		ar $(ARFLAGS) $(NAME) $(BONOBJS)

#clean:
#		make clean -C ./libft
#		rm -rf $(OBJS)
#		rm -rf $(BONOBJS)

#test:
#		make -C ./libft
#		$(CC)  $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
#		ar rcs $(NAME) *.o

#fclean: clean
#		make fclean -C ./libft
#		rm -f $(NAME) 

#re:	fclean all

#.PHONY: all bonus clean fclean re
