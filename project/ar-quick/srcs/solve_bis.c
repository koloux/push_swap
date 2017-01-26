/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:50:45 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/26 16:52:13 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_bis_l(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;

	i = 0;
	med = get_median(stk_a);
	while (i < nb && solve_order(stk_a) != 1)
	{
		if (stk_a->stk->nb[stk_a->stk->top] >= med)
		{
			stk_a->rot(stk_a);
			solve_secondary(stk_a, stk_b, 3);
		}
		if (stk_a->stk->nb[stk_a->stk->top] < med)
		{
			stk_a->push(stk_a, stk_b, 0);
			cmd_join(&stk_a->op, "pb\n");
		}
		i++;
	}
}

void	solve_bis_r(t_stk *stk_a, t_stk *stk_b)
{
	if (stk_a->stk->nb[stk_a->stk->top] >
			stk_a->stk->nb[stk_a->stk->top - 1])
	{
		stk_a->swap(stk_a);
		solve_secondary(stk_a, stk_b, 2);
	}
	while (stk_b->stk->nb[stk_b->stk->top] >
			stk_a->stk->nb[stk_a->stk->top])
	{
		stk_a->rot(stk_a);
		solve_secondary(stk_a, stk_b, 3);
	}
	stk_a->push(stk_b, stk_a, 1);
	cmd_join(&stk_a->op, "pb\n");
	while (stk_a->stk->nb[0] < stk_a->stk->nb[stk_a->stk->top])
	{
		stk_a->rev(stk_a);
		solve_secondary(stk_a, stk_b, 1);
	}
}

void	solve_bis_r_med(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	i;
	int	med;

	i = 0;
	med = get_median(stk_b);
	while (i < nb)
	{
		if (stk_b->stk->nb[stk_b->stk->top] <= med)
		{
			stk_b->rot(stk_b);
			cmd_add(stk_a, 3);
		}
		if (stk_b->stk->nb[stk_b->stk->top] > med)
			solve_bis_r(stk_a, stk_b);
		i++;
	}
}
