/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:14:29 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/20 19:04:05 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	solve_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int med;
	int i;

	i = 0;
	//add swap
	if (nb <= 2)
		return (1);
	med = get_median(stk_a);
	while (i < nb) 
	{
		if (stk_a->stk->nb[stk_a->stk->top] <= med)
		{
			stk_a->rot(stk_a);
			cmd_add(stk_a, 3);
		}
		if (stk_a->stk->nb[stk_a->stk->top] > med)
			stk_a->push(stk_a, stk_b, 0);
		i++;
	}
	solve_left(stk_a, stk_b, (nb / 2 + nb % 2));
	solve_right(stk_a, stk_b, nb / 2);
	return (0);
}

int	solve_right(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int med;
	int i;

	i = 0;
	if (nb <= 2)
		return (1);
	med = get_median(stk_b);
	while (i < nb) 
	{
		if (stk_b->stk->nb[stk_b->stk->top] >= med)
		{
			stk_b->rot(stk_b);
			cmd_join(&stk_a->op, "rb\n");
		}
		if (stk_b->stk->nb[stk_b->stk->top] < med)
			stk_b->push(stk_b, stk_a, 1);
		i++;
	}
	solve_left(stk_a, stk_b, (nb / 2 + nb % 2));
	solve_right(stk_a, stk_b, nb / 2);
	return (0);
}

void	solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	solve_order_reverse(stk_a, stk_b);
	solve_left(stk_a, stk_b, stk_a->stk->top + 1);
	info(stk_a, stk_b, 100);
	/*
	if (order_reverse(stk_b) == 1)
	{
		while (stk_b->stk->top > -1)
			stk_b->push(stk_b, stk_a, 0);
	}
	else
	{
		274
	}
	*/
}
