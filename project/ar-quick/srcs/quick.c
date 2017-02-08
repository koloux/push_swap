/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:24:43 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/08 12:35:28 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int		quick_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;
	int c;

	if (nb <= 2)
	{
		if (STK_A->nb[TOP_A] > STK_A->nb[TOP_A - 1])
		{
			stk_a->swap(stk_a);
			solve_right(stk_a, stk_b, 2);
		}
		return (1);
	}
	med = check_med(stk_a, nb);
	i = 0;
	c = 0; 
	while (i <= nb && check_median(stk_a, med, nb, 0) != 0)
	{
		if (STK_A->nb[TOP_A] >= med)
		{
			stk_a->rot(stk_a);
			solve_right(stk_a, stk_b, 3);
			c++;
		}
		else
			stk_a->push(stk_a, stk_b, 1);
		i++;
	}
	if ((nb / 2 + nb % 2) != TOP_A + 1)
	{
		while (c > 0)
		{
			stk_a->rev(stk_a);
			solve_right(stk_a, stk_b, 1);
			c--;
		}
	}
	quick_left(stk_a, stk_b, nb / 2 + nb % 2);
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}

int		quick_right(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;
	int	c;
	
	if (nb <= 2)
	{
		if (nb == 2 && STK_B->nb[TOP_B] < STK_B->nb[TOP_B - 1])
		{
			stk_b->swap(stk_b);
			solve_left(stk_a, stk_b, 2);
		}
		while (nb--)
			stk_a->push(stk_b, stk_a, 0);
		return (1);
	}
	med = check_med(stk_b, nb);
	i = 0;
	c = 0; 
	while (i <= nb && check_median(stk_b, med, nb, 1) != 0)
	{
		if (STK_B->nb[TOP_B] < med)
		{
			stk_b->rot(stk_b);
			solve_left(stk_a, stk_b, 3);
			c++;
		}	
		if (STK_B->nb[TOP_B] >= med)
			stk_a->push(stk_b, stk_a, 0);
		i++;
	}
	if (nb / 2 != TOP_B + 1)
	{
		while (c > 0)
		{
			stk_b->rev(stk_b);
			solve_left(stk_a, stk_b, 1);
			c--;
		}
	}
	quick_left(stk_a, stk_b, (nb / 2 + nb % 2));
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}
