/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:49 by sruff             #+#    #+#             */
/*   Updated: 2024/04/08 20:20:48 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// //t_ps_node static	*find_smallest(t_ps_node *node)
// //{
// //	long			value;
// //	t_ps_node	*smallest_node;

// //	if (NULL == node)
// //		return (NULL);
// //	value = node->value;	
// //	while (node)
// //	{
// //		if (node->value < value)
// //		{
// //			value = node->value;
// //			smallest_node = node;
// //		}
// //		node = node->next;
// //	}
// //	return (smallest_node);
// //}

// void	free_split(char **split_arg)
// {
// 	char	**temp;

// 	temp = split_arg;
// 	if (split_arg == NULL)
// 		return ;
// 	while (*temp)
// 	{
// 		free(*temp);
// 		temp++;
// 	}
// 	if (split_arg)
// 	{
// 		free(split_arg);
// 	}
// }

// void	free_stack(t_ps_node **lst)
// {
// 	t_ps_node	*tmp;

// 	while (*lst)
// 	{
// 		tmp = *lst;
// 		*lst = (*lst)->next;
// 		free(tmp);
// 	}
// }

// t_ps_node	*last_node(t_ps_node *header)
// {
// 	if (header == NULL)
// 		return (NULL);
// 	while (header->next)
// 	{
// 		header = header->next;
// 	}
// 	return (header);
// }

//  int	check_doubles(t_ps_node *head, char **split_arg, int argc)
// {
// 	t_ps_node	*temp;
// 	t_ps_node	*temp2;

// 	temp = head;
// 	while (temp)
// 	{
// 		temp2 = head;
// 		while (temp2)
// 		{
// 			if (temp->value == temp2->value && temp != temp2 && argc == 2)
// 				return (free_split(split_arg), 1);
// 			else if (temp->value == temp2->value && temp != temp2)
// 				return (1);
// 			temp2 = temp2->next;
// 		}
// 		temp = temp->next;
// 	}
// 	return (0);
// }

// static void	init_a(t_ps_node **a, int number)
// {
// 	t_ps_node	*node;
// 	t_ps_node	*last;

// 	node = malloc(sizeof(t_ps_node));
// 	if (!node)
// 		return ;
// 	node->value = number;
// 	if (*a == NULL)
// 	{
// 		*a = node;
// 		node->next = NULL;
// 		node->previous = NULL;
// 	}
// 	else
// 	{
// 		last = last_node(*a);
// 		last->next = node;
// 		node->previous = last;
// 		node->next = NULL;
// 	}
// }

// void print_error_message(void)
// {
// 	write(STDERR_FILENO, "Error\n", 6);
// }

// t_ps_node  *init_stack(char **argv, int argc)
// {
// 	t_ps_node	*a_stack;
// 	char		*tem1;
// 	long		number;
// 	int			i;

// 	a_stack = NULL;
// 	number = 0;
// 	i = 0;
// 	while (argv[i])
// 	{
// 		number = ft_atoi(argv[i]);
// 		tem1 = ft_itoa(number);
// 		if (ft_strncmp(tem1, argv[i], 50) && argc == 2)
// 			return (free_split(argv), free(tem1), free_stack(&a_stack), NULL);
// 		else if (ft_strncmp(tem1, argv[i], 50))
// 			return (free(tem1), free_stack(&a_stack), NULL);
// 		init_a(&a_stack, number);
// 		free(tem1);
// 		i++;
// 	}
// 	return (a_stack);
// }

// void	ft_pre_index(t_ps_node **stack)
// {
// 	t_ps_node	*tmp;
// 	t_ps_node	*tmp2;
// 	int			index;

// 	tmp = *stack;
// 	index = 1;
// 	while (tmp)
// 	{
// 		index = 1;
// 		tmp2 = *stack;
// 		while (tmp2)
// 		{
// 			if (tmp->value > tmp2->value)
// 				index++;
// 			tmp2 = tmp2->next;
// 		}
// 		tmp->index = index;
// 		tmp = tmp->next;
// 	}
// }

// int	parse_input(char **input)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (!(input[i] || !(input)))
// 		return (0);
// 	while (input[i])
// 	{
// 		while (input[i][j])
// 		{
// 			if (!(input[i][j] >= '0' && input[i][j] <= '9') && !(j == 0 &&
// 				input[i][j] == '-' && (input[i][j + 1] >= '0' &&
// 				input[i][j + 1] <= '9')))
// 				return (0);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	return (1);
// }


int	main(int argc, char *argv[])
{
	t_ps_node	*a;
	t_ps_node	*b;
	char		**split_arg ;

	split_arg = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		split_arg = ft_split(argv[1], ' ');
	else if (argc > 2)
		split_arg = &argv[1];
	if (!(parse_input(split_arg)))
		return (print_error_message(), 1);
	a = init_stack(split_arg, argc);
	// push_to_b(&a, &b);
	// push_to_b(&a, &b);
	// reverse_rotate_a(&a);
	// while(a)
	// {
	// 	printf("%d\n", a->value);
	// 	a = a->next;
	// }
	// while(b)
	// {
	// 	printf("%d\n", b->value);
	// 	b = b->next;
	// }
	if (!a || check_doubles(a, split_arg, argc))
		return (free_stack(&a), print_error_message(), 1);
	mini_sort(&a, &b);
	if (check_if_ordered(&a, split_arg, argc))
		return (free_stack(&a), free_stack(&b), 0);
	first_swap(&a, &b);
	second_swap(&a, &b);
	if (argc == 2)
		free_split(split_arg);
	return (free_stack(&a), 0);
}
