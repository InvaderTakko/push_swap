/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:19:12 by sruff             #+#    #+#             */
/*   Updated: 2024/04/10 11:59:11 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "checker.h"
# include "./libft/libft.h"
// # include "./libft/get_next_line/get_next_line.h"
// # include "libft.h"
// # include "./libft/ft_printf_bonus.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_ps_node
{
	int					value;
	int					price;
	int					index;
	struct s_ps_node	*next;
	struct s_ps_node	*previous;
}	t_ps_node;

// int	main(int argc, char *argv[]);
t_ps_node	*last_node(t_ps_node *header);
void		push(t_ps_node **a_stack, t_ps_node **b_stack);
void		swap(t_ps_node **node);
void		rotate(t_ps_node **node);
void		reverse_rotate(t_ps_node **node);

void		rotate_a(t_ps_node **a);
void		rotate_b(t_ps_node **b);
void		rotate_both(t_ps_node **a, t_ps_node **b);

void		reverse_rotate_a(t_ps_node **a);
void		reverse_rotate_b(t_ps_node **b);
void		reverse_rotate_both(t_ps_node **a, t_ps_node **b);

void		swap_a(t_ps_node **a);
void		swap_b(t_ps_node **b);
void		swap_both(t_ps_node **a, t_ps_node **b);

void		push_to_a(t_ps_node **a, t_ps_node **b);
void		push_to_b(t_ps_node **a, t_ps_node **b);

int			find_cheapest(t_ps_node *node);
t_ps_node	*find_smallest(t_ps_node *node);
t_ps_node	*find_biggest(t_ps_node *node);
int			lstsize(t_ps_node *lst);
int			find_position(t_ps_node **node, int value);
int			set_price(t_ps_node **a);
void		pre_index(t_ps_node **stack);
void		rank_index(t_ps_node **head);

int			check_if_ordered(t_ps_node **node, char **split_arg, int argc);
int			check_doubles(t_ps_node *head, char **split_arg, int argc);
int			parse_input(char **input, int argc);
t_ps_node	*init_stack(char **argv, int argc);

void		first_swap(t_ps_node **a, t_ps_node **b);
void		second_swap(t_ps_node **a, t_ps_node **b);
int			push_cheapest(t_ps_node **a, t_ps_node **b);
void		mini_sort(t_ps_node **node, t_ps_node **node2);
void		mini_sort_three(t_ps_node **a, t_ps_node **b, int len, int len_og);

void		free_stack(t_ps_node **lst);
void		free_split(char **split_arg);

void		print_error_message(void);

#endif