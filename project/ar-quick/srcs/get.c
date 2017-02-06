/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 17:05:55 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/06 19:10:47 by nhuber           ###   ########.fr       */
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

int	get_median(t_stk *stack)
{
	int i;
	int	j;
	int	nb;
	int	med;

	j = 0;
	while (j < stack->stk->top + 1)
	{
		med = 0;
		i = 0;
		nb = stack->stk->nb[j];
		while (i < stack->stk->top + 1)
		{
			if (nb != stack->stk->nb[i])
				(stack->stk->nb[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (stack->stk->top % 2 == 0 ? 0 : -1))
			return (stack->stk->nb[j]);
		j++;
	}
	return (0);
}

int	get_small(int i, int j, int k)
{
	if (i < j && i < k)
		return (1);
	if (j < i && j < k)
		return (2);
	return (3);
}

int	get_high(int i, int j, int k)
{
	if (i > j && i > k)
		return (1);
	if (j > i && j > k)
		return (2);
	return (3);
}
