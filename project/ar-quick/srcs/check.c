/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:28:50 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/08 12:30:45 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_median(t_stk *stack, int med, int nb, int sens)
{
	int	i;

	i = stack->stk->top - nb - 1;
	while (i < stack->stk->top + 1)
	{
		if (stack->stk->nb[i] < med && sens == 0)
			return (1);
		if (stack->stk->nb[i] >= med && sens == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_med(t_stk *stk_a, int nbelem)
{
	int	i;
	int	j;
	int	nb;
	int	med;

	j = TOP_A - nbelem + 1;
	while (j < TOP_A + 1)
	{
		med = 0;
		i = TOP_A - nbelem + 1;
		nb = STK_A->nb[j];
		while (i < TOP_A + 1)
		{
			if (nb != STK_A->nb[i])
				(STK_A->nb[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (nbelem % 2 == 0 ? -1 : 0))
			return (STK_A->nb[j]);
		j++;
	}
	return (0);
}
