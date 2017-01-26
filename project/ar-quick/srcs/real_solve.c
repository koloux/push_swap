/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:14:29 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/26 15:18:44 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		solve_secondary(t_stk *stk_a, t_stk *stk_b, int cmd)
{
	if (cmd == 1 && (stk_b->stk->nb[0] >
				stk_b->stk->nb[stk_b->stk->top]))
	{
		stk_b->rev(stk_b);
		cmd += 3;
	}
	if (cmd == 2 &&
		(stk_b->stk->nb[stk_b->stk->top - 1] >
		stk_b->stk->nb[stk_b->stk->top]))
	{
		stk_b->swap(stk_b);
		cmd += 3;
	}
	if (cmd == 3 && (stk_b->stk->nb[0] > stk_b->stk->nb[stk_b->stk->top]))
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	cmd_add(stk_a, cmd);
}

int			solve_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	if (nb <= 2)
	{
		if (solve_order(stk_a) == 0)
		{
			stk_a->swap(stk_a);
			cmd_add(stk_a, 2);
		}
		return (1);
	}
	solve_bis_l(stk_a, stk_b, nb);
	solve_left(stk_a, stk_b, (nb / 2 + nb % 2));
	solve_right(stk_a, stk_b, nb / 2);
	return (0);
}

int			solve_right(t_stk *stk_a, t_stk *stk_b, int nb)
{
	if (nb <= 2)
	{
		if (order_reverse(stk_b) == 1)
		{
			stk_b->swap(stk_b);
			cmd_join(&stk_a->op, "sb\n");
		}
		return (1);
	}
	solve_bis_r_med(stk_a, stk_b, nb);
	solve_left(stk_a, stk_b, (nb / 2 + nb % 2));
	solve_right(stk_a, stk_b, nb / 2);
	return (0);
}

void		solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	solve_order_reverse(stk_a, stk_b);
	solve_left(stk_a, stk_b, stk_a->stk->top + 1);
	while (stk_b->stk->top != -1)
	{
		stk_b->push(stk_b, stk_a, 1);
		if (solve_order(stk_a) != 1)
		{
			stk_a->swap(stk_a);
			solve_secondary(stk_a, stk_b, 2);
		}
	}
}
