/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:31:52 by sruff             #+#    #+#             */
/*   Updated: 2024/04/05 21:05:31 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// static	int	parse_and_init(char **split_arg, int argc, t_ps_node **a)
// {
// 	if (!(parse_input(split_arg)))
// 		return (print_error_message(), 1);
// 	*a = init_stack(split_arg, argc);
// 	if (!*a || check_doubles(*a, split_arg, argc))
// 		return (free_stack(a), print_error_message(), 1);
// 	return (0);
// }

static void	compare(t_ps_node **a, t_ps_node **b, char *output_str)
{
	if (!ft_strncmp(output_str, "rra\n", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(output_str, "rrb\n", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(output_str, "rrr\n", 4))
		reverse_rotate(a), reverse_rotate(b);
	if (!ft_strncmp(output_str, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(output_str, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(output_str, "ss\n", 3))
		swap(a), swap(b);
	else if (!ft_strncmp(output_str, "pa\n", 3))
		push(a, b);
	else if (!ft_strncmp(output_str, "pb\n", 3))
		push(b, a);
	else if (!ft_strncmp(output_str, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(output_str, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(output_str, "rr\n", 3))
		rotate(a), rotate(b);
	else
		return (free_stack(a), free_stack(b));
}

static void	reading_loop(t_ps_node **a, t_ps_node **b)
{
	char	*nl;

	nl = NULL;
	// nl = get_next_line(0);
	// if (nl == NULL)
	// 	return ;
	// compare(a, b, nl);
	// free(nl);
	while (1)
	{
		nl = get_next_line(0);
		if (nl == NULL)
			break ;
		compare(a, b, nl);
		free(nl);
	}
}

// int	main(int argc, char **argv)
// {
// 	t_ps_node	*a;
// 	t_ps_node	*b;
// 	char		**split_arg ;

// 	split_arg = NULL;
// 	b = NULL;
// 	if (argc < 2)
// 		return (1);
// 	else if (argc == 2)
// 		split_arg = ft_split(argv[1], ' ');
// 	else if (argc > 2)
// 		split_arg = &argv[1];
// 	if (parse_and_init(split_arg, argc, &a))
// 		return (1);
// 	reading_loop(&a, &b);
// 	if (check_if_ordered(&a, split_arg, argc))
// 		return (ft_printf("OK\n"), free_stack(&a), free_stack(&b), 0);
// 	else
// 		return (ft_printf("KO\n"), free_stack(&a), free_stack(&b), 0);
// }

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
	if (!(parse_input(split_arg)))
		return (print_error_message(), 1);
	a = init_stack(split_arg, argc);
	if (!a || check_doubles(a, split_arg, argc))
		return (free_stack(&a), print_error_message(), 1);
	reading_loop(&a, &b);
	if (!b && check_if_ordered(&a, split_arg, argc))
		return (ft_printf("OK\n"), free_stack(&a), free_stack(&b), 0);
	else
		return (ft_printf("KO\n"), free_stack(&a), free_stack(&b), 0);
	return (free_stack(&a), 0);
}
