/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:28:36 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/08 12:31:16 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_right(t_stk *stk_a, t_stk *stk_b, int cmd)
{	
	(void)stk_a;
	(void)stk_b;
	/*
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
	if (cmd == 3 && (get_median(stk_b) > STK_B->nb[TOP_B]))
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	*/
	cmd_add_right(stk_a, cmd);
}

void	solve_left(t_stk *stk_a, t_stk *stk_b, int cmd)
{
	(void)stk_a;
	(void)stk_b;
	/*
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
	*/
	cmd_add_left(stk_a, cmd);
}

void	solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	quick_left(stk_a, stk_b, TOP_A + 1);
	//info(stk_a, stk_b, 100);
}
