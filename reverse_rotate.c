/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:22:36 by sruff             #+#    #+#             */
/*   Updated: 2024/03/01 10:13:08 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_a(t_ps_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void reverse_rotate_b(t_ps_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void reverse_rotate_both(t_ps_node **a, t_ps_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}