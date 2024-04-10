/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:49 by sruff             #+#    #+#             */
/*   Updated: 2024/04/10 10:34:07 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps_node	*a;
	t_ps_node	*b;
	char		**split_arg ;

	split_arg = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		split_arg = ft_split(argv[1], ' ');
	else if (argc > 2)
		split_arg = &argv[1];
	if (!(parse_input(split_arg, argc)))
		return (print_error_message(), 1);
	a = init_stack(split_arg, argc);
	if (!a || check_doubles(a, split_arg, argc))
		return (free_stack(&a), print_error_message(), 1);
	mini_sort(&a, &b);
	if (check_if_ordered(&a, split_arg, argc))
		return (free_stack(&a), free_stack(&b), 0);
	first_swap(&a, &b);
	second_swap(&a, &b);
	if (argc == 2)
		free_split(split_arg);
	return (free_stack(&a), 0);
}
