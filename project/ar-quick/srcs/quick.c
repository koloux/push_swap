/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:24:43 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/06 19:16:13 by nhuber           ###   ########.fr       */
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
		bubble_left(stk_a, stk_b);
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
	while (i <= nb && check_median(stk_a, med) != 0)
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
	while (c > 0 && get_max(stk_a) != STK_A->nb[0])
	{
		stk_a->rev(stk_a);
		solve_right(stk_a, stk_b, 1);
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
		bubble_right(stk_a, stk_b);
		if (STK_B->nb[TOP_B] < STK_B->nb[TOP_B - 1])
		{
			stk_b->swap(stk_b);
			solve_left(stk_a, stk_b, 2);
		}
		else
			stk_a->push(stk_b, stk_a, 0);
		return (1);
	}
	med = get_median(stk_b);
	i = 0;
	while (i <= nb && TOP_B > 0 && order_reverse(stk_b) != 1)
	{
		if (STK_B->nb[TOP_B] < med)
		{
			stk_b->rot(stk_b);
			solve_left(stk_a, stk_b, 3);
		}	
		if (STK_B->nb[TOP_B] >= med)
			stk_a->push(stk_b, stk_a, 0);
		i++;
	}
	quick_right(stk_a, stk_b, nb / 2);
	quick_left(stk_a, stk_b, (nb / 2 + nb % 2));
	return (0);
}
