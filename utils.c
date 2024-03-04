/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:15:55 by sruff             #+#    #+#             */
/*   Updated: 2024/03/01 15:53:29 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest(t_ps_node *node)
{
	long			price;
	int				i;
	int				j;
	t_ps_node	*smallest_node;

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
			smallest_node = node;
			j = i;
		}
		node = node->next;
		i++;
	}
	return (j);
}

t_ps_node *find_smallest(t_ps_node *node)
{
	long			price;
	t_ps_node	*smallest_node;

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
		//if(!node->next)	
		//	//return (smallest_node);
	}
	return (smallest_node);
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

void rank_index(t_ps_node **head)
{
	t_ps_node *temp;
	int i;

	i = 1;
	temp = *head;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}