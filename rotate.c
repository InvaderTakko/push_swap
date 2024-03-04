/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:13:39 by sruff             #+#    #+#             */
/*   Updated: 2024/03/01 10:13:10 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_ps_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
void rotate_b(t_ps_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rotate_both(t_ps_node **a, t_ps_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}