/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:45:19 by sruff             #+#    #+#             */
/*   Updated: 2024/04/10 10:46:17 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_ordered(t_ps_node **node, char **split_arg, int argc)
{
	t_ps_node	*temp;

	temp = *node;
	pre_index(node);
	while (temp && temp->next)
	{
		if (!(temp->index < temp->next->index))
			return (0);
		temp = temp->next;
	}
	if (argc == 2)
	{
		free_split(split_arg);
	}
	return (1);
}

void	mini_sort_three(t_ps_node **a, t_ps_node **b, int len, int len_og)
{
	if (len <= 3)
	{
		if (find_biggest(*a) == *a)
			rotate_a(a);
		else if ((*a)->next->index == find_biggest(*a)->index)
			reverse_rotate_a(a);
		if ((*a)->next->index < (*a)->index)
			swap_a(a);
	}
	if (len_og > 3 && len_og <= 5)
		second_swap(a, b);
}

void	mini_sort(t_ps_node **node, t_ps_node **node2)
{
	int			len;
	int			len_og;

	set_price(node);
	len = lstsize(*node);
	len_og = len;
	if (check_if_ordered(node, NULL, 0))
		return (free_stack(node), free_stack(node2));
	while (len <= 5 && len > 3)
	{
		if ((*node)->index == 0 || (*node)->index == 1)
		{
			if ((*node)->index > (*node)->next->index)
				swap_a(node);
			push_to_b(node, node2);
			len--;
		}
		else
			rotate_a(node);
	}
	mini_sort_three(node, node2, len, len_og);
}

int	find_cheapest(t_ps_node *node)
{
	long			price;
	int				i;
	int				j;

	i = 1;
	j = 1;
	if (NULL == node)
		return (0);
	price = node->price;
	while (node)
	{
		if (node->price < price)
		{
			price = node->price;
			j = i;
		}
		node = node->next;
		i++;
	}
	return (j);
}

t_ps_node	*find_smallest(t_ps_node *node)
{
	long			price;
	t_ps_node		*smallest_node;

	if (NULL == node)
		return (NULL);
	price = node->price;
	while (node)
	{
		if (node->price <= price)
		{
			price = node->price;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}
