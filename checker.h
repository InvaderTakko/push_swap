/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruff <sruff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:51:50 by sruff             #+#    #+#             */
/*   Updated: 2024/04/09 12:44:07 by sruff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// # include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf_bonus.h"
# include "push_swap.h"
// # include "get_next_line.h"

int	reading_loop(t_ps_node **a, t_ps_node **b, char **split_arg, int argc);

#endif