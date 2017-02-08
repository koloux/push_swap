/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:01:12 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/08 15:01:21 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solve_order(t_stk *stack)
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

int		order_reverse(t_stk *stack)
{
	int	i;

	i = stack->stk->top;
	while (i > 0)
	{
		if (stack->stk->nb[i] < stack->stk->nb[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	solve_order_reverse(t_stk *stk_a, t_stk *stk_b)
{
	if (order_reverse(stk_a) == 1 && solve_order(stk_a) != 1)
	{
		if (stk_a->stk->top == 1)
		{
			stk_a->swap(stk_a);
			cmd_join(&stk_a->op, "sa\n");
		}
		else
		{
			while (stk_a->stk->top > 2)
			{
				stk_a->rev(stk_a);
				cmd_join(&stk_a->op, "rra\n");
				stk_a->push(stk_a, stk_b, 1);
			}
			stk_a->swap(stk_a);
			stk_a->rev(stk_a);
			cmd_join(&stk_a->op, "sa\nrra\n");
			while (stk_b->stk->top != -1)
				stk_a->push(stk_b, stk_a, 0);
		}
	}
}
