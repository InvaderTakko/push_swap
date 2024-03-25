/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:49 by sruff             #+#    #+#             */
/*   Updated: 2024/03/25 20:09:34 by sruff            ###   ########.fr       */
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

void free_split_arg(char **split_arg) 
{    
	char **temp;

	temp = split_arg;
    if (split_arg == NULL)
        return;


    while (*temp)
	{
        free(*temp);
        temp++;

    }
    if (*split_arg)
	{
		free(split_arg);
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
// static int check_doubles_2(int *arr)
// {
// 	int	i;
// 	int j;

// 	i = 0;
// 	j = 0;
	
//     // Iterate through the array
// 	// size++;
// 	while(arr[i]) {
//         // Compare each element with all subsequent elements
// 		j = i + 1;
// 		if (!(arr[j]))
//         while (arr[j])
// 		{
				
//             // j = i + 1;
// 			// If a duplicate is found, return true
//             if (arr[i] == arr[j]) {
//                 return 1; // True
//             }
// 			j++;
//         }
// 		i++;	
//     }
//     // If no duplicates found, return false
//     return 0; // False
// }
	
static int check_doubles(t_ps_node *head)
{
	t_ps_node	*temp;

	temp = head;
	while (temp)
	{
		head = temp;
		while (head)
		{
			if (temp->value == head->value && temp != head)
				return 1;
			head = head->next;
		}	
		temp = temp->next;
	}
	return 0;
}


static void init_a(t_ps_node **a, int number)
{
	t_ps_node	*node;
	t_ps_node	*last;

	node = malloc(sizeof(t_ps_node));
	if (!node)
		return;
	node->value = number;
	if (*a == NULL)
	{
		*a = node;
		node->next = NULL;
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

static void print_error_message(void)
{
	write(STDERR_FILENO, "Error\n",6);
}

static	t_ps_node  *init_stack(char **argv, int argc)
{
	t_ps_node	*a_stack;
	char		**temp;
	char		*temp1;
	long		number;
	int			i;

	a_stack = NULL;
	number = 0;
	i = 0;
	temp = argv;
	// if (!&argv[i])
	// 	return (a_stack);
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		temp1 = ft_itoa(number);
		if(ft_strncmp(temp1, argv[i], 50) && argc == 2)
			return (free_split_arg(temp), free(temp1), free_stack(&a_stack), NULL);
		else if (ft_strncmp(temp1, argv[i], 50))
			return (free(temp1), free_stack(&a_stack), NULL);
		init_a(&a_stack, number);
		free(temp1);
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

static int parse_input(char **input)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(input[i] || !(input)))
		return 0;
	while(input[i])
	{
		while(input[i][j])
		{
			if (!(input[i][j] >= '0' && input[i][j] <= '9') && !(j == 0 && input[i][j] == '-' && (input[i][j + 1] >= '0' && input[i][j + 1] <= '9')))
				return 0;
			j++;
		}
		j = 0;
		i++;	
	}
	return 1;
}
int	main(int argc, char *argv[])
{
	t_ps_node	*a;
	t_ps_node	*b;
	char	**split_arg = NULL;

	b = NULL;
	if (argc < 2 )
		return (1);
	else if (argc == 2)
		split_arg = ft_split(argv[1], ' ');
	else if (argc > 2)
		split_arg = &argv[1];
	if (!(parse_input(split_arg)))
		return (print_error_message(),1);
	a = init_stack(split_arg, argc);
	if (!a || check_doubles(a))
		return (free_stack(&a), print_error_message(), 1);
	if (check_if_ordered(&a, split_arg, argc))
		return (free_stack(&a), 0);
	mini_sort(&a, &b);
	if (check_if_ordered(&a, split_arg, argc))
		return (free_stack(&a), 0);
	first_swap(&a, &b);
	second_swap(&a, &b);
	free_stack(&a);
	if (argc == 2)
		free_split_arg(split_arg);
	return (0);		
}

