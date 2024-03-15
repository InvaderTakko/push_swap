/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:49 by sruff             #+#    #+#             */
/*   Updated: 2024/03/15 20:04:36 by intra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//t_ps_node static	*find_smallest(t_ps_node *node)
//{
//	long			value;
//	t_ps_node	*smallest_node;

//	if (NULL == node)
//		return (NULL);
//	value = node->value;	
//	while (node)
//	{
//		if (node->value < value)
//		{
//			value = node->value;
//			smallest_node = node;
//		}
//		node = node->next;
//	}
//	return (smallest_node);
//}

t_ps_node *last_node(t_ps_node *header)
{
	if (header == NULL)
		return NULL;
	while (header->next)
	{
		header = header->next;
	}
	return (header);
}

static void init_a(t_ps_node **a, int number)
{
	t_ps_node	*node;
	t_ps_node	*last;

	node = malloc(sizeof(t_ps_node));
	node->next = NULL;
	node->value = number;
	if (*a == NULL)
	{
		*a = node;
		node->previous = NULL;
	}
	else
	{	
		last = last_node(*a);
		last->next = node;
		node->previous = last;
		node->next = NULL;
	}
}

 static	t_ps_node  *init_stack(int argc, char *argv[])
{
	t_ps_node	*a_stack;
	long		number;
	int			i;

	if (argc)
	a_stack = NULL;
	number = 0;
	i = 0;

	number = ft_atoi(argv[i]);
	init_a(&a_stack, number);
	i++;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		init_a(&a_stack, number);
		//printf("%ld\n", number);
		i++;
	}
	return (a_stack);
}

//t_ps_node static *index_nodes(t_ps_node **head, t_ps_node **temp)
//{
//	t_ps_node *counter;

//	//init_a(head, inde)
//	if (*head == NULL) {
//        return;
//    } else {
//        current = *head;
//        while (current->next != NULL) {
//            index = current->next;
//            while (index != NULL) {
//                if (current->data > index->data) {
//                    // Swap the data of current and index nodes
//                    temp = current->data;
//                    current->data = index->data;
//                    index->data = temp;
//                }
//                index = index->next;
//            }
//            current = current->next;
//        }
//    }
//	find_smallest(head);
//}
void	ft_pre_index(t_ps_node **stack)
{
	t_ps_node	*tmp;
	t_ps_node	*tmp2;
	int		index;

	tmp = *stack;
	index = 1;
	while (tmp)
	{
		index = 1;
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
static void free_stack(t_ps_node **lst)
{
	t_ps_node	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}

}

int	main(int argc, char *argv[])
{
	t_ps_node	*a;
	t_ps_node	*b;
	int			i;
	char	**split_arg = NULL;

	i = 0;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	else if (argc == 2)
		split_arg = ft_split(argv[1], ' ');
	else if (argc > 2)
		split_arg = &argv[1];
	a = init_stack(argc, split_arg);
	first_swap(&a, &b);
	second_swap(&a, &b);
	free_stack(&a);
	while (split_arg[i])
		free(split_arg[i++]);
	free(split_arg);	
	return (0);		
}