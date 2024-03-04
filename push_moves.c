/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:41:18 by sruff             #+#    #+#             */
/*   Updated: 2024/03/01 10:13:04 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void push(t_ps_node **a_stack, t_ps_node **b_stack)
//{
//	t_ps_node	*temp;

//	if (!a_stack || !b_stack !*b_stack)
//	{
//		return;
//	}
//	temp = *b_stack;
//	(*a_stack)->previous = temp;
//	//ft_lstadd_front(a_stack, b_stack);
//	//(*b_stack)->previous = NULL;
//	*b_stack = (*b_stack)->next;
//	(*b_stack)->previous = NULL;
//	temp->next = *a_stack;
//	*a_stack = temp;
//}
void push(t_ps_node **a_stack, t_ps_node **b_stack)
{
	t_ps_node *temp;

    if (!a_stack || !b_stack || !*b_stack)
        return;
	temp = *b_stack;
    *b_stack = (*b_stack)->next;
	(*b_stack)->previous = NULL;

    temp->next = *a_stack;
    temp->previous = NULL;

    if (*a_stack)
    {
        (*a_stack)->previous = temp;
    }
    *a_stack = temp;
}


void swap(t_ps_node **node)
{
	t_ps_node	*second;
	t_ps_node	*third;

	second = (*node)->next;
	third = second->next;

	second->next = *node;
	(*node)->next = third;

	second->previous = NULL;
	(*node)->previous = second;

	if (third != NULL)
		third->previous = *node;

	*node = second;	
		
	
}
void rotate(t_ps_node **node)
{
	t_ps_node	*first;
	t_ps_node	*last;

	first = *node;
	*node = (*node)->next;
	last = last_node(*node);
	last->next = first;
	first->previous = last;
	first->next = NULL;
	(*node)->previous = NULL;

}

void reverse_rotate(t_ps_node **node)
{
	t_ps_node	*first;
	t_ps_node	*last;
	t_ps_node	*new_last;

	first = *node;
	//*node = (*node)->next;
	last = last_node(*node);
	new_last = last->previous;
	new_last->next = NULL;
	last->next = first;
	first->previous = last;
	*node = (*node)->previous;
	(*node)->previous = NULL;
}