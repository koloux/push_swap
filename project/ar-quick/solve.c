/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:29:51 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/07 20:15:23 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_order(t_stk *stack)
{
	int	i;

	if (stack->stk->nb[stack->stk->top] > stack->stk->nb[stack->stk->top - 1])
	{
		i = stack->stk->top - 1;
		while (i > 0)
		{
			if (stack->stk->nb[i] < stack->stk->nb[i - 1])
				return (0);
			i--;
		}
	}
	return (1);
}

static int	solve_get_pivot(t_stk *stack)
{
	int	i;
	int	min;
	int	pivot;

	i = 0;
	min = stack->stk->nb[stack->stk->top];
	while (i < stack->stk->top)
	{
		if (min > stack->stk->nb[i])	
		{
			pivot = 
		}
		i++;
	}
}

void		solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	

}
