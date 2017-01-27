/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:28:36 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/27 17:28:05 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	solve_right(t_stk *stk_a, t_stk *stk_b, int cmd)
{
	if (cmd == 1 && (STK_B->nb[0] >	STK_B->nb[TOP_B]))
	{
		stk_b->rev(stk_b);
		cmd += 3;
	}
	if (cmd == 2 &&	(STK_B->nb[TOP_B - 1] > STK_B->nb[TOP_B]))
	{
		stk_b->swap(stk_b);
		cmd += 3;
	}
	/*
	if (cmd == 3 && STK_B->nb[TOP_B - 1] > STK_B->nb[TOP_B])
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	*/
	cmd_add_right(stk_a, cmd);
}

void	solve_left(t_stk *stk_a, t_stk *stk_b, int cmd)
{
	if (cmd == 1 && (STK_A->nb[0] < STK_A->nb[TOP_A]))
	{
		stk_b->rev(stk_a);
		cmd += 3;
	}
	if (cmd == 2 &&	(STK_A->nb[TOP_A - 1] < STK_A->nb[TOP_A]))
	{
		stk_b->swap(stk_a);
		cmd += 3;
	}
	if (cmd == 3 && STK_A->nb[TOP_A - 1] < STK_A->nb[TOP_A])
	{
		stk_b->rot(stk_a);
		cmd += 3;
	}
	cmd_add_left(stk_a, cmd);
}

void	solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	quick_left(stk_a, stk_b, TOP_A + 1);
}
