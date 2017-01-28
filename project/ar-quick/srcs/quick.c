/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:24:43 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/28 20:10:37 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int		quick_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;

	//printf("QUICK-LEFT-|%d|-|%d|\n", get_median(stk_a), nb);
	//info(stk_a, stk_b, TOP_A + 1);
	if (nb <= 7)
	{
		cmd_join(&stk_a->op, "here");
		bubble_left(stk_a, stk_b);
		return (1);
	}
	med = get_median(stk_a);
	i = 0;
	while (i <= nb)
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

	//printf("QUICK-RIGHT-|%d|-|%d|\n", get_median(stk_b), nb);
	//info(stk_a, stk_b, TOP_B + 1);
	if (nb <= 2)
	{
		if (STK_B->nb[TOP_B] < STK_B->nb[TOP_B - 1])
		{
			stk_b->swap(stk_b);
			solve_left(stk_a, stk_b, 2);
		}
		//bubble_right(stk_a, stk_b);
		return (1);
	}
	med = get_median(stk_b);
	i = 0;
	while (i <= nb)
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
	quick_left(stk_a, stk_b, (nb / 2 + nb % 2));
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}
