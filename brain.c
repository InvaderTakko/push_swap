/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:07:03 by sruff             #+#    #+#             */
/*   Updated: 2024/03/04 17:41:18 by sruff            ###   ########.fr       */
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


	head = *a;
	while(head)
	{
		//price = *a->index - position;
		//price = pos - *a->index;
		//pos + index = price lower half +1;
		ft_pre_index(a);
		position = find_position(a, (*a)->value);
		if (position > stack_len)
				head->price = head->index + (lstsize(*a) - find_position(&head, head->value) + 1);
		head->price = head->index + position;
		head = head->next;
	}
	return 1;
}

void first_swap(t_ps_node **a, t_ps_node **b)
{
	t_ps_node *second_a;
	t_ps_node *second_b;
	t_ps_node *temp_a;
	t_ps_node *temp_b;

	second_a = *a;
	second_b = *b;
	temp_a = *a;
	temp_b = *b;	

	second_a = second_a->next;
	while((*a)->next)
	{
		if(lstsize(*a) >= 2)
		{
			rank_index(a);
			rank_index(b);
			set_price(a);
			set_price(b);
			if ((*a)->price > second_a->price && (*a)->price > second_a->price && (*a)->next && (*b)->next)
			{
				swap_both(a, b);
				//temp_a = last_node(*a);
				//temp_b = last_node(*b);
				printf("reached 1st if");
			}
			rank_index(a);
			rank_index(b);
			set_price(a);
			set_price(b);
			temp_a = last_node(*a);
			temp_b = last_node(*b);
			if ((*a)->price > temp_a->price && (*b)->price < temp_b->price && (*a)->next && (*b)->next)
				rotate_both(a, b);
		}
		rank_index(a);
		rank_index(b);
		set_price(a);
		set_price(b);		
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
	if (!((*a)->next))
	{
		push_to_b(a, b);
	}

	
}


int push_cheapest(t_ps_node **a, t_ps_node **b)
{
	t_ps_node *smallest_node;

	set_price(a);
	set_price(b);
	smallest_node = find_smallest(*a);
	if(!smallest_node)
		return (0);
	while((*a)->price != smallest_node->price)
	{
		rank_index(a);
		//set_price(a);
		//set_price(b);
		//smallest_node = find_smallest(*a);
		if (smallest_node->index < lstsize(*a) / 2)
			rotate_a(a); //top half
		else
			reverse_rotate_a(a); // bottom half
		//smallest_node = find_smallest(*a);	
	}
	//set_price(a);
	//set_price(b);
	if((*a)->price == smallest_node->price)
		return (push_to_b(a, b), 1);
	return (1);
}



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