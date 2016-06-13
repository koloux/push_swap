/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:29:51 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/13 18:12:07 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_order(t_stk *stack)
{
	int	i;

	i = stack->stk->top;
	while (i > 0)
	{
		if (stack->stk->nb[i] > stack->stk->nb[i - 1])
			return (0);
		i--;
	}
	return (1);
}

static void	solve_secondary(t_stk *stk_a, t_stk *stk_b, int cmd)
{
	(void)stk_a;
	if (cmd == 1 && (stk_b->stk->nb[0] >
				stk_b->stk->nb[stk_b->stk->top]))
		stk_b->rev(stk_b);
	if (cmd == 2 &&
			(stk_b->stk->nb[stk_b->stk->top - 1] >
			stk_b->stk->nb[stk_b->stk->top]))
		stk_b->swap(stk_b);
	if (cmd == 3 && (stk_b->stk->nb[0] < stk_b->stk->nb[stk_b->stk->top]
			|| (stk_b->stk->nb[stk_b->stk->top - 1] >
			stk_b->stk->nb[stk_b->stk->top]
			&& stk_b->stk->nb[0] < stk_b->stk->nb[stk_b->stk->top - 1])))
		stk_b->rot(stk_b);
}

static void	solve_soft(t_stk *stk_a, t_stk *stk_b)
{
	int	min;
	int	cmd;

	min = get_min(stk_a);
	while (solve_order(stk_a) != 1
			&& (min == stk_a->stk->nb[0] ||
				min == stk_a->stk->nb[stk_a->stk->top] ||
				min == stk_a->stk->nb[stk_a->stk->top - 1]))
	{
		cmd = 0;
		if (min == stk_a->stk->nb[stk_a->stk->top])
			stk_a->push(stk_a, stk_b);
		if (min == stk_a->stk->nb[0])
		{
			cmd = 1;
			stk_a->rev(stk_a);
		}
		if (min == stk_a->stk->nb[stk_a->stk->top - 1])
		{
			cmd = 2;
			stk_a->swap(stk_a);
		}
		solve_secondary(stk_a, stk_b, cmd);
		min = get_min(stk_a);
	}
}

static void	solve_end(t_stk *stk_a, t_stk *stk_b)
{
	int	max;

	if (solve_order(stk_b))
	{
		while (stk_b->stk->top != -1)
			stk_a->push(stk_b, stk_a);
	}
	else
	{
		while (stk_b->stk->top != -1)
		{
			max = get_max(stk_b);
			if (max == stk_b->stk->nb[stk_b->stk->top])
				stk_a->push(stk_b, stk_a);
			else if (max == stk_b->stk->nb[stk_b->stk->top - 1])
				stk_b->swap(stk_b);
			else
				stk_b->rot(stk_b);
		}
	}
}

void		solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	int	cmd;
	int	pivot;

	while (solve_order(stk_a) != 1)
	{
		cmd = 0;
		info(stk_a, stk_b, 8);
		solve_soft(stk_a, stk_b);
		pivot = stk_a->stk->nb[stk_a->stk->top / 2];
		if (stk_a->stk->nb[stk_a->stk->top] > pivot)
		{
			if (stk_a->stk->nb[0] < pivot)
			{
				cmd = 1;
				stk_a->rev(stk_a);
			}
			if (stk_a->stk->nb[stk_a->stk->top - 1] < pivot)
			{
				cmd = 2;
				stk_a->swap(stk_a);
			}
			else
			{
				cmd = 3;
				stk_a->rot(stk_a);
			}
		}
		else
			stk_a->push(stk_a, stk_b);
		solve_secondary(stk_a, stk_b, cmd);
	}
	solve_end(stk_a, stk_b);
}
