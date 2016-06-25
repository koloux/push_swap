/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 17:05:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/25 10:00:41 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stk *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stk->nb[stack->stk->top];
	while (i < stack->stk->top)
	{
		if (min > stack->stk->nb[i])
			min = stack->stk->nb[i];
		i++;
	}
	return (min);
}

int	get_max(t_stk *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stk->nb[stack->stk->top];
	while (i < stack->stk->top)
	{
		if (max < stack->stk->nb[i])
			max = stack->stk->nb[i];
		i++;
	}
	return (max);
}
