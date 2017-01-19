/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:55:56 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/19 12:46:21 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	cmd_add(stk_a, cmd);
}

static void	solve_pivot(t_stk *stk_a, t_stk *stk_b)
{
	int med;

	med = get_median(stk_a);
	while (solve_order(stk_a) != 1)
	{
		//info(stk_a, stk_b, 8);
		if (stk_a->stk->nb[stk_a->stk->top - 1] <
			 stk_a->stk->nb[stk_a->stk->top])
		{
			stk_a->swap(stk_a);
			((stk_b->stk->top > 0) ? solve_secondary(stk_a, stk_b, 2) :
			 cmd_add(stk_a, 2));
			//info(stk_a, stk_b, 8);
		}
		else if (stk_a->stk->nb[0] <
			 stk_a->stk->nb[stk_a->stk->top])
		{
			stk_a->rev(stk_a);
			((stk_b->stk->top > 0) ? solve_secondary(stk_a, stk_b, 1) :
			 cmd_add(stk_a, 1));
		}
		else if (med == stk_a->stk->nb[stk_a->stk->top]
				|| med > stk_a->stk->nb[stk_a->stk->top])
			stk_a->push(stk_a, stk_b, 1);
		else
		{
			stk_a->rot(stk_a);
			((stk_b->stk->top > 0) ? solve_secondary(stk_a, stk_b, 3) :
			 cmd_add(stk_a, 3));
		}
		med = get_median(stk_a);
	}
	if (order_reverse(stk_b) == 1)
	{
		while (stk_b->stk->top > -1)
			stk_b->push(stk_b, stk_a, 0);
	}
}

void	solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	solve_order_reverse(stk_a, stk_b);
	solve_pivot(stk_a, stk_b);	
	//info(stk_a, stk_b, 8);
}
