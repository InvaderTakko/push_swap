/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:32:25 by sruff             #+#    #+#             */
/*   Updated: 2024/04/10 11:37:37 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*last_node(t_ps_node *header)
{
	if (header == NULL)
		return (NULL);
	while (header->next)
	{
		header = header->next;
	}
	return (header);
}

void	free_split(char **split_arg)
{
	char	**temp;

	temp = split_arg;
	if (split_arg == NULL)
		return ;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	if (split_arg)
	{
		free(split_arg);
	}
}

void	free_stack(t_ps_node **lst)
{
	t_ps_node	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	print_error_message(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}
