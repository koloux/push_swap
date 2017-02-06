/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:43:58 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/06 18:48:04 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	bubble_softsort(t_stk *stk_a)
{
	int	max_i;

	max_i = 0;
	while (get_max(stk_a) != STK_A->nb[max_i])
		max_i++;
	while (max_i < TOP_A)
	{
		if (STK_A->nb[max_i] < STK_A->nb[max_i + 1])
			return (0);
		max_i++;
	}
	return (1);
}

void		bubble_left(t_stk *stk_a, t_stk *stk_b)
{
	while (solve_order(stk_a) != 1)
	{
		if (bubble_softsort(stk_a) == 1)
		{
			//implementer : rotate | reverse
			while (get_max(stk_a) != STK_A->nb[0])
			{
				stk_a->rev(stk_a);
				solve_right(stk_a, stk_b, 1);
			}
		}
		if (STK_A->nb[TOP_A] < STK_A->nb[TOP_A - 1] && solve_order(stk_a) != 1)
		{
			stk_a->rot(stk_a);
			solve_right(stk_a, stk_b, 3);
		}
		else
		{
			stk_a->swap(stk_a);
			solve_right(stk_a, stk_b, 2);
		}
	}
}

static int	bubble_softrev(t_stk *stk_b, int n)
{

	while (n > 0)
	{
		if (STK_B->nb[TOP_B - n] > STK_B->nb[TOP_B - n + 1])
			return (0);
		n--;
	}
	return (1);
}

void		bubble_right(t_stk *stk_a, t_stk *stk_b)
{
	int	i;
	int	top;

	top = (TOP_B > 6 ? 6 : TOP_B);
	i = 0;
	while (TOP_B > 2 && bubble_softrev(stk_b, top) != 1)
	{
		while (i != 0)
		{
			stk_b->rev(stk_b);
			solve_left(stk_a, stk_b, 1);
			i--;
		}
		while (i < top && bubble_softrev(stk_b, top - i) != 1)
		{
			if (STK_B->nb[TOP_B - 1] > STK_B->nb[TOP_B])
			{
				stk_b->swap(stk_b);
				solve_left(stk_a, stk_b, 2);
			}
			if (bubble_softrev(stk_b, top - i) != 1)
			{
				stk_b->rot(stk_b);
				solve_left(stk_a, stk_b, 3);
				i++;
			}
		}
	}
}
