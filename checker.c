/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:31:52 by sruff             #+#    #+#             */
/*   Updated: 2024/04/09 13:46:30 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	compare(t_ps_node **a, t_ps_node **b, char *output_str)
{
	if (!ft_strncmp(output_str, "rra\n", 4))
		return (reverse_rotate(a), 1);
	else if (!ft_strncmp(output_str, "rrb\n", 4))
		return (reverse_rotate(b), 1);
	else if (!ft_strncmp(output_str, "rrr\n", 4))
		return (reverse_rotate(a), reverse_rotate(b), 1);
	else if (!ft_strncmp(output_str, "sa\n", 3))
		return (swap(a), 1);
	else if (!ft_strncmp(output_str, "sb\n", 3))
		return (swap(b), 1);
	else if (!ft_strncmp(output_str, "ss\n", 3))
		return (swap(a), swap(b), 1);
	else if (!ft_strncmp(output_str, "pa\n", 3))
		return (push(a, b), 1);
	else if (!ft_strncmp(output_str, "pb\n", 3))
		return (push(b, a), 1);
	else if (!ft_strncmp(output_str, "ra\n", 3))
		return (rotate(a), 1);
	else if (!ft_strncmp(output_str, "rb\n", 3))
		return (rotate(b), 1);
	else if (!ft_strncmp(output_str, "rr\n", 3))
		return (rotate(a), rotate(b), 1);
	else
		return (0);
}

int	reading_loop(t_ps_node **a, t_ps_node **b, char **split_arg, int argc)
{
	char	*nl;

	nl = NULL;
	while (1)
	{
		nl = get_next_line(0);
		if (nl == NULL)
			break ;
		if (!compare(a, b, nl))
		{
			free(nl);
			print_error_message();
			if (argc == 2)
				free_split(split_arg);
			return (0);
		}
		free(nl);
	}
	if (argc == 2)
		free_split(split_arg);
	return (1);
}


int	main(int argc, char **argv)
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
	if (!reading_loop(&a, &b, split_arg, argc))
		return (free_stack(&a), free_stack(&b), 1);
	if (lstsize(b) == 0 && check_if_ordered(&a, split_arg, argc))
		return (ft_printf("OK\n"), free_stack(&a), free_stack(&b), 0);
	else
		return (ft_printf("KO\n"), free_stack(&a), free_stack(&b), 0);
	return (free_stack(&a), 0);
}
