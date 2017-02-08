/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:29:51 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/08 15:04:10 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	soft_secondary(t_stk *stk_a, t_stk *stk_b, int cmd)
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
	if (cmd == 3 && (stk_b->stk->nb[0] > stk_b->stk->nb[stk_b->stk->top]
		|| (stk_b->stk->nb[stk_b->stk->top - 1] >
		stk_b->stk->nb[stk_b->stk->top]
		&& stk_b->stk->nb[0] < stk_b->stk->nb[stk_b->stk->top - 1])))
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	cmd_add_right(stk_a, cmd);
}

static void	soft_pivot_bis(t_stk *stk_a, t_stk *stk_b, int med)
{
	if (stk_a->stk->nb[0] < med)
	{
		stk_a->rev(stk_a);
		soft_secondary(stk_a, stk_b, 1);
	}
	else if (stk_a->stk->nb[stk_a->stk->top] <
			stk_a->stk->nb[stk_a->stk->top - 1])
	{
		stk_a->swap(stk_a);
		soft_secondary(stk_a, stk_b, 2);
	}
	else
	{
		stk_a->rot(stk_a);
		soft_secondary(stk_a, stk_b, 3);
	}
}

static void	soft_pivot(t_stk *stk_a, t_stk *stk_b)
{
	int	med;

	med = get_median(stk_a);
	while (solve_order(stk_a) != 1 && stk_a->stk->top > 1)
	{
		if (stk_a->stk->nb[stk_a->stk->top] < med)
			stk_a->push(stk_a, stk_b, 1);
		else if (stk_a->stk->nb[stk_a->stk->top] > med)
			soft_pivot_bis(stk_a, stk_b, med);
		else
		{
			stk_a->push(stk_a, stk_b, 1);
			med = get_median(stk_a);
		}
	}
}

static void	soft_end(t_stk *stk_a, t_stk *stk_b)
{
	int	max;

	if (solve_order(stk_a) != 1)
	{
		stk_a->swap(stk_a);
		soft_secondary(stk_a, stk_b, 2);
	}
	while (order_reverse(stk_b) != 1)
	{
		max = get_max(stk_b);
		if (stk_b->stk->nb[stk_b->stk->top] == max)
			stk_b->push(stk_b, stk_a, 0);
		else if (stk_b->stk->nb[stk_b->stk->top] <
				stk_b->stk->nb[stk_b->stk->top - 1])
		{
			stk_b->swap(stk_b);
			cmd_join(&stk_a->op, "sb\n");
		}
		else
		{
			stk_b->rot(stk_b);
			cmd_join(&stk_a->op, "rb\n");
		}
	}
}

void		soft_solve(t_stk *stk_a, t_stk *stk_b)
{
	solve_order_reverse(stk_a, stk_b);
	soft_pivot(stk_a, stk_b);
	soft_end(stk_a, stk_b);
	while (TOP_B != -1)
		stk_b->push(stk_b, stk_a, 0);
}
