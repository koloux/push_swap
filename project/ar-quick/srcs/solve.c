/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:28:36 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/26 19:11:33 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	solve_right(t_stk *stk_a, t_stk *stk_b, int cmd)
{
	if (cmd == 1 && (STK_B->nb[0] >
				STK_B->nb[TOP_B]))
	{
		stk_b->rev(stk_b);
		cmd += 3;
	}
	if (cmd == 2 &&	(STK_B->nb[TOP_B - 1] > STK_B->nb[TOP_B]))
	{
		stk_b->swap(stk_b);
		cmd += 3;
	}
	if (cmd == 3 && (STK_B->nb[TOP_B - 1] > STK_B->nb[TOP_B]))
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	cmd_add(stk_a, cmd);
}

int		quick_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;

	if (nb <= 2)
	{
		if (solve_order(stk_a) != 1)
		{
			stk_a->swap(stk_a);
			cmd_add(stk_a, 2);
		}
		info(stk_a, stk_b, TOP_A + 1);
		return (1);
	}
	med = get_median(stk_a);
	i = 0;
	while (i < nb)
	{
		if (STK_A->nb[TOP_A] >= med)
		{
			stk_a->rot(stk_a);
			solve_right(stk_a, stk_b, 3);
		}
		if (STK_A->nb[TOP_A] < med)
			stk_a->push(stk_a, stk_b, 1);
		i++;
	}	
	quick_left(stk_a, stk_b, nb / 2 + nb % 2);
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}

int		quick_right(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;

	if (nb <= 2)
	{
		if (order_reverse(stk_b) != 1)
		{
			stk_b->swap(stk_b);
			cmd_join(&stk_a->op, "sb\n");
		}
		return (1);
	}
	med = get_median(stk_a);
	i = 0;
	while (i < nb)
	{
		if (STK_A->nb[TOP_A] > med)
		{
			stk_b->rot(stk_b);
			cmd_join(&stk_a->op, "rb\n");
		}
		if (STK_A->nb[TOP_A] <= med)
			stk_a->push(stk_b, stk_a, 0);
		i++;
	}
	quick_left(stk_a, stk_b, nb / 2 + nb % 2);
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}


void	solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	quick_left(stk_a, stk_b, TOP_A + 1);
}
