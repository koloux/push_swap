/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:14:29 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/22 15:25:06 by nhuber           ###   ########.fr       */
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
	if (cmd == 3 && (stk_b->stk->nb[0] > stk_b->stk->nb[stk_b->stk->top]))
	{
		stk_b->rot(stk_b);
		cmd += 3;
	}
	cmd_add(stk_a, cmd);
}
int	solve_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int med;
	int i;

	//info(stk_a, stk_b, stk_a->stk->top + 1);
	if (nb <= 2)
	{
		if (solve_order(stk_a) == 0)
		{
			stk_a->swap(stk_a);
			cmd_add(stk_a, 2);
		}
		//printf("LEFT = |MED=%d|NB=%d|TOP=%d|\n", get_median(stk_a), nb, stk_a->stk->top);
		return (1);
	}
	i = 0;
	med = get_median(stk_a);
	//printf("LEFT = |MED=%d|NB=%d|TOP=%d|\n", med, nb, stk_a->stk->top);
	while (i < nb && solve_order(stk_a) != 1) 
	{
		if (stk_a->stk->nb[stk_a->stk->top] >= med)
		{
			stk_a->rot(stk_a);
			solve_secondary(stk_a, stk_b, 3);
		}
		if (stk_a->stk->nb[stk_a->stk->top] < med)
		{
			//printf("PUSH B: %d\n", stk_a->stk->nb[stk_a->stk->top]);
			stk_a->push(stk_a, stk_b, 0);
			cmd_join(&stk_a->op, "pb\n");
		}
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

	if (nb <= 2)
	{
		if (order_reverse(stk_b) == 1)
		{
			stk_b->swap(stk_b);
			cmd_join(&stk_a->op, "sb\n");
		}
		//printf("RIGHT = |MED=%d|NB=%d|TOP=%d|\n", get_median(stk_b), nb, stk_b->stk->top);
		//info(stk_a, stk_b, stk_b->stk->top + 1);
		return (1);
	}
	i = 0;
	med = get_median(stk_b);
	//printf("RIGHT = |MED=%d|NB=%d|TOP=%d|\n", med, nb, stk_b->stk->top);
	while (i < nb) 
	{
		if (stk_b->stk->nb[stk_b->stk->top] <= med)
		{
			stk_b->rot(stk_b);
			cmd_add(stk_a, 3);
		}
		if (stk_b->stk->nb[stk_b->stk->top] > med)
		{
			//printf("PUSH A: %d\n", stk_b->stk->nb[stk_b->stk->top]);
			if (stk_a->stk->nb[stk_a->stk->top] > stk_a->stk->nb[stk_a->stk->top - 1]) 
			{
				stk_a->swap(stk_a);
				solve_secondary(stk_a, stk_b, 2);
			}
			while (stk_b->stk->nb[stk_b->stk->top] > stk_a->stk->nb[stk_a->stk->top]) 
			{
				stk_a->rot(stk_a);
				solve_secondary(stk_a, stk_b, 3);
			}
			stk_b->push(stk_b, stk_a, 1);
			cmd_join(&stk_a->op, "pb\n");
			while (stk_a->stk->nb[0] < stk_a->stk->nb[stk_a->stk->top])
			{
				stk_a->rev(stk_a);
				solve_secondary(stk_a, stk_b, 1);
			}
		}
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
	while (stk_b->stk->top != -1)
	{
		stk_b->push(stk_b, stk_a, 1);
		if (solve_order(stk_a) != 1)
		{
			stk_a->swap(stk_a);
			solve_secondary(stk_a, stk_b, 2);
		}
	}
	//info(stk_a, stk_b, 100);
}
