/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:30:12 by sruff             #+#    #+#             */
/*   Updated: 2024/03/01 10:05:03 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_ps_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void swap_b(t_ps_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void swap_both(t_ps_node **a, t_ps_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}