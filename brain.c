/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:07:03 by sruff             #+#    #+#             */
/*   Updated: 2024/03/25 22:36:05 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_ps_node **node, int value)
{
	int	position;

	position = 1;
	while ((*node)->next && value != (*node)->value)
	{
		*node = (*node)->next;
		position++;
	}
	return (position);
}

int	set_price(t_ps_node **a)
{
	int			position;
	t_ps_node	*head;
	int			stack_len;	

	stack_len = lstsize(*a);
	stack_len = stack_len / 2;
	pre_index(a);
	head = *a;
	while (head)
	{
		position = find_position(a, (*a)->value);
		if (position > stack_len)
		{
			head->price = head->index + lstsize(*a);
			head->price -= find_position(&head, head->value) + 1;
		}
		head->price = head->index + position;
		head = head->next;
	}
	return (1);
}

void	first_swap(t_ps_node **stack_a, t_ps_node **stack_b)
{
	int		i;
	float	range_size;
	float	percentage;

	range_size = lstsize(*stack_a);
	i = 0;
	percentage = 0.08;
	range_size = range_size * percentage;
	set_price(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)->index < i)
		{
			push_to_b(stack_a, stack_b);
			rotate_b(stack_b);
			i++;
		}
		else if ((*stack_a)->index < i + range_size)
		{
			push_to_b(stack_a, stack_b);
			i++;
		}
		else
			rotate_a(stack_a);
	}
}

void	second_swap(t_ps_node **a, t_ps_node **b)
{
	set_price(b);
	while ((*b)->next)
	{
		push_cheapest(a, b);
	}
	if ((!(*b)->next))
	{
		push_to_a(a, b);
	}
}

int	push_cheapest(t_ps_node **a, t_ps_node **b)
{
	t_ps_node	*biggest_node;
	int			lst_size;
	int			lst_half;

	set_price(b);
	rank_index(b);
	lst_size = lstsize(*b);
	lst_half = lst_size / 2;
	biggest_node = find_biggest(*b);
	if (!biggest_node)
		return (0);
	while ((*b)->price != biggest_node->price)
	{
		if (biggest_node->index < lst_half)
			rotate_b(b); //top half
		else
			reverse_rotate_b(b); // bottom half
	}
	if ((*b)->price == biggest_node->price)
		return (push_to_a(a, b), 1);
	return (1);
}

//int final_push(t_ps_node **a, t_ps_node **b)
//{
//}//if (*a && i < index_brackets)

//INDEX	POSITION	VALUE	PRICE			
//5			1			54		6			
//1			2			-12	    2			
//6			3			99		9			
//3			3			1		6			
//4			2			33		6			
//2			1			-1		3								
//			swap=swap first second			
//			rotate = push up/down								
//if b_len >= 2						
//	if price first > second		& if price first < second	swap a&b	
//	if price first > last		& if price first < last		rotate ab&b	
//	if price last < first		& if price last > first		reverse rotate a&b
//	if first = lowest price		push			
//	if price first > second		swap			
//	if price first > last		rotate			
//	if price last < first		reverse rotate			

// keep rotating until cheapest at top 
// check after every rotate if statements above apply and do them
// set new price after every step
// ???
// success