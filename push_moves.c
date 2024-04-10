/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:41:18 by sruff             #+#    #+#             */
/*   Updated: 2024/04/10 10:37:10 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ps_node **a_stack, t_ps_node **b_stack)
{
	t_ps_node	*temp;

	if (!a_stack || !b_stack)
		return ;
	temp = *b_stack;
	if (*b_stack)
	{
		*b_stack = (*b_stack)->next;
		if (*b_stack)
			(*b_stack)->previous = NULL;
	}
	temp->next = *a_stack;
	if (*a_stack)
		(*a_stack)->previous = temp;
	temp->previous = NULL;
	*a_stack = temp;
}

void	swap(t_ps_node **node)
{
	t_ps_node	*first;
	t_ps_node	*second;
	t_ps_node	*third;

	first = *node;
	second = first->next;
	third = second->next;
	if (!(*node) || !((*node)->next))
		return ;
	if (third)
		third->previous = first;
	second->previous = NULL;
	first->previous = second;
	first->next = third;
	second->next = first;
	*node = second;
}

void	rotate(t_ps_node **node)
{
	t_ps_node	*first;
	t_ps_node	*second;
	t_ps_node	*last;

	if (*node == NULL && (*node)->next == NULL)
	{
		return ;
	}
	first = *node;
	second = (*node)->next;
	last = last_node(*node);
	first->previous = last;
	first->next = NULL;
	second->previous = NULL;
	last->next = first;
	*node = second;
}

void	reverse_rotate(t_ps_node **node)
{
	t_ps_node	*first;
	t_ps_node	*last;
	t_ps_node	*new_last;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	first = *node;
	last = last_node(*node);
	new_last = last->previous;
	new_last->next = NULL;
	last->next = first;
	first->previous = last;
	*node = last;
	(*node)->previous = NULL;
}
