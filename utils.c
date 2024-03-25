/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:15:55 by sruff             #+#    #+#             */
/*   Updated: 2024/03/25 22:59:10 by sruff            ###   ########.fr       */
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

void	mini_sort(t_ps_node **node, t_ps_node **node2)
{
	t_ps_node	*temp;
	int			len;
	int			len_og;

	temp = *node;
	set_price(node);
	len = lstsize(*node);
	len_og = len;
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
	if (len <= 3)
	{
		if (find_biggest(*node) == *node)
			rotate_a(node);
		else if ((*node)->next->index == find_biggest(*node)->index)
			reverse_rotate_a(node);
		if ((*node)->next->index < (*node)->index)
			swap_a(node);
	}
	if (len_og > 3 && len_og <= 5)
		second_swap(node, node2);
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

t_ps_node	*find_biggest(t_ps_node *node)
{
	long			price;
	t_ps_node		*biggest_node;

	if (NULL == node)
		return (NULL);
	price = node->price;
	while (node)
	{
		if (node->price >= price)
		{
			price = node->price;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}

int	lstsize(t_ps_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	rank_index(t_ps_node **head)
{
	t_ps_node	*temp;
	int			i;

	i = 1;
	temp = *head;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	pre_index(t_ps_node **stack)
{
	t_ps_node	*tmp;
	t_ps_node	*tmp2;
	int			index;

	tmp = *stack;
	index = 0;
	while (tmp)
	{
		index = 0;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				index++;
			tmp2 = tmp2->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}