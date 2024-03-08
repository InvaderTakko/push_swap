/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:07:03 by sruff             #+#    #+#             */
/*   Updated: 2024/03/08 16:36:21 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_position(t_ps_node **node, int value)
{
	int position;
	//int stack_len;

	position = 1;

	while((*node)->next && value != (*node)->value)
	{
		*node = (*node)->next;
		position++;
	}

	//*node->position = position;

	return (position);
}


int	set_price(t_ps_node **a)
{
	//int	price;
	int position;
	t_ps_node	*head;
	int stack_len;	

	stack_len = lstsize(*a);
	stack_len = stack_len / 2;

	pre_index(a);
	head = *a;
	while(head)
	{
		//price = *a->index - position;
		//price = pos - *a->index;
		//pos + index = price lower half +1;
		//pre_index(a);
		position = find_position(a, (*a)->value);
		if (position > stack_len)
				head->price = head->index + (lstsize(*a) - find_position(&head, head->value) + 1);
		head->price = head->index + position;
		head = head->next;
	}
	return 1;
}
//void first_swap(t_ps_node **a, t_ps_node **b)
//{
//	int	list_size;
//	int index_brackets;
//	int i;
//	int	range;
//	float percentage;
//	t_ps_node	*temp;

//	i = 1;
//	percentage = 0.05;
//	pre_index(a);
//	//pre_index(b);
//	set_price(a);
//	//set_price(b);
//	temp = *a;
//	list_size = lstsize(*a);

//	range = list_size * percentage;

//	//index_brackets = list_size / 6;
//	//if (list_size % 6 != 0)
//	//	index_brackets++;
//	//while(lstsize(*a) > 1)
//	while(*a)
//	{
//		if((*a)->index  < range)
//		{
//			push_to_b(a, b);
//			i++;
//		}	
//		else if (i > index_brackets)
//		{
//			//if (list_size % 6 != 0)
//			//	index_brackets++;
//			index_brackets += index_brackets;
//		}
//		else if (*a) 
//			rotate_a(a);
//	}
//	//push_to_b(a, b);
//	//push_to_b(a, b);
//}

//int static	ft_sqrt(int nb)
//{
//	int	sqr_root;

//	if (nb < 0)
//		return (0);
//	sqr_root = 0;
//	while (sqr_root * sqr_root <= nb)
//	{
//		if (sqr_root * sqr_root <= nb && (sqr_root + 1) * (sqr_root + 1) >= nb)
//			return (sqr_root);
//		sqr_root++;
//	}
//	return (0);
//}

void	first_swap(t_ps_node **stack_a, t_ps_node **stack_b)
{
	int	i;
	int	range;
	int	lst_size;
	float percentage;

	lst_size = lstsize(*stack_a);
	i = 0;
	percentage = 0.07;
	range = lst_size * percentage;
	//range = ft_sqrt(lst_size) * 1.6;
	//printf("the range is %d", range);
	pre_index(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index < i)
		{
			push_to_b(stack_a, stack_b);
			rotate_b(stack_b);
			i++;
		}
		else if ((*stack_a)->index < i + range)
		{
			push_to_b(stack_a, stack_b);
			i++;
		}
		else
		{
			rotate_a(stack_a);
		}
	}
}

// 100 : 6
// 

void second_swap(t_ps_node **a, t_ps_node **b)
{
	//t_ps_node *second_a;
	//t_ps_node *second_b;
	//t_ps_node *temp_a;
	//t_ps_node *temp_b;

	//second_a = *a;
	//second_b = *b;
	//temp_a = *a;
	//temp_b = *b;	

	//second_a = second_a->next;
	//pre_index(b);
	set_price(b);
	while((*b)->next)
	{
		//rank_index(a);
		//pre_index(b);
		//set_price(a);
		//set_price(b);		
		push_cheapest(a, b);
		//if(lstsize(*a) >= 2)
		//{
		//	ft_pre_index(a);
		//	set_price(a);
		//	set_price(b);
		//	if ((*a)->price > second_a->price && (*a)->price > second_a->price && (*a)->next && (*b)->next)
		//	{
		//		swap_both(a, b);
		//		temp_a = last_node(*a);
		//		temp_b = last_node(*b);
		//	}
		//	temp_a = last_node(*a);
		//	temp_b = last_node(*b);
		//	if ((*a)->price > temp_a->price && (*b)->price < temp_b->price && (*a)->next && (*b)->next)
		//		rotate_both(a, b);
		//	//if((*a)->price > temp_a->price && (*b)->price < temp_b->price)	

		//}
		//temp = temp->next;
	}
	if ((!(*b)->next))
	{
		push_to_a(a, b);
	}
}


int push_cheapest(t_ps_node **a, t_ps_node **b)
{
	t_ps_node *biggest_node;
	int			lst_size;
	int			lst_half;
	//set_price(a);
	//set_price(b);
	set_price(b);
	rank_index(b);
	lst_size = lstsize(*b);
	lst_half = lst_size / 2;
	biggest_node = find_biggest(*b);
	if(!biggest_node)
		return (0);
	while((*b)->price != biggest_node->price)
	{
		//rank_index(a);
		//pre_index(b);
		////set_price(a);
		//set_price(b);
		//rank_index(b);
		if (biggest_node->index < lst_half)
			rotate_b(b); //top half
		else
			reverse_rotate_b(b); // bottom half
		//biggest_node = find_biggest(*a);	
	}
	//set_price(a);
	//set_price(b);
	if((*b)->price == biggest_node->price)
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
//	if price first > second		& if price first < second		swap a&b	
//	if price first > last		& if price first < last		    rotate ab&b	
//	if price last < first		& if price last > first		    reverse rotate a&b	
						
//	if first = lowest price		push			
//	if price first > second		swap			
//	if price first > last		rotate			
//	if price last < first		reverse rotate			


// keep rotating until cheapest at top 
// check after every rotate if statements above apply and do them
// set new price after every step
// ???
// success