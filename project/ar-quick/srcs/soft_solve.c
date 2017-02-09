/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:29:51 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/09 17:22:48 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_secondary(t_stk *stk_a, t_stk *stk_b, int cmd)
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
	if (cmd == 3 && (stk_b->stk->nb[0] < stk_b->stk->nb[stk_b->stk->top]
			|| (stk_b->stk->nb[stk_b->stk->top - 1] >
			stk_b->stk->nb[stk_b->stk->top]
			&& stk_b->stk->nb[0] < stk_b->stk->nb[stk_b->stk->top - 1])))
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	cmd_add_right(stk_a, cmd);
}

static void	solve_soft(t_stk *stk_a, t_stk *stk_b)
{
	int	min;

	min = get_min(stk_a);
	while (solve_order(stk_a) != 1
			&& (min == stk_a->stk->nb[0] ||
				min == stk_a->stk->nb[stk_a->stk->top] ||
				min == stk_a->stk->nb[stk_a->stk->top - 1]))
	{
		if (min == stk_a->stk->nb[stk_a->stk->top])
			stk_a->push(stk_a, stk_b, 1);
		if (min == stk_a->stk->nb[0])
		{
			stk_a->rev(stk_a);
			solve_secondary(stk_a, stk_b, 1);
		}
		if (min == stk_a->stk->nb[stk_a->stk->top - 1])
		{
			stk_a->swap(stk_a);
			solve_secondary(stk_a, stk_b, 2);
		}
		min = get_min(stk_a);
	}
}

static void	solve_end(t_stk *stk_a, t_stk *stk_b)
{
	if (solve_order(stk_b))
	{
		while (stk_b->stk->top != -1)
			stk_a->push(stk_b, stk_a, 0);
	}
	else
	{
		while (stk_b->stk->top != -1)
		{
			if (get_max(stk_b) == stk_b->stk->nb[stk_b->stk->top])
				stk_a->push(stk_b, stk_a, 0);
			else if (get_max(stk_b) == stk_b->stk->nb[stk_b->stk->top - 1])
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
}

static void	solve_pivot(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->stk->nb[stk_a->stk->top] > stk_a->stk->nb[stk_a->stk->top / 2])
	{
		if (stk_a->stk->nb[0] < stk_a->stk->nb[stk_a->stk->top / 2])
		{
			stk_a->rev(stk_a);
			solve_secondary(stk_a, stk_b, 1);
		}
		else if (stk_a->stk->nb[stk_a->stk->top - 1] <
				stk_a->stk->nb[stk_a->stk->top / 2])
		{
			stk_a->swap(stk_a);
			solve_secondary(stk_a, stk_b, 2);
		}
		else
		{
			stk_a->rot(stk_a);
			solve_secondary(stk_a, stk_b, 3);
		}
	}
	else
		(solve_order(stk_a) == 1) ? solve_order(stk_b) :
		stk_a->push(stk_a, stk_b, 1);
}

void		solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	solve_order_reverse(stk_a, stk_b);
	while (solve_order(stk_a) != 1)
	{
		solve_soft(stk_a, stk_b);
		solve_pivot(stk_a, stk_b);
	}
	solve_end(stk_a, stk_b);
}
